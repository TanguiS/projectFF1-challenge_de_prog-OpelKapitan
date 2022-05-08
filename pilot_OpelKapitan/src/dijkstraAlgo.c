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
 * @file dijkstraAlgo.c
 * @brief This file contains the functions to implement the Dijstra's algo.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 29 avril 2022
 */

#include "../include/dijkstraAlgo.h"





void initDijkstraLenght(dijkstraMatrix* dijkstraMatrix, int width, int heigth, short x, short y) {
    int i;
    int j;

    for (i=0; i<heigth; i++){
        for (j=0; j<width; j++) {
            dijkstraMatrix->matrix[i][j].pathLength = SHRT_MAX;
        }
    }
    dijkstraMatrix->matrix[x][y].pathLength = 0;
}


void mixeCoord (coord* reference, coord* result ) {
    *(result)[0] = *(reference)[0];
    *(result)[1] = *(reference)[1];   
}

void findMin(GRAPH* graph, short x, short y, coord* sommet) {
    short min = SHRT_MAX;
    coord* succ;
    short i;
    short sizeSucc;
    int distance;

    sommet[0][0] = -1;
    *(sommet)[1] = -1;   
    succ = getSuccessorGraph(graph, x, y);
    sizeSucc = *(succ)[0];

    for (i=1; i<sizeSucc; i++) { 
        distance = (short) getElementGraph(graph, x, y);
        if ( distance < min) {
            min = distance;
            mixeCoord(succ[i], sommet);
        }
    }
}