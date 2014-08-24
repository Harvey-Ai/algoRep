allHeader = DSSetTester.h SegTreeTester.h suffixArrTester.h
target = Tester
flag =  -g

all:$(allHeader) Tester.cpp
	g++ $(flag) $^ -o $(target)

.PHONY: clean

clean:
	rm *.o
