OBJECTS= statexam.o stats.o
CFLAGS= -Wall
CC= g++

run: statexam
	./statexam

statexam: $(OBJECTS)
	$(CC) $(OBJECTS) -o statexam 

statexam.o: statexam.cpp stats.h
	$(CC) $(CFLAGS) -c statexam.cpp

stats.o: stats.cpp stats.h
	$(CC) $(CFLAGS) -c stats.cpp

clean:
	rm *.o statexam