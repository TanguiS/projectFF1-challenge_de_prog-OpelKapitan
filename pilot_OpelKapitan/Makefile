PILOT_NAME = OpelKapitan

SRC_PATH = ./src
INC_PATH = ./include
OBJ_PATH = ./obj
BIN_PATH = ../drivers
LIB_PATH = ./lib

CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -O3
CPPFLAGS = -I$(INC_PATH) -L$(LIB_PATH)
LDFLAGS = -lm

SANITIZE=off
ifeq ($(SANITIZE),on)
CFLAGS += -fsanitize=address
endif
ifeq ($(DEBUG),off)
CFLAGS += -D'DEBUG'
endif

OBJS = $(OBJ_PATH)/main.o $(OBJ_PATH)/communicatorWithGDC.o $(OBJ_PATH)/pilotManagement.o $(OBJ_PATH)/pilotDirection.o $(OBJ_PATH)/graph.o $(OBJ_PATH)/matrix.o $(OBJ_PATH)/pathList.o $(OBJ_PATH)/dijkstraAlgo.o $(OBJ_PATH)/dijkstraMatrix.o $(OBJ_PATH)/list.o $(OBJ_PATH)/follow_line.o $(OBJ_PATH)/actionModificator.o

install: $(BIN_PATH)/$(PILOT_NAME)

try: install
	cd .. ; ./GrandPrix

$(OBJ_PATH)/main.o: $(SRC_PATH)/main.c $(INC_PATH)/communicatorWithGDC.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/communicatorWithGDC.o: $(SRC_PATH)/communicatorWithGDC.c $(INC_PATH)/communicatorWithGDC.h 
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/matrix.o: $(SRC_PATH)/matrix.c $(INC_PATH)/matrix.h 
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/matrixDij.o: $(SRC_PATH)/dijkstraMatrix.c $(INC_PATH)/dijkstraMatrix.h 
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/pathList.o: $(SRC_PATH)/pathList.c $(INC_PATH)/pathList.h 
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/pilotManagement.o: $(SRC_PATH)/pilotManagement.c $(INC_PATH)/pilotManagement.h 
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/actionModificator.o: $(SRC_PATH)/actionModificator.c $(INC_PATH)/actionModificator.h 
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/pilotDirection.o: $(SRC_PATH)/pilotDirection.c $(INC_PATH)/pilotDirection.h 
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/graph.o: $(SRC_PATH)/graph.c $(INC_PATH)/graph.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/dijkstraAlgo.o: $(SRC_PATH)/dijkstraAlgo.c $(INC_PATH)/dijkstraAlgo.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/dijkstraMatrix.o: $(SRC_PATH)/dijkstraMatrix.c $(INC_PATH)/dijkstraAlgo.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/list.o: $(SRC_PATH)/list.c $(INC_PATH)/list.h 
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/follow_line.o: $(SRC_PATH)/follow_line.c $(INC_PATH)/follow_line.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_PATH)/$(PILOT_NAME): $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $(BIN_PATH)/$(PILOT_NAME) $(LDFLAGS)

clean: $(OBJ_PATH) #Détruire les fichiers temporaires
	rm $</*.o
distclean: $(BIN_PATH)
	make clean
	rm $(BIN_PATH)/$(PILOT_NAME)