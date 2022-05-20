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


void mergePosition (POSITION* reference, POSITION* result ) {
    result->X = reference->X;
    result->Y = reference->Y;   
}

boolean areEqualsPosition(POSITION sommet1, POSITION sommet2) {
    if (sommet1.X == sommet2.X && sommet1.Y == sommet2.Y) {
        return true;
    }
    return false;
}

void initDijkstraLength(dijkstraMatrix* dijkstraMatrix, POSITION first) {
    int i;
    int j;

    for (i=0; i<getHeigthMatrixDijkstra(dijkstraMatrix); i++) {
        for (j=0; j<getWidthMatrixDijkstra(dijkstraMatrix); j++) {
            setPathLength ( dijkstraMatrix, j, i, SHRT_MAX );
            dijkstraMatrix->matrix[j][i].flag = white;
        }
    }
    setPathLength ( dijkstraMatrix, first.X, first.Y, 0 );
    dijkstraMatrix->matrix[first.X][first.Y].flag = gray;
    /*displayDijkstraMatrix ( dijkstraMatrix, -1, -1 );*/
}



void    findMin(dijkstraMatrix* dijkstra, POSITION* sommet, LIST list ) {
    short i;
    POSITION minTemp;

    i = getElementList(list, sommet, 0);
    mergePosition(sommet, &minTemp);
    while (i) {
        i = getNextElementList(list, &minTemp, &minTemp);
        if (getPathLength(dijkstra, sommet->X, sommet->Y) > getPathLength(dijkstra, minTemp.X, minTemp.Y)) {
            mergePosition(&minTemp, sommet);
        }
    }
    dijkstra->matrix[sommet->X][sommet->Y].flag = black;
    /*displayDijkstraMatrix ( dijkstra, sommet->X, sommet->Y );*/
}

void updateDistance(dijkstraMatrix* dijkstra, GRAPH* graph, POSITION sommet1, POSITION sommet2) {
    short d1;
    short d2;
    short arcValue;

    d1 = getPathLength(dijkstra, sommet1.X, sommet1.Y);
    d2 = getPathLength(dijkstra, sommet2.X, sommet2.Y);
    arcValue = (short)getElementGraph(graph, sommet2);
    arcValue += abs((sommet1.X - sommet2.X)) + abs((sommet1.Y - sommet2.Y)) - 1 ;
    if ( d2 > (d1 + arcValue) ) {
        setPathLength(dijkstra, sommet2.X, sommet2.Y, (d1 + arcValue));
        setPredecessor(dijkstra, sommet2.X, sommet2.Y, sommet1);
        /*displayDijkstraMatrix ( dijkstra, sommet2.X, sommet2.Y );*/
        return;
    }
   /* displayDijkstraMatrix ( dijkstra, sommet1.X, sommet1.Y );*/
}


void getSuccSand (GRAPH*graph, dijkstraMatrix* dijkstra ,LIST* list, POSITION parent) {
    POSITION successor;
    int i;
    static POSITION tab[] ={
                            {1, 0},
                            {-1, 0},
                            {0, 1},
                            {0, -1}
    };
    for (i=0; i<4; i++) {
        successor.X = parent.X + tab[i].X;
        successor.Y = parent.Y + tab[i].Y;
        if ( isInGraph ( graph, successor.X, successor.Y ) ) {
            if ( getElementGraph ( graph, successor ) != wallGraph) {
                if ( dijkstra->matrix[successor.X][successor.Y].flag == white) {
                    *list = addElementList(*list, successor);
                    dijkstra->matrix[successor.X][successor.Y].flag = gray;
                    /*displayDijkstraMatrix(dijkstra, successor.X, successor.Y);*/
                    updateDistance(dijkstra, graph, parent, successor);
                }
            }
        }
    }
}

void getRoadSucc (GRAPH* graph, dijkstraMatrix* dijkstra ,LIST* list, POSITION parent) {
    POSITION successor;
    int i;
    static POSITION tab[] ={
                            {1, 0},
                            {-1, 0},
                            {0, 1},
                            {0, -1},
                            {1, 1},
                            {1, -1},
                            {-1, 1},
                            {-1, -1}
    };
    for (i=0; i<8; i++) {
        successor.X = parent.X + tab[i].X;
        successor.Y = parent.Y + tab[i].Y;
        if ( isInGraph ( graph, successor.X, successor.Y ) ) {
            if ( getElementGraph ( graph, successor ) != wallGraph) {
                if ( dijkstra->matrix[successor.X][successor.Y].flag == white) {
                    *list = addElementList(*list, successor);
                    dijkstra->matrix[successor.X][successor.Y].flag = gray;
                    /*displayDijkstraMatrix(dijkstra, successor.X, successor.Y);*/
                    updateDistance(dijkstra, graph, parent, successor);
                }
            }
        }
    }
}

void listGraphSucc(GRAPH* graph, dijkstraMatrix* dijkstra ,LIST* list, POSITION parent) {
    
    if (getElementGraph(graph, parent) == sandGraph) {
        getSuccSand(graph, dijkstra, list, parent);
    } else {
        getRoadSucc(graph, dijkstra, list, parent);
    }
}



void allPathDijkstra(dijkstraMatrix* dijkstra, GRAPH* graph, POSITION firstSommet) {
    /*int i;*/
    POSITION sommet;
    /*POSITION* succ;
    short sizeSucc;*/
    LIST list;
    
    list = createList();
    initDijkstraLength(dijkstra, firstSommet);
    sommet.X = firstSommet.X;
    sommet.Y = firstSommet.Y;
    list = addElementList(list, sommet);
    

    while (!isEmptyList(list)) {
        findMin(dijkstra, &sommet, list);
        listGraphSucc(graph, dijkstra, &list, sommet);
        list = removeElementListCoord(list, &sommet, &sommet);
    }
    destroyList(list);
} 

PATH_LIST givePath(dijkstraMatrix* dijkstra, GRAPH* graph, POSITION first) {
    POSITION sommet;
    PATH_LIST stack;
    POSITION finalSommet;

    allPathDijkstra ( dijkstra, graph, first );
    updateClosetFinishLine ( graph, first );
    getClosestFinishLine ( graph, &finalSommet );
    stack = createPathList();
    mergePosition(&finalSommet, &sommet);
    while( !areEqualsPosition(sommet, first) ) {
        stack = addHeadElementPathList(stack, sommet);
        getPredecessor(dijkstra, sommet.X, sommet.Y, &sommet);
    }
    return stack;
}