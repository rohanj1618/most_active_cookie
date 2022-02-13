CXX=clang++
CXXFlAGS=-g -std=c++11 -pedantic -Wall -Werror -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable -Wno-unused-function

most_active_cookie: main.o cookie.o
	$(CXX) $(CXXFlAGS) -o most_active_cookie main.o cookie.o

main.o: main.cpp
	$(CXX) $(CXXFlAGS) -c main.cpp

test.o: test.cpp
	$(CXX) $(CXXFlAGS) -c test.cpp

cookie.o: cookie.cpp
	$(CXX) $(CXXFlAGS) -c cookie.cpp

test: main.o test.o cookie.o
	$(CXX) $(CXXFlAGS) -o test test.o cookie.o

clean:
	rm -f most_active_cookie main.o test.o test cookie.o