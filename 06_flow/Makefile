TARGET = main
OBJS = main.o

CC = c++
CFLAGS = -c -W -Wall -Wno-write-strings
LD = c++
LDFLAGS = -o $(TARGET)
LIBS = -lncursesw

all : $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) $(LIBS)

.cpp.o:
	$(CC) $(CFLAGS) $<

clean:
	rm *.o
	rm $(TARGET)
