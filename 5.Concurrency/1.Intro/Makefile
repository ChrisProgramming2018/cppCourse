CXX = g++ -std=c++11 -g #-D_GLIBCXX_USE_CXX11_ABI=0
CXX1 = g++ -std=c++11 -D_GLIBCXX_USE_CXX11_ABI=0
CHECKSTYLE = python ../cpplint.py
MAIN = $(basename $(wildcard *Main.cpp))
TEST = $(basename $(wildcard *Test.cpp))
OBJECTS = $(addsuffix .o, $(filter-out %Main %Test, $(basename $(wildcard *.cpp))))
HEADERS = $(wildcard *.h)
LIBS = -pthread 

.PRECIOUS: %.o

all: compile test checkstyle

compile: $(MAIN)

test: $(TEST)
	for T in $(TEST); do ./$$T; done

checkstyle:
	$(CHECKSTYLE) *.cpp *.h

%Main: %Main.o $(OBJECTS)
	$(CXX1) -o $@ $^ $(LIBS)

%Test: %Test.o $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS) -lgtest -lgtest_main -lpthread

%.o: %.cpp $(HEADERS)
	$(CXX) -c $<

clean:
	rm -f *.o
	rm -f core
	rm -f $(MAIN)
	rm -f $(TEST)
