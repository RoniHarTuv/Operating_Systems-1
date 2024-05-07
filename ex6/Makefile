CXX = g++
CXXFLAGS = -g -Wall 

.PHONY: all clean

all: add2pb find_phone

find_phone: findPhone.cpp
	$(CXX) $(CXXFLAGS)  -o $@ $^

add2pb: add2PB.cpp
	$(CXX) $(CXXFLAGS)  -o $@ $^	

clean:
	rm -f *.o  add2pb find_phone
