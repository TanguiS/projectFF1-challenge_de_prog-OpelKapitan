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
 * @file graph.c
 * @brief This file contains the prototypes / declarations used to choose the pilot's direction.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 19 avril 2022
 */

#include "../include/graphMadj.h"

static void setWidthGraph ( GRAPH* graph, short width );

static void setHeightGraph ( GRAPH* graph, short height );

static void initGraph ( GRAPH* graph , short width, short height );

static void setWidthGraph ( GRAPH* graph, short width )
{
    graph->width = width;
}

static void setHeightGraph ( GRAPH* graph, short height )
{
    graph->height = height;
}

static void initGraph ( GRAPH* graph, short width, short height )
{
    setWidthGraph ( graph, width );
    setHeightGraph ( graph, height );
}

#ifndef DEBUG
void displayGraph ( GRAPH* graph )
{
    int i, j;
    DEBUG_CHAR ( "\nAffichage du graph : ", ' ' );
    for ( i = 0; i < getHeightGraph ( graph ); i++ ) {
        for ( j = 0; j < getWidthGraph ( graph ); j++ ) {
            DEBUG_ONLY_INT ( getElementGraph ( graph, j, i ) );
        }
        DEBUG_ONLY_CHAR ( '\n' );
    }
}
#endif

short getWidthGraph ( GRAPH* graph )
{
    return graph->width;
}

short getHeightGraph ( GRAPH* graph )
{
    return graph->height;
}

element getElementGraph ( GRAPH* graph, short x, short y )
{
    return graph->graph[x][y];
}

GRAPH createGraph ( short width, short height )
{
    GRAPH newGraph;
    int i;
    initGraph ( &newGraph, width, height );
    newGraph.graph = ( element** ) malloc ( newGraph.width * sizeof ( element* ) );
    assert ( newGraph.graph );
    for ( i = 0; i < newGraph.width; i++ ) {
        newGraph.graph[i] = ( element* ) malloc ( newGraph.width * sizeof ( element ) );
        assert ( newGraph.graph[i] );
    }
    return newGraph;   
}