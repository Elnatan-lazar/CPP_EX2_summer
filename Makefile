
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror -I.
GUIFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99

SOURCES_Demo = Tree.hpp Node.hpp Demo.cpp
SOURCES_TEST = Tree.hpp Node.hpp  test.cpp testCounter.cpp

all: Demo test
	
Tree : Demo
	./$^

Demo: Demo.o Tree.o Node.o
	$(CXX) $(CXXFLAGS) $^ -o $@ $(GUIFLAGS)

test: test.o testCounter.o tree.o node.o
	$(CXX) $(CXXFLAGS) $^ -o $@

valgrind: Demo test
	valgrind $(VALGRIND_FLAGS) ./Demo
	

%.o: %.cpp

	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o Demo test

.PHONY: all test  clean valgrind

#