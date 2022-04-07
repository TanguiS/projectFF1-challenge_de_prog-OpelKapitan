PILOT_NAME = OpelKapitan

SRC_PATH = ./src
INC_PATH = ./include
OBJ_PATH = ./obj
BIN_PATH = ../drivers
LIB_PATH = ./lib

CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -g
CPPFLAGS = -I$(INC_PATH) -L$(LIB_PATH)
LDFLAGS = 

SANITIZE=off
ifeq ($(SANITIZE),on)
CFLAGS += -fsanitize=address
endif
ifeq ($(DEBUG),off)
CFLAGS += -D'DEBUG'
endif

OBJS = $(OBJ_PATH)/main.o $(OBJ_PATH)/readMap.o 

install: $(BIN_PATH)/$(PILOT_NAME)

try: install
	cd .. ; ./GrandPrix

$(OBJ_PATH)/main.o: $(SRC_PATH)/main.c $(INC_PATH)/readMap.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/readMap.o: $(SRC_PATH)/readMap.c $(INC_PATH)/readMap.h 
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


$(BIN_PATH)/$(PILOT_NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $(BIN_PATH)/$(PILOT_NAME) $(LDFLAGS)

clean: $(OBJ_PATH) #Détruire les fichiers temporaires
	rm $</*.o