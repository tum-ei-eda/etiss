#!/bin/bash

set -euo pipefail

export SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

export RISCV_GDB=${RISCV_GDB:-riscv-none-elf-gdb}
export ETISS=${ETISS:-bare_etiss_processor}

export INI=${1:-./examples_prebuilt_rv32/ini/hello_world.ini}
export ELF=${2:-./examples_prebuilt_rv32/bin/hello_world}
export PORT=${3:-2001}
export JIT=${4:-TCC}
TIMEOUT_SEC=${5:-180}
echo qqq
$ETISS -i$INI --jit.type=${JIT}JIT -pgdbserver --plugin.gdbserver.port=$PORT 2>&1 > etiss_output.log &
# tee_pid=$!
# echo www
# sleep 0.1  # give the processes a moment to start
# ETISS_PID=$(pgrep -P $tee_pid)
# echo "PID of tee: $tee_pid"
ETISS_PID=$!
echo ETISS_PID=$ETISS_PID


# Ensure ETISS is killed on failure
cleanup() {
    echo "Cleaning up..."
    kill $ETISS_PID 2>/dev/null || true
}
trap cleanup EXIT

# Wait until gdbserver socket is ready
for i in {1..10}; do
    if nc -z localhost $PORT; then break; fi
    sleep 0.2
done

sleep 1

# echo "Ready"

run_gdb_session() {
    # Avoid non-zero exit code of GDB if etiss disconnects after simulation
    $RISCV_GDB -q -nx -batch -x $SCRIPT_DIR/gdbserver_test.cmd "$ELF" -ex "continue" || true
}
export -f run_gdb_session

timeout $TIMEOUT_SEC bash -c run_gdb_session 2>&1 | tee gdb_output.log
TIMEOUT_EXIT=$?


if [[ $TIMEOUT_EXIT -eq 124 ]]
then
    echo "GDB Session timed out!"
    exit 1
elif [[ $TIMEOUT_EXIT -ne 0 ]]
then
    echo "GDB Session crashed!"
    exit 1
fi

echo C

# read -n 1

# echo "Done"

echo "Waiting for etiss to close... (PID=$ETISS_PID)"

wait $ETISS_PID
ETISS_EXIT=$?

echo ETISS_EXIT=$ETISS_EXIT

checks=(
  '^x0[[:space:]]+0x0[[:space:]]+0($|[[:space:]])'
  '^zero[[:space:]]+0x0[[:space:]]+0($|[[:space:]])'
  '^pc[[:space:]]+0x[0-9a-fA-F]+[[:space:]]+0x[0-9a-fA-F]+[[:space:]]+<[^>]+>'
  'Breakpoint 1'
  'Breakpoint 2'
  'Remote connection closed'
)

for re in "${checks[@]}"; do
    if ! grep -qE "$re" gdb_output.log; then
        echo "❌ Check failed for regex: $re"
        exit 1
    else
        echo "check ok: $re"
    fi
done

echo "Cleaning up..."  # TODO: use temp workdir?
rm gdb_output.log

echo "✅ test passed"