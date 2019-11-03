CXXFLAGS=-std=c++14 -Wall -Wextra -Werror
CPPFLAGS=-I. -D_GLIBCXX_DEBUG

all: trim_test

trim_test: trim_test.o
	$(CXX) -o $@ $<

clean:
	rm -f trim_test trim_test.o
