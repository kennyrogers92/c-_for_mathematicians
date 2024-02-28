interval = ../Uniform/uniform.o Interval.o
median = ../Uniform/uniform.o median.o
unitcube = ../Uniform/uniform.o unitCube.o
includes = -L../Uniform/
CXXFLAGS = -Wall

interval: $(interval)
	g++ $(interval) $(includes) -o exec

median: $(median)
	g++ $(median) $(includes) -o exec 

unitcube: $(unitcube)
	g++ $(unitcube) $(includes) -o exec; ./exec

clean: 
	rm -f *.o