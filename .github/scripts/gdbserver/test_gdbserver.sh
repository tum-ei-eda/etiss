#!/bin/bash

set -euo pipefail

export SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

export RISCV_GDB=${RISCV_GDB:-riscv-none-elf-gdb}
echo "RISCV_GDB=$RISCV_GDB"
export ETISS=${ETISS:-bare_etiss_processor}
echo "ETISS=$ETISS"

export INI=${1:-./examples_prebuilt_rv32/ini/hello_world.ini}
echo "INI=$INI"
export ELF=${2:-./examples_prebuilt_rv32/bin/hello_world}
echo "ELF=$ELF"
export PORT=${3:-2001}
echo "PORT=$PORT"
export JIT=${4:-TCC}
echo "JIT=$JIT"
TIMEOUT_SEC=${5:-180}
echo "TIMEOUT_SEC=$TIMEOUT_SEC"

# echo $ETISS -i$INI --jit.type=${JIT}JIT -pgdbserver --plugin.gdbserver.port=$PORT
# $ETISS -i$INI --jit.type=${JIT}JIT -pgdbserver --plugin.gdbserver.port=$PORT 2>&1 > etiss_output.log &
"$ETISS" \
    -i"$INI" \
    --jit.type="${JIT}JIT" \
    -pgdbserver \
    --plugin.gdbserver.port="$PORT" \
    >etiss_output.log 2>&1 &
ETISS_PID=$!
echo ETISS_PID=$ETISS_PID


# Ensure ETISS is killed on failure
cleanup() {
    # echo "Cleaning up..."
    # kill $ETISS_PID 2>/dev/null || true
    rc=$?

    if kill -0 "$ETISS_PID" 2>/dev/null; then
        kill "$ETISS_PID" 2>/dev/null || true
        wait "$ETISS_PID" 2>/dev/null || true
    fi

    if (( rc != 0 )); then
        echo "===== ETISS output ====="
        cat etiss_output.log 2>/dev/null || true
        echo "===== GDB output ====="
        cat gdb_output.log 2>/dev/null || true
    fi

    rm -f etiss_output.log gdb_output.log
    exit "$rc"
}
trap cleanup EXIT

ready=0

for _ in {1..100}; do
    if ss -ltnH "sport = :$PORT" | grep -q .; then
        ready=1
        break
    fi

    if ! kill -0 "$ETISS_PID" 2>/dev/null; then
        echo "ETISS exited before opening GDB port"
        wait "$ETISS_PID" || true
        exit 1
    fi

    sleep 0.1
done

if (( ! ready )); then
    echo "GDB server did not start listening on port $PORT"
    echo "Current listening sockets:"
    ss -ltn
    exit 1
fi

echo "GDB server is listening on port $PORT"
# sleep 3

# echo "Ready"

# run_gdb_session() {
#     # Avoid non-zero exit code of GDB if etiss disconnects after simulation
#     $RISCV_GDB -q -nx -batch -x $SCRIPT_DIR/gdbserver_test.cmd "$ELF" -ex "continue" || true
# }
# export -f run_gdb_session

# timeout $TIMEOUT_SEC bash -c run_gdb_session 2>&1 | tee gdb_output.log
# TIMEOUT_EXIT=$?
#
# if [[ $TIMEOUT_EXIT -eq 124 ]]
# then
#     echo "GDB Session timed out!"
#     exit 1
# elif [[ $TIMEOUT_EXIT -ne 0 ]]
# then
#     echo "GDB Session crashed!"
#     exit 1
# fi

set +e
timeout "$TIMEOUT_SEC" \
    "$RISCV_GDB" -q -nx -batch \
    -x "$SCRIPT_DIR/gdbserver_test.cmd" \
    "$ELF" \
    -ex continue \
    2>&1 | tee gdb_output.log
# echo ABC
# GDB_EXIT=${PIPESTATUS[0]}
PIPE_STATUSES=("${PIPESTATUS[@]}")
# echo "timeout/gdb exit: ${PIPE_STATUSES[0]}"
# echo "tee exit:         ${PIPE_STATUSES[1]}"
GDB_EXIT=${PIPE_STATUSES[0]}
set -e

# case "$GDB_EXIT" in
#     0)
#         ;;
#     124)
#         echo "GDB session timed out"
#         cat etiss_output.log
#         exit 1
#         ;;
#     *)
#         echo "GDB failed with exit code $GDB_EXIT"
#         cat etiss_output.log
#         exit 1
#         ;;
# esac

# grep -q "Remote communication error" gdb_output.log && GDB_CRASH=1 || GDB_CRASH=0
#
# if [[ $GDB_CRASH -ne 0 ]]
# then
#     echo "GDB connection lost!"
#     exit 1
# fi

if [[ $GDB_EXIT -eq 124 ]]; then
    echo "GDB session timed out!"
    exit 1
fi

# A nonzero GDB status is expected when ETISS terminates and closes the
# remote connection. Only reject it when the expected close is absent.
if [[ $GDB_EXIT -ne 0 ]] &&
   ! grep -q "Remote connection closed" gdb_output.log; then
    echo "GDB session failed with exit code $GDB_EXIT"
    exit 1
fi

# Detect known abnormal remote errors separately.
if grep -qE \
    "Remote communication error|Remote connection unexpectedly closed|Connection timed out" \
    gdb_output.log; then
    echo "GDB connection failed!"
    exit 1
fi

# read -n 1

# echo "Done"

echo "Waiting for etiss to close... (PID=$ETISS_PID)"

set +e
wait $ETISS_PID
ETISS_EXIT=$?
set -e

echo ETISS_EXIT=$ETISS_EXIT

if (( ETISS_EXIT != 0 )); then
    echo "ETISS failed"
    cat etiss_output.log
    exit 1
fi

checks=(
  '^x0[[:space:]]+0x0[[:space:]]+0($|[[:space:]])'
  '^zero[[:space:]]+0x0[[:space:]]+0($|[[:space:]])'
  '^pc[[:space:]]+0x[0-9a-fA-F]+[[:space:]]+0x[0-9a-fA-F]+[[:space:]]+<[^>]+>'
  'Breakpoint 1,'
  'Breakpoint 2,'
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
rm etiss_output.log
rm gdb_output.log

echo "✅ test passed"
