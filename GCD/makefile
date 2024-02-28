test1 = gcd.o test1.o
test2 = gcdx.o test2.o
problem = gcd.o problem.o
CXXFLAGS = -Wall

test1: $(test1)
	g++ $(test1) -o exec

test2: $(test2)
	g++ $(test2) -o exec

problem: $(problem)
	g++ $(problem) -o exec

clean: 
	rm -f *.o