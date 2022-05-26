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
#include "pilotDirection.h"


void mergePosition (POSITION* reference, POSITION* result ) {
    result->X = reference->X;
    result->Y = reference->Y;   
}

void initDijkstra(DIJKSTRA* dijkstra, POSITION firstNode/*, POSITION parentNode*/) {
    int i;
    int j;
    POSITION tmp;

    for (i=0; i<getHeigthDijkstra(dijkstra); i++) {
        for (j=0; j<getWidthDijkstra(dijkstra); j++) {
            setPathLength ( dijkstra, j, i, SHRT_MAX );
            tmp.X = j;
            tmp.Y = i;
            setFlag ( dijkstra, tmp, white );
        }
    }
    setPathLength ( dijkstra, firstNode.X, firstNode.Y, 0 );
    /*setPredecessor ( dijkstra, firstNode.X, firstNode.Y, parentNode);*/
    setFlag ( dijkstra, firstNode, gray );
}




void findNodeWithMinimalLength(DIJKSTRA* dijkstra, POSITION* currentNode, LIST list ) {
    short i;
    POSITION minTemp;

    i = getElementList(list, currentNode, 0);
    mergePosition(currentNode, &minTemp);
    while (i) {
        i = getNextElementList(list, &minTemp, &minTemp);
        if (getPathLength(dijkstra, currentNode->X, currentNode->Y) > getPathLength(dijkstra, minTemp.X, minTemp.Y)) {
            mergePosition(&minTemp, currentNode);
        }
    }
    setFlag ( dijkstra, *currentNode, black );
}

short getArcValue ( DIJKSTRA* dijkstra, GRAPH* graph, POSITION currentNode, POSITION successorNode )
{
    short arcValue /*= 0*/;
    /*POSITION parentNode;
    getPredecessor ( dijkstra, currentNode.X, currentNode.Y, &parentNode );*/

    arcValue = (short)getElementGraph ( graph, successorNode);
    arcValue += abs((currentNode.X - successorNode.X)) + abs((currentNode.Y - successorNode.Y)) - 1 ;
    /*  
    if ( isSand ( graph, successorNode ) ) {
        arcValue += 4;
    } else if ( isAroundCar ( graph, successorNode ) ) {
        arcValue += 3;
    } else if ( isRoad ( graph, successorNode ) ) {
        arcValue += 1;
    }
    if ( !areAligned ( parentNode, currentNode, successorNode ) ) {
        arcValue += 1;
    } else if ( lineToFollow ( parentNode, successorNode ) == diagonal ) {
        arcValue += 1;
    }*/
    return arcValue;
}

void updateLengthNode(DIJKSTRA* dijkstra, GRAPH* graph, POSITION currentNode, POSITION successorNode) {
    short d1;
    short d2;
    short arcValue;

    d1 = getPathLength(dijkstra, currentNode.X, currentNode.Y);
    d2 = getPathLength(dijkstra, successorNode.X, successorNode.Y);
    arcValue = getArcValue ( dijkstra, graph, currentNode, successorNode );
    if ( d2 > (d1 + arcValue) ) {
        setPathLength(dijkstra, successorNode.X, successorNode.Y, (d1 + arcValue));
        setPredecessor(dijkstra, successorNode.X, successorNode.Y, currentNode);
        /*displayDijkstraMatrix ( dijkstra, sommet2.X, sommet2.Y );*/
        return;
    }
   /* displayDijkstraMatrix ( dijkstra, sommet1.X, sommet1.Y );*/
}


void processSuccessorsSand (GRAPH*graph, DIJKSTRA* dijkstra ,LIST* list, POSITION currentNode ) {
    POSITION successor;
    int i;
    static POSITION tab[] ={
                            {1, 0},
                            {-1, 0},
                            {0, 1},
                            {0, -1}
    };
    for (i=0; i<4; i++) {
        successor.X = currentNode.X + tab[i].X;
        successor.Y = currentNode.Y + tab[i].Y;
        if ( isInGraph ( graph, successor.X, successor.Y ) ) {
            if ( getElementGraph ( graph, successor ) != wallGraph) {
                if ( dijkstra->matrix[successor.X][successor.Y].flag == white) {
                    *list = addElementList(*list, successor);
                    dijkstra->matrix[successor.X][successor.Y].flag = gray;
                    /*displayDijkstraMatrix(dijkstra, successor.X, successor.Y);*/
                    updateLengthNode(dijkstra, graph, currentNode, successor);
                }
            }
        }
    }
}

void processSuccessorRoad (GRAPH* graph, DIJKSTRA* dijkstra ,LIST* list, POSITION currentNode ) {
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
        successor.X = currentNode.X + tab[i].X;
        successor.Y = currentNode.Y + tab[i].Y;
        if ( isInGraph ( graph, successor.X, successor.Y ) ) {
            if ( !isWall ( graph, successor ) ) {
                if ( isNodeWhite ( dijkstra, successor ) ) {
                    *list = addElementList(*list, successor);
                    setFlag ( dijkstra, successor, gray );
                    updateLengthNode(dijkstra, graph, currentNode, successor );
                }
            }
        }
    }
}

void redirectorToProcessSuccessor(GRAPH* graph, DIJKSTRA* dijkstra ,LIST* list, POSITION nodeToProcess ) {
    
    if (isSand ( graph, nodeToProcess )) {
        processSuccessorsSand(graph, dijkstra, list, nodeToProcess );
    } else {
        processSuccessorRoad(graph, dijkstra, list, nodeToProcess );
    }
}



void executeDijkstra(DIJKSTRA* dijkstra, GRAPH* graph, POSITION firstNode/*, POSITION parentNode*/) {
    POSITION currentNode;
    LIST list;
    
    list = createList();
    initDijkstra(dijkstra, firstNode);
    currentNode.X = firstNode.X;
    currentNode.Y = firstNode.Y;
    list = addElementList(list, currentNode);
    

    while (!isEmptyList(list)) {
        findNodeWithMinimalLength(dijkstra, &currentNode, list);
        redirectorToProcessSuccessor(graph, dijkstra, &list, currentNode );
        list = removeElementListCoord(list, &currentNode, &currentNode);
    }
    destroyList(list);
} 

PATH_LIST pathToFollow(DIJKSTRA* dijkstra, GRAPH* graph, POSITION firstNode/*, POSITION parentNode*/ ) {
    POSITION sommet;
    PATH_LIST stack;
    POSITION finalSommet;

    executeDijkstra ( dijkstra, graph, firstNode/*, parentNode*/ );

    updateClosetFinishLine ( graph, firstNode );
    getClosestFinishLine ( graph, &finalSommet );
    stack = createPathList();
    mergePosition(&finalSommet, &sommet);
    while( !areEqualsPosition(sommet, firstNode) ) {
        stack = addHeadElementPathList(stack, sommet);
        getPredecessor(dijkstra, sommet.X, sommet.Y, &sommet);
    }
    return stack;
}