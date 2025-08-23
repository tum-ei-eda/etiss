#!/bin/bash

set -euo pipefail

SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

RISCV_GDB=${RISCV_GDB:-riscv-none-elf-gdb}
ETISS=${ETISS:-bare_etiss_processor}

INI=${1:-./examples_prebuilt_rv32/ini/hello_world.ini}
ELF=${2:-./examples_prebuilt_rv32/bin/hello_world}
PORT=${3:-2001}
JIT=${4:-TCC}

$ETISS -i$INI --jit.type=${JIT}JIT -pgdbserver --plugin.gdbserver.port=$PORT &
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

# echo "Ready"

# Avoid non-xero exit code of GDB if etiss disconnects after simulation
($RISCV_GDB -q -nx -batch -x $SCRIPT_DIR/gdbserver_test.cmd "$ELF" -ex "continue" || true) 2>&1 | tee gdb_output.log

# read -n 1

# echo "Done"

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

echo "✅ test passed"