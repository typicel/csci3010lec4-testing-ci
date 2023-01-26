CXX = g++
CXXFLAGS = -Wall -Werror -std=c++20

all: test main

test: test.cpp
	$(CXX) $(CXXFLAGS) test.cpp -o test

main: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o main

clean:
	rm main test