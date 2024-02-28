testArr = ../GCD/gcd.o testArr.o
testSet = ../GCD/gcd.o testSet.o
includes = -L../GCD/
CXXFLAGS = -Wall

arr: $(testArr)
	g++ $(testArr) $(includes) -o exec

set: $(testSet)
	g++ $(testSet) $(includes) -o exec

clean: 
	rm -f *.o