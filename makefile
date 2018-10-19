
all: driver.o library.o linked-list.o
	gcc -o out driver.o library.o linked-list.o

driver.o: driver.c library.h linked-list.h
	gcc -c driver.c

library.o: library.c linked-list.h 
	gcc -c library.c

linked-list.o: linked-list.c
	gcc -c linked-list.c

run:
	./out

clean:
	rm out
	rm *.o