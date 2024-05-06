CXX = g++
CXXFLAGS = -g -Wall -fprofile-arcs -ftest-coverage

.PHONY: all clean

all: dijkstra

dijkstra: Dijkstra.o
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -lgcov -c $< -o $@

clean:
	rm -f *.o dijkstra Dijkstra