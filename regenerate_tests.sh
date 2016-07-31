cd install/tests

regenerate_test_from_dacomp(){
  cp ../../../DACOMPILER/src/tests/verification/$1.bc.ver .
  cp ../../../DACOMPILER/src/tests/verification/$1.bc.ver \
     ../../src/tests/verification/.
  ./davm $1.bc.ver > $1.bc.out.ver
}

regenerate_test_from_dacomp test1
regenerate_test_from_dacomp test2
regenerate_test_from_dacomp test3

regenerate_test_standalone(){
  ./$1 > $1.ver
}

regenerate_test_standalone test1

#end
echo "Tests regenerated. You need to reinstall before running tests again."