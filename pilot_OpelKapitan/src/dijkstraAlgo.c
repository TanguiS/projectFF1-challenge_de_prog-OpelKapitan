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



void mixePOSITION (POSITION* reference, POSITION* result ) {
    result->X = reference->X;
    result->Y = reference->Y;   
}

boolean samePOSITION(POSITION sommet1, POSITION sommet2) {
    if (sommet1.X == sommet2.X && sommet1.Y == sommet2.Y) {
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
            dijkstraMatrix->matrix[j][i].flag = white;
        }
    }
    setPathLength ( dijkstraMatrix, x, y, 0 );
    dijkstraMatrix->matrix[x][y].flag = gray;
    displayDijkstraMatrix ( dijkstraMatrix, -1, -1 );
}



void findMin(dijkstraMatrix* dijkstra, POSITION* sommet, LIST list ) {
    short i;
    POSITION minTemp;

    i = getElementList(list, sommet, 0);
    mixePOSITION(sommet, &minTemp);
    while (i) {
        i = getNextElementList(list, &minTemp, &minTemp);
        if (getPathLength(dijkstra, sommet->X, sommet->Y) > getPathLength(dijkstra, minTemp.X, minTemp.Y)) {
            mixePOSITION(&minTemp, sommet);
        }
    }
    dijkstra->matrix[sommet->X][sommet->Y].flag = black;
    displayDijkstraMatrix ( dijkstra, sommet->X, sommet->Y );
}

void updateDistance(dijkstraMatrix* dijkstra, GRAPH* graph, POSITION sommet1, POSITION sommet2) {
    short d1;
    short d2;
    short arcValue;

    d1 = getPathLength(dijkstra, sommet1.X, sommet1.Y);
    d2 = getPathLength(dijkstra, sommet2.X, sommet2.Y);
    arcValue = (short)getElementGraph(graph, sommet2);

    if ( d2 > (d1 + arcValue) ) {
        setPathLength(dijkstra, sommet2.X, sommet2.Y, (d1 + arcValue));
        setPredecessor(dijkstra, sommet2.X, sommet2.Y, sommet1);
        displayDijkstraMatrix ( dijkstra, sommet2.X, sommet2.Y );
        return;
    }
    displayDijkstraMatrix ( dijkstra, sommet1.X, sommet1.Y );

}



void allPathDijkstra(dijkstraMatrix* dijkstra, GRAPH* graph, POSITION firstSommet) {
    int i;
    POSITION sommet;
    POSITION* succ;
    short sizeSucc;
    LIST list;
    
    list = createList();
    initDijkstraLenght(dijkstra, firstSommet.X, firstSommet.Y);
    sommet.X = firstSommet.X;
    sommet.Y = firstSommet.Y;
    list = addElementList(list, sommet);
    

    while (!isEmptyList(list)) {
        findMin(dijkstra, &sommet, list);
        succ = getSuccessorGraph(graph, sommet);
        sizeSucc = succ[0].X;
        for (i=1; i<sizeSucc; i++) {
            if ( dijkstra->matrix[succ[i].X][succ[i].Y].flag == white ) {
                list = addElementList(list, succ[i]);
                dijkstra->matrix[succ[i].X][succ[i].Y].flag = gray;
                displayDijkstraMatrix(dijkstra, sommet.X, sommet.Y);
            } 
            updateDistance(dijkstra, graph, sommet, succ[i]);
        }
        list = removeElementList(list, &sommet);
        free ( succ );
    }
    destroyList(list);
} 

PATH_LIST givePath(dijkstraMatrix* dijkstra, GRAPH* graph, short firstx, short firsty, short finalx, short finaly) {
    POSITION sommet;
    PATH_LIST stack;
    POSITION firstSommet;
    POSITION finalSommet;

    firstSommet.X = firstx;
    firstSommet.Y = firsty;
    finalSommet.X = finalx;
    finalSommet.Y = finaly;
    allPathDijkstra ( dijkstra, graph, firstSommet );
    displayDijkstraMatrix ( dijkstra, -1, -1 );
    stack = createPathList();
    mixePOSITION(&finalSommet, &sommet);
    while( !samePOSITION(sommet, firstSommet) ) {
        stack = addHeadElementPathList(stack, sommet);
        getPredecessor(dijkstra, sommet.X, sommet.Y, &sommet);
    }
    stack = addHeadElementPathList(stack, firstSommet);
    return stack;
}