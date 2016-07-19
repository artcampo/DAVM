cd install/tests
#test1
./install/tests/test2


diff test1.out test1.ver
rm test1.out

#test2
./install/tests/test1
diff test2.out test2.ver
rm test2.out