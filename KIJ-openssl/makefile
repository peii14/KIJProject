# the compiler
CC = g++

# compiler flags
CFLAGS  = -g -Wall -lcrypto

main: aes.cpp ../bitmap.cpp
	$(CC) aes.cpp $(CFLAGS) ../bitmap.cpp  -o main

clean:
	$(RM) main
