CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic -Werror -std=c++17
OPTFLAGS=-g
LDFLAGS=$(CXXFLAGS) $(OPTFLAGS)

all: extracredit

extracredit: extracredit.cpp
	$(CXX) $(LDFLAGS) -o extracredit extracredit.cpp

clean:
	rm -rf *.o extracredit
