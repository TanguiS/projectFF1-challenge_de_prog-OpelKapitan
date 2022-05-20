/**
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @file matrix.h
 * @brief This file contains prototypes and declarations to manage a matrix.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 06 mai 2022
 */



#ifndef __DIJ_MATRIX_HH__
#define __DIJ_MATRIX_HH__

#include <limits.h>

#include "dijkstraMatrix.h"
#include "util.h"
#include "graphMadj.h"
#include <stdio.h>
#include <stdlib.h>


typedef enum {
    white,
    gray,
    black
} dijBoolean;  

typedef struct _elementDijkstra {
    POSITION predecessor; 
    short pathLength;
    dijBoolean flag;
}elementdij;

typedef struct _dijkstraMatrix {
    short width;
    short height;
    elementdij** matrix;
}dijkstraMatrix;



short getWidthMatrixDijkstra(dijkstraMatrix* dijkstra);

short getHeigthMatrixDijkstra(dijkstraMatrix* dijkstra);


elementdij getElementDijkstra(dijkstraMatrix* dijkstra, short x, short y);

short getPathLength(dijkstraMatrix* dijkstra, short x, short y);

void setElementDijkstra(dijkstraMatrix* dijkstra, short x, short y, elementdij values);

void setPathLength(dijkstraMatrix* dijkstra, short x, short y, short newPathLength);

void setPredecessor(dijkstraMatrix* dijkstra, short x, short y, POSITION newPredecessor);

void getPredecessor(dijkstraMatrix* dijkstra, short x, short y, POSITION* result);

dijkstraMatrix createDijkstraMatrix(short width, short heigth);


void destroyDijkstraMatrix(dijkstraMatrix dijkstra);

#ifndef DEBUG
void displayDijkstraMatrix(dijkstraMatrix* dijkstra, short x, short y );
void displayDijkstraMatrixPath(dijkstraMatrix* dijkstra, int count, POSITION* path);
#endif



#endif 