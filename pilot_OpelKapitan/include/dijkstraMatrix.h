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
} flagNode;  

typedef struct _elementDijkstra {
    POSITION predecessor; 
    short pathLength;
    flagNode flag;
}elementdij;

typedef struct _dijkstraMatrix {
    short width;
    short height;
    elementdij** matrix;
}DIJKSTRA;



short getWidthDijkstra(DIJKSTRA* dijkstra);

short getHeigthDijkstra(DIJKSTRA* dijkstra);

elementdij getElementDijkstra(DIJKSTRA* dijkstra, short x, short y);

short getPathLength(DIJKSTRA* dijkstra, short x, short y);

void setElementDijkstra(DIJKSTRA* dijkstra, short x, short y, elementdij values);

void setPathLength(DIJKSTRA* dijkstra, short x, short y, short newPathLength);

void setPredecessor(DIJKSTRA* dijkstra, short x, short y, POSITION newPredecessor);

void getPredecessor(DIJKSTRA* dijkstra, short x, short y, POSITION* result);

void setFlag ( DIJKSTRA* dijkstra, POSITION node, flagNode flag );

boolean isNodeWhite ( DIJKSTRA* dijkstra, POSITION nodeToTest );

boolean isNodeBlack ( DIJKSTRA* dijkstra, POSITION nodeToTest );

boolean isNodeGray ( DIJKSTRA* dijkstra, POSITION nodeToTest );

DIJKSTRA createDijkstraMatrix(short width, short heigth);

void destroyDijkstraMatrix(DIJKSTRA dijkstra);

#ifndef DEBUG
void displayDijkstraMatrix(DIJKSTRA* dijkstra, short x, short y );
void displayDijkstraMatrixPath(DIJKSTRA* dijkstra, int count, POSITION* path);
#endif



#endif 