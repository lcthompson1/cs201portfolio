CC = gcc
CFLAGS = -g -Wall -pedantic
DEP = db.c main.c db_create.c movie_entry.c
DEPO =  db.o main.o db_create.o movie_entry.o

program: $(DEPO)
	$(CC) $(CFLAGS) -o program $(DEPO) 

clean:
	rm program
	rm *.o