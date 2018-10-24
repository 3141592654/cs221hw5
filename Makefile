CXX=g++
CXXFLAGS=-g -Wall -Wextra -pedantic -std=c++17
OPTFLAGS=-O3
LDFLAGS=$(OPTFLAGS) $(CXXFLAGS)

all: test_tree

test_tree: test_tree.cc tree.cc tree.hh tree.o
	$(CXX) $(LDFLAGS) -o test_tree test_tree.cc tree.o

tree.o: tree.cc tree.hh
	$(CXX) $(LDFLAGS) -c -o tree.o tree.cc

clean:
	rm -rf *.o test_tree
