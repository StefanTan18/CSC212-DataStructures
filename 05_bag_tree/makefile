OBJECTS= bagexam.o
CFLAGS= -Wall
CC= g++

run: bagexam
	./bagexam

bagexam: $(OBJECTS)
	$(CC) $(OBJECTS) -o bagexam

bagexam.o: bagexam.cpp bag5.h bag5.template bintree.h bintree.template
	$(CC) $(CFLAGS) -c bagexam.cpp

clean:
	rm *.o bagexam