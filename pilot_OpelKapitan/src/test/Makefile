BIN_PATH = ./bin
OBJ_PATH = ./obj
INC_PATH = ../../include

CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -g
CPPFLAGS = -I$(INC_PATH)
LDFLAGS = -lm


install: $(BIN_PATH)/dijstra.out
matrix: $(BIN_PATH)/matrix.out

OBJS = $(OBJ_PATH)/main_dijstra.o
OBJS_MATRIX = $(OBJ_PATH)/main_matrix.o $(OBJ_PATH)/matrix.o

try: install
	$(install)

$(OBJ_PATH)/main_dijstra.o: ./main_dijkstra.c $(INC_PATH)/dijkstraAlgo.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


$(OBJ_PATH)/main_matrix.o: ./main_matrix.c $(INC_PATH)/matrix.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
$(OBJ_PATH)/matrix.o: ../matrix.c $(INC_PATH)/matrix.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


$(BIN_PATH)/dijstra.out: $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $(BIN_PATH)/dijstra.out $(LDFLAGS)

$(BIN_PATH)/matrix.out: $(OBJS_MATRIX)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $(BIN_PATH)/matrix.out $(LDFLAGS)

clean: $(OBJ_PATH) #Détruire les fichiers temporaires
	rm $</*.o
distclean: $(BIN_PATH)
	make clean
	rm $(install)