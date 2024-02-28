main = main.o ../Uniform/uniform.o PObject.o PPoint.o PLine.o
pappus = ../Uniform/uniform.o PObject.o PPoint.o PLine.o pappus.o
desargues = ../Uniform/uniform.o PObject.o PPoint.o PLine.o desargues.o
includes = -L../Uniform/
CXXFLAGS = -Wall

main: $(main)
	g++ $(main) $(includes) -o exec

pappus: $(pappus)
	g++ $(pappus) $(includes) -o exec

desargues: $(desargues)
	g++ $(desargues) $(includes) -o exec

clean:
	rm -f *.o

