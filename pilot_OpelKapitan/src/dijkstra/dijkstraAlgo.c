/*
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
 * @author PICQUE Kylian <picque.kylian@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 2.5.0
 * @date 29 avril 2022
 */

#include "../../include/dijkstra/dijkstraAlgo.h"
#include "../../include/direction/pilotDirection.h"
#include "../../include/direction/straightAction.h"

/**
 * @brief Set result's values to reference.
 * 
 * @param reference The reference position.
 * @param result The result position.
 */
static void mergePosition ( POSITION* reference, POSITION* result );


/**
 * @brief Initialize the dijkstra matrix. It add the max value for every lenght(to simulate the infinity)
 * 
 * @param dijkstra The dijkstra matrix. Already created. 
 * @param firstNode Coordinates of the firstNode position.  
 */
static void initDijkstra ( DIJKSTRA* dijkstra, POSITION firstNode);


/**
 * @brief Find the position with the fewer length for a successors of positions. 
 * 
 * @param dijkstra The dijkstra matrix. Place where are stocked position's length. 
 * @param currentNode The current node to test. 
 * @param list the list of successor.
 */
static void findNodeWithMinimalLength ( DIJKSTRA* dijkstra, POSITION* currentNode, LIST list );


/**
 * @brief Give the arc value between a node and one of this successors.
 * 
 * @param graph The graph of the race map. Is used the inform about the value of the arc.
 * @param dijkstra The DIJKSTRA object.
 * @param currentNode The node which is studied.
 * @param successorNode A currentNode's successor. 
 * @return short The value of the arc.
 */
static short getArcValue ( GRAPH* graph, DIJKSTRA* dijkstra,POSITION currentNode, POSITION successorNode );


/**
 * @brief Change a node's length thanks to the predecessor's length add whith the arc's value.
 * The length changes if the new length is fewer.
 * 
 * @param dijkstra The Dijkstra matrice. Where are stokes nodes's length
 * @param graph The graph of the race map.
 * @param currentNode The node which is studied.
 * @param successorNode A currentNode's successor.
 */
static void updateLengthNode( DIJKSTRA* dijkstra, GRAPH* graph, POSITION currentNode, POSITION successorNode);


/**
 * @brief Stock in the list all successors which are not visited yet and could be visited (road or sand) of the current node
 * 
 * @param graph The graph of the race map. Give the type of nodes.
 * @param dijkstra The Dijkstra matrice.
 * @param list A list of node accissible but not visited yet.
 * @param currentNode The node which is studied. A sand node
 */
static void processSuccessorsSand ( GRAPH*graph, DIJKSTRA* dijkstra ,LIST* list, POSITION currentNode );


/**
 * @brief Stock in the list all successors which are not visited yet and could be visited (road or sand) of the current node.
 * 
 * @param graph The graph of the race map. Give the type of nodes.
 * @param dijkstra The Dijkstra matrice.
 * @param list A list of node accissible but not visited yet.
 * @param currentNode The node which is studied. A road node.
 */
static void processSuccessorRoad ( GRAPH* graph, DIJKSTRA* dijkstra ,LIST* list, POSITION currentNode );


/**
 * @brief Redirects to stock good successorsif the current node is sand or road.
 * 
 * @param graph The graph of the race map. Give the type of nodes.
 * @param dijkstra The Dijkstra matrice.
 * @param list A list of node accissible but not visited yet.
 * @param nodeToProcess The current node.
 */
static void redirectorToProcessSuccessor ( GRAPH* graph, DIJKSTRA* dijkstra ,LIST* list, POSITION nodeToProcess );


/**
 * @brief Execute the Dijkstra algorthm and fill the dijkstra matrix.
 * 
 * @param dijkstra The Dijkstra matrice. Juste created.
 * @param graph The graph of the race map.
 * @param firstNode The position of the pilot. The first node visited
 */
static void executeDijkstra ( DIJKSTRA* dijkstra, GRAPH* graph, POSITION firstNode );


static void mergePosition ( POSITION* reference, POSITION* result ) 
{
    result->X = reference->X;
    result->Y = reference->Y;   
}

static void initDijkstra ( DIJKSTRA* dijkstra, POSITION firstNode ) 
{
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
    setPredecessor ( dijkstra, firstNode.X, firstNode.Y, firstNode );
    setFlag ( dijkstra, firstNode, gray );
}


static void findNodeWithMinimalLength ( DIJKSTRA* dijkstra, POSITION* currentNode, LIST list ) 
{
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

static short getArcValue ( GRAPH* graph, DIJKSTRA* dijkstra,POSITION currentNode, POSITION successorNode )
{
    short arcValue;
    POSITION pred;

    getPredecessor ( dijkstra, currentNode.X, currentNode.Y, &pred );
    arcValue = (short)getElementGraph ( graph, successorNode);
    if ( isSand ( graph, successorNode ) ) {
        arcValue += 1;
    }
    if ( !areAligned ( currentNode, pred, successorNode ) ) {
        arcValue += 1;
    }
    arcValue += abs((currentNode.X - successorNode.X)) + abs((currentNode.Y - successorNode.Y));
    return arcValue;
}

static void updateLengthNode ( DIJKSTRA* dijkstra, GRAPH* graph, POSITION currentNode, POSITION successorNode )
{
    short d1;
    short d2;
    short arcValue;

    d1 = getPathLength(dijkstra, currentNode.X, currentNode.Y);
    d2 = getPathLength(dijkstra, successorNode.X, successorNode.Y);
    arcValue = getArcValue ( graph, dijkstra, currentNode, successorNode );
    if ( d2 > (d1 + arcValue) ) {
        setPathLength(dijkstra, successorNode.X, successorNode.Y, (d1 + arcValue));
        setPredecessor(dijkstra, successorNode.X, successorNode.Y, currentNode);
        return;
    }
}


static void processSuccessorsSand ( GRAPH*graph, DIJKSTRA* dijkstra ,LIST* list, POSITION currentNode ) 
{
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
                    updateLengthNode(dijkstra, graph, currentNode, successor);
                }
            }
        }
    }
}

static void processSuccessorRoad ( GRAPH* graph, DIJKSTRA* dijkstra ,LIST* list, POSITION currentNode ) 
{
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

static void redirectorToProcessSuccessor ( GRAPH* graph, DIJKSTRA* dijkstra ,LIST* list, POSITION nodeToProcess ) 
{
    if (isSand ( graph, nodeToProcess )) {
        processSuccessorsSand(graph, dijkstra, list, nodeToProcess );
    } else {
        processSuccessorRoad(graph, dijkstra, list, nodeToProcess );
    }
}

static void executeDijkstra ( DIJKSTRA* dijkstra, GRAPH* graph, POSITION firstNode ) 
{
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

PATH_LIST pathToFollow ( DIJKSTRA* dijkstra, GRAPH* graph, POSITION firstNode ) 
{
    POSITION sommet;
    PATH_LIST stack;
    POSITION finalSommet;

    executeDijkstra ( dijkstra, graph, firstNode );

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