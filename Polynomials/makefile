problem = ../GCD/gcdx.o problem.o
includes = -L../GCD/
CXXFLAGS = -Wall

problem: $(problem)
	g++ $(problem) $(includes) -o exec; ./exec

clean: 
	rm -f *.o