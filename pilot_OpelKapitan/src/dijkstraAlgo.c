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





void initDijkstraLenght(dijkstraMatrix* dijkstraMatrix, short x, short y) {
    int i;
    int j;

    for (i=0; i<getHeigthMatrixDijkstra(dijkstraMatrix); i++) {
        for (j=0; j<getWidthMatrixDijkstra(dijkstraMatrix); j++) {
            dijkstraMatrix->matrix[i][j].pathLength = SHRT_MAX;
        }
    }
    dijkstraMatrix->matrix[x][y].pathLength = 0;
}


void mixeCoord (coord* reference, coord* result ) {
    *(result)[0] = *(reference)[0];
    *(result)[1] = *(reference)[1];   
}

void findMin(GRAPH* graph, short x, short y, coord* sommet, boolean* flag) {
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
        distance = (short) getElementGraph(graph, succ[i][0], succ[i][1]);
        if ( distance < min && flag[succ[i][1] * getWidthGraph(graph) + succ[i][0]] == false ) {       /*succ is not visited*/ 
            min = distance;
            mixeCoord(&(succ[i]), sommet);
        }
    }
    flag[*(sommet)[1] * getWidthGraph(graph) + *(sommet)[0]] = true;
}

void updateDistance(dijkstraMatrix* dijkstra, GRAPH* graph, coord sommet1, coord sommet2) {
    short d1;
    short d2;
    short arcValue;

    d1 = getPathLength(dijkstra, sommet1[0], sommet1[1]);
    d2 = getPathLength(dijkstra, sommet2[0], sommet2[2]);
    arcValue = (short)getElementGraph(graph, sommet2[0], sommet2[1]);

    if ( d2 > (d1 + arcValue) ) {
        setPathLength(dijkstra, sommet2[0], sommet2[1], (d1 + arcValue));
        setPredecessor(dijkstra, sommet2[0], sommet2[1], sommet1);
    }
}



void allPathDijkstra(dijkstraMatrix* dijkstra, GRAPH* graph,short scale, coord firstSommet) {
    boolean* flag;
    int i;
    int countTrue = 0;
    coord sommet;
    coord* succ;
    short sizeSucc; 

    flag = (boolean*)calloc(getWidthMatrixDijkstra(dijkstra) * getHeigthMatrixDijkstra(dijkstra), sizeof(boolean));
    initDijkstraLenght(dijkstra, firstSommet[0], firstSommet[1]);
    sommet[0] = firstSommet[0];
    sommet[1] = firstSommet[1];

    while (countTrue != getWidthMatrixDijkstra(dijkstra) * getHeigthMatrixDijkstra(dijkstra)) {
        findMin(graph, sommet[0], sommet[1], &sommet, flag);
        succ = getSuccessorGraph(graph, sommet[0], sommet[1]);
        sizeSucc = *(succ)[0];
        for (i=1; i<sizeSucc; i++) {
            updateDistance(dijkstra, graph, sommet, succ[i]);
        }
        countTrue++;
    }

    






    free(flag);
} 