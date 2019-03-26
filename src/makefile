CC = gcc
CFLAGS = -g -Wall -pedantic
DEP = movie_entry.c db.c db_create.c  main.c 
DEPO = movie_entry.o db.o db_create.o  main.o 

program: $(DEPO)
	$(CC) $(CFLAGS) -o program $(DEPO) 

clean:
	rm program
	rm *.o