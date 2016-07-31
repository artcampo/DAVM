cd install/tests

#copy tests from dacomp
cp ../../../DACOMPILER/src/tests/verification/test1.bc.ver .
cp ../../../DACOMPILER/src/tests/verification/test2.bc.ver .
cp ../../../DACOMPILER/src/tests/verification/test3.bc.ver .

#test bc 1
./davm test1.bc.ver > test1.out
diff test1.out test_bc1.ver
rm test1.out 

#test bc 2
./davm test2.bc.ver > test1.out
diff test1.out test_bc2.ver
rm test1.out 

#test1
./test1 > test1.out
diff test1.out test1.ver
rm test1.out 

#test2
./test2 > test2.out
diff test2.out test2.ver
rm test2.out