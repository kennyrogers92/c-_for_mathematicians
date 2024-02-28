ulam = ../Uniform/uniform.o ../GCD/gcd.o Permutation.o ulam.o
includes = -L../Uniform/ -L../GCD/
CXXFLAGS = -Wall

ulam: $(ulam)
	g++ $(ulam) $(includes) -o exec; ./exec

clean:
	-rm -f *.o