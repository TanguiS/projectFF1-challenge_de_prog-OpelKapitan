BIN_PATH = ./bin
OBJ_PATH = ./obj
INC_PATH = ../../include
SRC_PATH = ../../src

CC = gcc
CFLAGS = -Wall -Wextra -ansi -pedantic -g
CPPFLAGS = -I$(INC_PATH)
LDFLAGS = -lm


install: $(BIN_PATH)/dijkstra.out
matrix: $(BIN_PATH)/matrix.out

OBJS = $(OBJ_PATH)/main_dijstra.o $(OBJ_PATH)/dijkstraAlgo.o $(OBJ_PATH)/dijkstraMatrix.o $(OBJ_PATH)/graphMadj.o $(OBJ_PATH)/matrix.o $(OBJ_PATH)/lifo.o $(OBJ_PATH)/list.o
OBJS_MATRIX = $(OBJ_PATH)/main_matrix.o $(OBJ_PATH)/matrix.o

try: install
	$(install)

$(OBJ_PATH)/main_dijstra.o: ./main_dijkstra.c $(INC_PATH)/dijkstraAlgo.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
$(OBJ_PATH)/dijkstraAlgo.o: $(SRC_PATH)/dijkstraAlgo.c $(INC_PATH)/dijkstraAlgo.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
$(OBJ_PATH)/dijkstraMatrix.o: $(SRC_PATH)/dijkstraMatrix.c $(INC_PATH)/dijkstraAlgo.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
$(OBJ_PATH)/graphMadj.o: $(SRC_PATH)/graphMadj.c $(INC_PATH)/graphMadj.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
$(OBJ_PATH)/matrix.o: $(SRC_PATH)/matrix.c $(INC_PATH)/matrix.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
$(OBJ_PATH)/lifo.o: $(SRC_PATH)/lifo.c $(INC_PATH)/lifo.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_PATH)/list.o: $(SRC_PATH)/list.c $(INC_PATH)/list.h 
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


$(OBJ_PATH)/main_matrix.o: ./main_matrix.c $(INC_PATH)/matrix.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
$(OBJ_PATH)/matrix.o: ../matrix.c $(INC_PATH)/matrix.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@


$(BIN_PATH)/dijkstra.out: $(OBJS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $(BIN_PATH)/dijkstra.out $(LDFLAGS)

$(BIN_PATH)/matrix.out: $(OBJS_MATRIX)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $(BIN_PATH)/matrix.out $(LDFLAGS)

clean: $(OBJ_PATH) #Détruire les fichiers temporaires
	rm $</*.o
distclean: $(BIN_PATH)
	make clean
	rm $</*out