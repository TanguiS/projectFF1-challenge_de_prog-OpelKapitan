BIN_PATH = ./bin
OBJ_PATH = ./obj
INC_PATH = ../../include

CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -g
CPPFLAGS = -I$(INC_PATH)
LDFLAGS = -lm


install: $(BIN_PATH)/dijstra.out

OBJS = $(OBJ_PATH)/main_dijstra.o

try: install
	$(install)

$(OBJ_PATH)/main_dijstra.o: ./main_dijkstra.c $(INC_PATH)/dijkstraAlgo.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@



$(BIN_PATH)/dijstra.out: $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $(BIN_PATH)/dijstra.out $(LDFLAGS)


clean: $(OBJ_PATH) #Détruire les fichiers temporaires
	rm $</*.o
distclean: $(BIN_PATH)
	make clean
	rm $(install)