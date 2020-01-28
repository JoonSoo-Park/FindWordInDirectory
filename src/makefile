CC = g++
CFLAGS = -w -std=c++17
LDLIBS = -lstdc++fs
OBJS = main.o Handle.o List.o File.o extension.o
TARGET = main

.SUFFIXES: .cpp .o

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDLIBS)

clean:
	rm -f $(OBJS) $(TARGET)
