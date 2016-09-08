#!/bin/sh

cd install/tests

regeneratetest() {
    #copy tests from DACOMP if needed
    if [ ! -f test$i.bc.ver]
    then
        #FIXME Shouldn't use hardcoded paths
        cp ../../../DACOMPILER/src/tests/verification/test$1.bc.ver .
    fi
    #copy tests from dacomp
    ./davm test$1.bc.ver > test_bc$1.ver
    ./test$1 > test$1.ver
}

for i in `seq 1 2`
do
    regeneratetest $i
done
