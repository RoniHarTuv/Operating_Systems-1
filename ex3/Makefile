CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11
LIBS = -lm
OBJS = q3.o Poisson.o

.PHONY: all clean

all: q3

q3: $(OBJS) libpoisson.so
	$(CXX) $(CXXFLAGS) -o q3 $(OBJS) -L. -lpoisson $(LIBS)

libpoisson.so: Poisson.o
	$(CXX) $(CXXFLAGS) -shared -fPIC -o libpoisson.so Poisson.o

Poisson.o: Poisson.cpp Poisson.hpp
	$(CXX) $(CXXFLAGS) -fPIC -c Poisson.cpp -o Poisson.o

q3.o: q3.cpp Poisson.hpp
	$(CXX) $(CXXFLAGS) -c q3.cpp -o q3.o

clean:
	rm -f *.o q3 libpoisson.so