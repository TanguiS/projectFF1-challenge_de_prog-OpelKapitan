PILOT_NAME = OpelKapitan

SRC_PATH = ./src
INC_PATH = ./include
OBJ_PATH = ./obj
BIN_PATH = ../drivers
LIB_PATH = ./lib

CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -g
CPPFLAGS = -I$(INC_PATH) -L$(LIB_PATH)
LDFLAGS = -lm

SANITIZE=off
ifeq ($(SANITIZE),on)
CFLAGS += -fsanitize=address
endif
ifeq ($(DEBUG),off)
CFLAGS += -D'DEBUG'
endif

OBJS = $(OBJ_PATH)/main.o $(OBJ_PATH)/readMap.o $(OBJ_PATH)/pilotManagement.o $(OBJ_PATH)/pilotDirection.o $(OBJ_PATH)/graphMadj.o $(OBJ_PATH)/matrix.o

install: $(BIN_PATH)/$(PILOT_NAME)

try: install
	cd .. ; ./GrandPrix

$(OBJ_PATH)/main.o: $(SRC_PATH)/main.c $(INC_PATH)/readMap.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/readMap.o: $(SRC_PATH)/readMap.c $(INC_PATH)/readMap.h 
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/matrix.o: $(SRC_PATH)/matrix.c $(INC_PATH)/matrix.h 
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/pilotManagement.o: $(SRC_PATH)/pilotManagement.c $(INC_PATH)/pilotManagement.h 
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/pilotDirection.o: $(SRC_PATH)/pilotDirection.c $(INC_PATH)/pilotDirection.h 
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/graphMadj.o: $(SRC_PATH)/graphMadj.c $(INC_PATH)/graphMadj.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_PATH)/$(PILOT_NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $(BIN_PATH)/$(PILOT_NAME) $(LDFLAGS)

clean: $(OBJ_PATH) #Détruire les fichiers temporaires
	rm $</*.o
distclean: $(BIN_PATH)
	make clean
	rm $(BIN_PATH)/$(PILOT_NAME)