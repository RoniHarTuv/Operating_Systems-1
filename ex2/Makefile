CXX = g++
CXXFLAGS = -g -Wall -lm

.PHONY: all clean

all: poisson

poisson: Poisson.o
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o poisson