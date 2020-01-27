CC=g++
CFLAGS=-w -std=c++17
LDLIBS=-lstdc++fs
OBJS=main.o Handle.o List.o File.o extension.o
TARGET=main

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDLIBS)

main.o:			main.cpp List.h
	g++ -c -o main.o main.cpp

Handle.o:		Handle.cpp List.h
	g++ -c -o Handle.o Handle.cpp

List.o:			List.cpp extension.h
	g++ -c -o List.o List.cpp

File.o:			File.cpp
	g++ -c -o File.o File.cpp

extension.o:	extension.cpp
	g++ -c -o extension.o extension.cpp

clean:
	rm *.o main
