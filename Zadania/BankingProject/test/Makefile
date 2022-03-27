# Makefile for Writing Make Files
 
# *****************************************************
# Variables to control Makefile operation
CC = g++
CFLAGS = -Wall -g

INCLUD_DIR =../util/libs
SOURCE_DIR =../util/src/

# ****************************************************
# Targets needed to bring the executable up to date

bankingProject: bankingProject.o bank.o account.o
	$(CC) $(CFLAGS) -o bankingProject bankingProject.o bank.o account.o

bankingProject.o: bankingProject.cpp
	$(CC) $(CFLAGS) -c bankingProject.cpp

bank.o: $(SOURCE_DIR)bank.cpp account.o
	$(CC) $(CFLAGS) -c -I$(INCLUD_DIR) $(SOURCE_DIR)bank.cpp

account.o: $(SOURCE_DIR)account.cpp
	$(CC) $(CFLAGS) -c -I$(INCLUD_DIR) $(SOURCE_DIR)account.cpp

clean:
	del bankingProject.o bank.o account.o
