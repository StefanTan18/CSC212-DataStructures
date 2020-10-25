OBJECTS= sequence3.o node1.o seq_ex3.o
CFLAGS= -Wall
CC= g++

run: seq_ex3
	./seq_ex3

seq_ex3: $(OBJECTS)
	$(CC) $(OBJECTS) -o seq_ex3 

sequence3.o: sequence3.cpp sequence3.h
	$(CC) $(CFLAGS) -c sequence3.cpp

node1.o: node1.cpp node1.h
	$(CC) $(CFLAGS) -c node1.cpp

seq_ex3.o: seq_ex3.cpp sequence3.h
	$(CC) $(CFLAGS) -c seq_ex3.cpp

clean:
	rm *.o seq_ex3