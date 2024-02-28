problem = uniform.o ../GCD/gcd.o problem.o
includes = -L../GCD/
CXXFLAGS = -Wall

problem: $(problem)
	g++ $(problem) $(includes) -o exec

clean: 
	rm -f *.o