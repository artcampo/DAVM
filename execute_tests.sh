#!/bin/sh

cd install/tests

executetest() {
    cp ../../../DACOMPILER/src/tests/verification/test$1.bc.ver .
    # Test bytecode
    ./davm test$1.bc.ver > test$1.out
    diff test$1.out test_bc$1.ver
    rm test$1.out 
    # Test correctness of executable
    ./test$1 > test$1.out
    diff test$1.out test$1.ver
    rm test$1.out 
}

for i in `seq 1 2`
do
    executetest $i
done

echo "Done testing"

