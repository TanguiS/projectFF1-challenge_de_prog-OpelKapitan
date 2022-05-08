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



void mixeCoord (coord* reference, coord* result ) {
    result[0][0] = reference[0][0];
    result[0][1] = reference[0][1];   
}

boolean sameCoord(coord sommet1, coord sommet2) {
    if (sommet1[0] == sommet2[0] && sommet1[1] == sommet2[1]) {
        return true;
    }
    return false;
}


void initDijkstraLenght(dijkstraMatrix* dijkstraMatrix, short x, short y) {
    int i;
    int j;

    for (i=0; i<getHeigthMatrixDijkstra(dijkstraMatrix); i++) {
        for (j=0; j<getWidthMatrixDijkstra(dijkstraMatrix); j++) {
            setPathLength ( dijkstraMatrix, j, i, SHRT_MAX );
        }
    }
    setPathLength ( dijkstraMatrix, x, y, 0 );
    displayDijkstraMatrix ( dijkstraMatrix );
}



void findMin(GRAPH* graph, short x, short y, coord* sommet, boolean** flag) {
    short min = SHRT_MAX;
    coord* succ;
    short i;
    short sizeSucc;
    int distance;

    sommet[0][0] = -1;
    sommet[0][1] = -1;   
    succ = getSuccessorGraph(graph, x, y);
    sizeSucc = succ[0][0];

    for (i=1; i<sizeSucc; i++) { 
        distance = (short) getElementGraph(graph, succ[i][0], succ[i][1]);
        if ( distance < min && flag[succ[i][0]][succ[i][1]] == false ) {       /*succ is not visited*/ 
            min = distance;
            mixeCoord(&(succ[i]), sommet);
        }
    }
    flag[sommet[0][0]][sommet[i][1]] = true;
    free ( succ );
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
    displayDijkstraMatrix ( dijkstra );
}



void allPathDijkstra(dijkstraMatrix* dijkstra, GRAPH* graph, coord firstSommet) {
    boolean** flag;
    int i;
    int countTrue = 0;
    coord sommet;
    coord* succ;
    short sizeSucc; 
    

    flag = (boolean**)malloc ( getWidthMatrixDijkstra ( dijkstra ) * sizeof ( boolean* ) );
    for ( i = 0; i < getWidthMatrixDijkstra ( dijkstra ); i++ ) {
        flag[i] = (boolean*) calloc ( getHeigthMatrixDijkstra ( dijkstra ), sizeof ( boolean ) );
    }
    initDijkstraLenght(dijkstra, firstSommet[0], firstSommet[1]);
    sommet[0] = firstSommet[0];
    sommet[1] = firstSommet[1];

    while (countTrue != getWidthMatrixDijkstra(dijkstra) * getHeigthMatrixDijkstra(dijkstra)) {
        succ = getSuccessorGraph(graph, sommet[0], sommet[1]);
        sizeSucc = succ[0][0];
        for (i=1; i<sizeSucc; i++) {
            updateDistance(dijkstra, graph, sommet, succ[i]);
        }
        findMin(graph, sommet[0], sommet[1], &sommet, flag);
        countTrue++;
        free ( succ );
    }
    free(flag);
} 

LIFO givePath(dijkstraMatrix* dijkstra, GRAPH* graph, short firstx, short firsty, short finalx, short finaly) {
    coord sommet;
    LIFO stack;
    coord firstSommet;
    coord finalSommet;

    firstSommet[0] = firstx;
    firstSommet[1] = firsty;
    finalSommet[0] = finalx;
    finalSommet[1] = finaly;
    allPathDijkstra ( dijkstra, graph, firstSommet );
    stack = createLifo();
    mixeCoord(&finalSommet, &sommet);
    while( !sameCoord(sommet, firstSommet) ) {
        stack = addElementLifo(stack, sommet);
        getPredecessor(dijkstra, sommet[0], sommet[1], &sommet);
    }
    stack = addElementLifo(stack, firstSommet);
    return stack;
}