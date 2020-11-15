OBJECTS= sequence2.o seq_ex2.o
CFLAGS= -Wall
CC= g++

run: seq_ex2
	./seq_ex2

seq_ex2: $(OBJECTS)
	$(CC) $(OBJECTS) -o seq_ex2 

sequence2.o: sequence2.cpp sequence2.h
	$(CC) $(CFLAGS) -c sequence2.cpp

seq_ex2.o: seq_ex2.cpp sequence2.h
	$(CC) $(CFLAGS) -c seq_ex2.cpp

clean:
	rm *.o seq_ex2