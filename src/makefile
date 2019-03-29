CC = gcc
CFLAGS = -g -Wall -pedantic
DEP = movie_entry.c ll.c db.c db_create.c movie_log.c log_create.c menu.c main.c 
DEPO = movie_entry.o ll.o db.o db_create.o movie_log.o log_create.o menu.o main.o 

program: $(DEPO)
	$(CC) $(CFLAGS) -o program $(DEPO) -lncurses

clean:
	rm *.o
	rm program