CC=g++
CFLAGS=-c

all: test

test: test.o plain_matrix.o crs_matrix.o linalg.o
	$(CC) test.o plain_matrix.o crs_matrix.o linalg.o -o test

test.o: test.cpp
	$(CC) $(CFLAGS) test.cpp

plain_matrix.o: plain_matrix.cpp
	$(CC) $(CFLAGS) plain_matrix.cpp

crs_matrix.o: crs_matrix.cpp
	$(CC) $(CFLAGS) crs_matrix.cpp

linalg.o: linalg.cpp
	$(CC) $(CFLAGS) linalg.cpp

clean:
	rm -rf *.o
