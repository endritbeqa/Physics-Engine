
app: test.o
	g++ -o test.exe  -L$(shell pwd) -labc test.o


test.o : test.cpp
	g++ -fPIC -o test.o -c test.cpp


