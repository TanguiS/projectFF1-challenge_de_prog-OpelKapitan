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
            dijkstraMatrix->matrix[j][i].flag = white;
        }
    }
    setPathLength ( dijkstraMatrix, x, y, 0 );
    dijkstraMatrix->matrix[x][y].flag = black;
    displayDijkstraMatrix ( dijkstraMatrix, -1, -1 );
}



void findMin(dijkstraMatrix* dijkstra, coord* sommet, LIST list ) {
    /*short min = SHRT_MAX;*/
    short i;
    /*short sizeSucc;
    int distance;*/
    coord minTemp;

    i = getElementList(list, sommet, 0);
    mixeCoord(sommet, &minTemp);
    while (i) {
        i = getNextElementList(list, &minTemp, &minTemp);
        if (getPathLength(dijkstra, sommet[0][0], sommet[0][1]) > getPathLength(dijkstra, minTemp[0], minTemp[1])) {
            mixeCoord(&minTemp, sommet);
        }
    }
    
    /*
    sommet[0][0] = -1;
    sommet[0][1] = -1;   
    sizeSucc = succ[0][0];

    for (i=1; i<sizeSucc; i++) { 
        distance = (short) getElementGraph(graph, succ[i][0], succ[i][1]);
        if ( distance < min && dijkstra->matrix[succ[i][0]][succ[i][1]].flag == false ) {       succ is not visited 
            min = distance;
            mixeCoord(&(succ[i]), sommet);
        }
    }
    if ( sommet[0][1] == -1 ) {
        return;
    }*/
    dijkstra->matrix[sommet[0][0]][sommet[0][1]].flag = black;
    displayDijkstraMatrix ( dijkstra, sommet[0][0], sommet[0][1] );
}

void updateDistance(dijkstraMatrix* dijkstra, GRAPH* graph, coord sommet1, coord sommet2) {
    short d1;
    short d2;
    short arcValue;

    d1 = getPathLength(dijkstra, sommet1[0], sommet1[1]);
    d2 = getPathLength(dijkstra, sommet2[0], sommet2[1]);
    arcValue = (short)getElementGraph(graph, sommet2[0], sommet2[1]);

    if ( d2 > (d1 + arcValue) ) {
        setPathLength(dijkstra, sommet2[0], sommet2[1], (d1 + arcValue));
        setPredecessor(dijkstra, sommet2[0], sommet2[1], sommet1);
        displayDijkstraMatrix ( dijkstra, sommet2[0], sommet2[1] );
        return;
    }
    displayDijkstraMatrix ( dijkstra, sommet1[0], sommet1[1] );

}


void addSuccessorListe(LIST* list, coord* succ, coord sommet,  short sizeSucc, dijkstraMatrix* dijkstra, GRAPH* graph) {
    int j;

    for (j=1; j<sizeSucc; j++) {
        if ( dijkstra->matrix[succ[j][0]][succ[j][1]].flag == white ) {
            updateDistance(dijkstra, graph, sommet, succ[j]);
            *(list) = addElementList(*(list), succ[j]);
            dijkstra->matrix[succ[j][0]][succ[j][1]].flag = gray;
            displayDijkstraMatrix(dijkstra, succ[j][0], succ[j][1]);
        }
        
    }
    

}


void allPathDijkstra(dijkstraMatrix* dijkstra, GRAPH* graph, coord firstSommet) {
    int i;
    coord sommet;
    coord* succ;
    short sizeSucc;
    LIST list;
    
    list = createList();
    initDijkstraLenght(dijkstra, firstSommet[0], firstSommet[1]);
    sommet[0] = firstSommet[0];
    sommet[1] = firstSommet[1];
    list = addElementList(list, sommet);
    /*
    succ = getSuccessorGraph(graph, sommet[0], sommet[1]);
    sizeSucc = succ[0][0];
    addSuccessorListe(&list, succ, sommet, sizeSucc, dijkstra, graph);*/
    

    while (!isEmptyList(list)) {
        succ = getSuccessorGraph(graph, sommet[0], sommet[1]);
        sizeSucc = succ[0][0];
        for (i=1; i<sizeSucc; i++) {
            if ( dijkstra->matrix[succ[i][0]][succ[i][1]].flag == white ) {
                /*updateDistance(dijkstra, graph, sommet, succ[i]);*/
                list = addElementList(list, succ[i]);
                dijkstra->matrix[succ[i][0]][succ[i][1]].flag = gray;
                displayDijkstraMatrix(dijkstra, sommet[0], sommet[1]);
            } 
            updateDistance(dijkstra, graph, sommet, succ[i]);
        }
        list = removeElementList(list, &sommet);
        findMin(dijkstra, &sommet, list);
        
        free ( succ );
    }
    destroyList(list);
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
    displayDijkstraMatrix ( dijkstra, -1, -1 );
    stack = createLifo();
    mixeCoord(&finalSommet, &sommet);
    while( !sameCoord(sommet, firstSommet) ) {
        stack = addElementLifo(stack, sommet);
        getPredecessor(dijkstra, sommet[0], sommet[1], &sommet);
    }
    stack = addElementLifo(stack, firstSommet);
    return stack;
}