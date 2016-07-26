cd install/tests

#copy tests from dacomp
cp ../../../DACOMPILER/src/tests/verification/test1.bc.ver .
cp ../../../DACOMPILER/src/tests/verification/test2.bc.ver .

#copy tests from dacomp
./davm test1.bc.ver > test_bc1.ver

#test bc 2
./davm test2.bc.ver > test_bc2.ver

#test1
./test1 > test1.ver

#test2
./test2 > test2.ver
