CXX = g++
CXXFLAGS = -g -Wall -lm -pg

.PHONY: all clean

all: sub1 sub2 sub3

sub1: subArray1.cpp
	$(CXX) $(CXXFLAGS)  -o $@ $^

sub2: subArray2.cpp
	$(CXX) $(CXXFLAGS)   -o $@ $^

sub3: subArray3.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^


clean:
	rm -f *.o sub1 sub2 sub3 
