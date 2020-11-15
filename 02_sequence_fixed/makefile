OBJECTS= sequence1.o sequence_exam.o
CFLAGS= -Wall
CC= g++

run: sequence_exam
	./sequence_exam

sequence_exam: $(OBJECTS)
	$(CC) $(OBJECTS) -o sequence_exam 

sequence1.o: sequence1.cpp sequence1.h
	$(CC) $(CFLAGS) -c sequence1.cpp

sequence_exam.o: sequence_exam.cpp sequence1.h
	$(CC) $(CFLAGS) -c sequence_exam.cpp

clean:
	rm *.o sequence_exam