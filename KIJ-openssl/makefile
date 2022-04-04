# the compiler
CC = g++

# compiler flags
CFLAGS  = -g -Wall -lcrypto

main: aes.cpp ../bitmap.cpp rsa.cpp 
	$(CC) aes.cpp $(CFLAGS) rsa.cpp $(CFLAGS) ../bitmap.cpp   -o main

clean:
	$(RM) main
