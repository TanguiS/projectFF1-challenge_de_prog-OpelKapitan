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

#define INIT_SIZE 0

static void setWidthGraph ( GRAPH* graph, short width );

static void setHeightGraph ( GRAPH* graph, short height );

static void setSizeFinishLine ( GRAPH* graph, char size );

static void initGraph ( GRAPH* graph , short width, short height );

static void addCoordFinishline ( GRAPH* graph, coord newCoord, int index );

static void setClosestFinishLine ( GRAPH* graph, coord closestFinishLine );

static boolean competitorIsClosest ( GRAPH* graph, coord pilot, coord competitor );

static int length ( coord first, coord secound );

static void setElementToGraph ( GRAPH* graph, element value, int x, int y );

static void setElementToGraph ( GRAPH* graph, element value, int x, int y )
{
    graph->graph[x][y] = value;
}

static int length ( coord first, coord secound )
{
    return ( ( ( first[0] - secound[0] ) * ( first[0] - secound[0] ) ) + ( ( first[1] - secound[1] ) * ( first[1] - secound[1] ) ) );
}

static boolean competitorIsClosest ( GRAPH* graph, coord pilot, coord competitor )
{
    coord closest;
    int lengthClosest;
    int lengthCompetitor;
    getClosestFinishLine ( graph, &closest );
    lengthClosest = length ( pilot, closest );
    lengthCompetitor = length ( pilot, competitor );
    DEBUG_INT ( ">Debug longueur competitor : ", lengthCompetitor );
    return ( lengthClosest > lengthCompetitor );
}

static void setSizeFinishLine ( GRAPH* graph, char size )
{
    graph->sizeFinishLine = size;
}

static void setClosestFinishLine ( GRAPH* graph, coord closestFinishLine )
{
    graph->closestFinishLine[0] = closestFinishLine[0];
    graph->closestFinishLine[1] = closestFinishLine[1];
}

static void setWidthGraph ( GRAPH* graph, short width )
{
    graph->width = width;
}

static void setHeightGraph ( GRAPH* graph, short height )
{
    graph->height = height;
}
static void addCoordFinishline ( GRAPH* graph, coord newCoord, int index )
{
    graph->finishLineCoord[index][0] = newCoord[0];
    graph->finishLineCoord[index][1] = newCoord[1];
}

static void initGraph ( GRAPH* graph, short width, short height )
{
    coord init = {SHRT_MAX, SHRT_MAX};
    setWidthGraph ( graph, width );
    setHeightGraph ( graph, height );
    setSizeFinishLine ( graph, INIT_SIZE );
    setClosestFinishLine ( graph, init );
}

#ifndef DEBUG
void displayGraph ( GRAPH* graph )
{
    int i, j;
    coord line;
    DEBUG_CHAR ( "\nAffichage du graph : ", ' ' );
    for ( i = 0; i < getHeightGraph ( graph ); i++ ) {
        for ( j = 0; j < getWidthGraph ( graph ); j++ ) {
            DEBUG_ONLY_INT ( getElementGraph ( graph, j, i ) );
        }
        DEBUG_ONLY_CHAR ( '\n' );
    }
    DEBUG_CHAR ( "\nAffichage coord ligne d'arrivée : ", ' ' );
    DEBUG_INT ( ">Taille ligne : ", getSizeFinishLine ( graph ) );
    for ( i = 0; i < getSizeFinishLine ( graph ); i++ ) {
        DEBUG_ONLY_CHAR ( '[' );
        getCoordFinishLine ( graph, i, &line );
        DEBUG_ONLY_INT ( line[0] );
        DEBUG_ONLY_CHAR ( ',' );
        DEBUG_ONLY_INT ( line[1] );
        DEBUG_ONLY_CHAR ( ']' );
    }
    DEBUG_ONLY_CHAR ( '\n' );
    DEBUG_CHAR ( ">Coord le plus proche de notre voiture : ", ' ' );
    DEBUG_ONLY_CHAR ( '[' );
    getClosestFinishLine ( graph, &line );
    DEBUG_ONLY_INT ( line[0] );
    DEBUG_ONLY_CHAR ( ',' );
    DEBUG_ONLY_INT ( line[1] );
    DEBUG_ONLY_CHAR ( ']' );
    DEBUG_ONLY_CHAR ( '\n' );
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

char getSizeFinishLine ( GRAPH* graph )
{
    return graph->sizeFinishLine;
}

void getCoordFinishLine ( GRAPH* graph, short index, coord* result )
{
    result[0][0] = graph->finishLineCoord[index][0];
    result[0][1] = graph->finishLineCoord[index][1];
}

void getClosestFinishLine ( GRAPH* graph, coord* result )
{
    result[0][0] = graph->closestFinishLine[0];
    result[0][1] = graph->closestFinishLine[1];
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
    for ( i = 0; i < newGraph.width; i++ ) {
        newGraph.graph[i] = ( element* ) malloc ( newGraph.height * sizeof ( element ) );
    }
    return newGraph;   
}

void updateCoordFinishLine ( GRAPH* graph, coord newFinishLine, int index )
{
    setSizeFinishLine ( graph, getSizeFinishLine ( graph ) + 1 );
    addCoordFinishline ( graph, newFinishLine, index );
}

void updateGraph ( GRAPH* graph, coord myPilot, coord secoundPilot, coord thirdPilot )
{
    int i;
    coord competitor;
    setElementToGraph ( graph, carGraph, secoundPilot[0], secoundPilot[1] );
    setElementToGraph ( graph, carGraph, thirdPilot[0], thirdPilot[1] );
    for ( i = 0; i < getSizeFinishLine ( graph); i++ ) {
        getCoordFinishLine ( graph, i, &competitor );
        if ( competitorIsClosest ( graph, myPilot, competitor ) ) {
            setClosestFinishLine ( graph, competitor );
        }
    }
}



void destroyGraph(GRAPH graph) {
    int i;

    for (i=0; i<graph.width; i++) {
        free(graph.graph[i]);
    }
    free(graph.graph);
}