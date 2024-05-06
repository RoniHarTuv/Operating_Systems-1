CXX = g++
CXXFLAGS = -g -Wall -Wextra 

.PHONY: all clean

all: undefinedMemory stackOverFlow ZeroDivision

undefinedMemory: undefinedMemory.o
	$(CXX) $(CXXFLAGS) $^ -o $@

stackOverFlow: stackOverFlow.o
	$(CXX) $(CXXFLAGS) $^ -o $@

ZeroDivision: ZeroDivision.o 
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o undefinedMemory stackOverFlow ZeroDivision
