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

/**
 * @brief Set the Size Finish Line object
 * 
 * @param graph 
 * @param size 
 */
static void setSizeFinishLine ( GRAPH* graph, char size );

/**
 * @brief Initialize the graph
 * 
 * @param graph 
 */
static void initGraph ( GRAPH* graph );

/**
 * @brief Add a position to the finish lines
 * 
 * @param graph 
 * @param coord 
 * @param index 
 */
static void addCoordFinishline ( GRAPH* graph, POSITION coord, int index );

/**
 * @brief Set the Closest Finish Line object
 * 
 * @param graph 
 * @param closestFinishLine 
 */
static void setClosestFinishLine ( GRAPH* graph, POSITION closestFinishLine );

/**
 * @brief 
 * 
 * @param graph 
 * @param pilot 
 * @param competitor 
 * @return boolean 
 */
static boolean competitorIsClosestToFinish ( GRAPH* graph, POSITION pilot, POSITION competitor );

/**
 * @brief 
 * 
 * @param first 
 * @param secound 
 * @return int 
 */
static int length ( POSITION first, POSITION secound );

static int length ( POSITION first, POSITION secound )
{
    return ( ( ( first.X - secound.X ) * ( first.X - secound.X ) ) + ( ( first.Y - secound.Y ) * ( first.Y - secound.Y ) ) );
}

static boolean competitorIsClosestToFinish ( GRAPH* graph, POSITION pilot, POSITION competitor )
{
    POSITION closest;
    int lengthClosest;
    int lengthCompetitor;
    getClosestFinishLine ( graph, &closest );
    lengthClosest = length ( pilot, closest );
    lengthCompetitor = length ( pilot, competitor );
    return ( lengthClosest > lengthCompetitor );
}

static void setSizeFinishLine ( GRAPH* graph, char size )
{
    graph->sizeFinishLine = size;
}

static void setClosestFinishLine ( GRAPH* graph, POSITION closestFinishLine )
{
    graph->closestFinishLine.X = closestFinishLine.X;
    graph->closestFinishLine.Y = closestFinishLine.Y;
}

static void addCoordFinishline ( GRAPH* graph, POSITION coord, int index )
{
    graph->finishLineCoord[index].X = coord.X;
    graph->finishLineCoord[index].Y = coord.Y;
}

static void initGraph ( GRAPH* graph )
{
    POSITION init;
    init.X = SHRT_MAX;
    init.Y = SHRT_MAX;
    setSizeFinishLine ( graph, INIT_SIZE );
    setClosestFinishLine ( graph, init );
}

#ifndef DEBUG
void displayGraph ( GRAPH* graph )
{
    int i, j;
    POSITION line;
    POSITION tmp;
    DEBUG_CHAR ( "\nAffichage du graph : ", ' ' );
    DEBUG_INT ( "width graph : ", getWidthGraph ( graph ) );
    DEBUG_INT ( "height graph : ", getHeightGraph ( graph ) );
    for ( i = 0; i < getHeightGraph ( graph ); i++ ) {
        for ( j = 0; j < getWidthGraph ( graph ); j++ ) {
            tmp.X = j;
            tmp.Y = i;
            DEBUG_ONLY_INT ( getElementGraph ( graph, tmp ) );
        }
        DEBUG_ONLY_CHAR ( '\n' );
    }
    DEBUG_CHAR ( "\nAffichage POSITION ligne d'arrivée : ", ' ' );
    DEBUG_INT ( ">Taille ligne : ", getSizeFinishLine ( graph ) );
    for ( i = 0; i < getSizeFinishLine ( graph ); i++ ) {
        DEBUG_ONLY_CHAR ( '[' );
        getCoordFinishLine ( graph, i, &line );
        DEBUG_ONLY_INT ( line.X );
        DEBUG_ONLY_CHAR ( ',' );
        DEBUG_ONLY_INT ( line.Y );
        DEBUG_ONLY_CHAR ( ']' );
    }
    DEBUG_ONLY_CHAR ( '\n' );
    DEBUG_CHAR ( ">POSITION le plus proche de notre voiture : ", ' ' );
    DEBUG_ONLY_CHAR ( '[' );
    getClosestFinishLine ( graph, &line );
    DEBUG_ONLY_INT ( line.X );
    DEBUG_ONLY_CHAR ( ',' );
    DEBUG_ONLY_INT ( line.Y );
    DEBUG_ONLY_CHAR ( ']' );
    DEBUG_ONLY_CHAR ( '\n' );
}
#endif

short getWidthGraph ( GRAPH* graph )
{
    return getWidthMatrix ( &(graph->graph) );
}

short getHeightGraph ( GRAPH* graph )
{
    return getHeightMatrix ( &(graph->graph) );
}

char getSizeFinishLine ( GRAPH* graph )
{
    return graph->sizeFinishLine;
}

void getCoordFinishLine ( GRAPH* graph, short index, POSITION* result )
{
    result->X = graph->finishLineCoord[index].X;
    result->Y = graph->finishLineCoord[index].Y;
}

void getClosestFinishLine ( GRAPH* graph, POSITION* result )
{
    result->X = graph->closestFinishLine.X;
    result->Y = graph->closestFinishLine.Y;
}

element getElementGraph ( GRAPH* graph, POSITION coord )
{
    return getElementMatrix ( &(graph->graph), coord.X, coord.Y );
}

boolean isSand ( GRAPH* graph, POSITION coord )
{
    return getElementGraph ( graph, coord ) == sandGraph;
}

boolean isRoad ( GRAPH* graph, POSITION coord )
{
    return getElementGraph ( graph, coord ) == roadGraph;
}

boolean isCar ( GRAPH* graph, POSITION coord )
{
    return getElementGraph ( graph, coord ) == carGraph;
}

boolean isWall ( GRAPH* graph, POSITION coord )
{
    return getElementGraph ( graph, coord ) == wallGraph;
}

boolean isInGraph ( GRAPH* graph, short x, short y )
{
    if ( x >= getWidthGraph ( graph ) ) {
        return false;
    }
    if ( y >= getHeightGraph ( graph ) ) {
        return false;
    }
    if ( x < 0 ) {
        return false;
    }
    if ( y < 0 ) {
        return false;
    }
    return true;
}

static boolean areNotEqualsZero ( short x, short y )
{
    if ( x != 0 ) {
        return true;
    }
    if ( y != 0 ) {
        return true;
    }
    return false;
}


POSITION* getSuccessorGraph ( GRAPH* graph, POSITION parent )
{
    /*
    POSITION* successor;
    int count = 1;
    int tab[3] = {-1, 0, 1};
    int tabd[2] = {-1, 1};
    int i, j;
    successor = (POSITION*) malloc ( ( NUMBER_CASES_AROUND + 1 ) * sizeof ( POSITION ) );
    for ( i = 0; i < 3; i++ ) {
        if ( isInGraph ( graph, parent.X, parent.Y + tab[i] ) ) {
                successor[count].X = parent.X ;
                successor[count].Y = parent.Y + tab[i];
            if ( getElementGraph ( graph, successor[count] ) != wallGraph ) {
                count++;                    
            }
        }
        if ( isInGraph ( graph, parent.X + tab[i], parent.Y ) ) {
                successor[count].X = parent.X + tab[i];
                successor[count].Y = parent.Y;
            if ( getElementGraph ( graph, successor[count] ) != wallGraph ) {
                count++;                    
            }
        }
    }
    for ( i = 0; i < 2; i++ ) {
        for ( j = 0; j < 2; j++ ) {
            if ( isInGraph ( graph, parent.X + tabd[j], parent.Y + tabd[i] ) ) {
                    successor[count].X = parent.X + tabd[j];
                    successor[count].Y = parent.Y + tabd[i];
                if ( getElementGraph ( graph, successor[count] ) != wallGraph ) {
                    count++;                    
                }
            }
        }
    }
    successor[0].X = count;
    return successor;
    */

   POSITION* successor;
    int count = 1;
    int tab[3] = {-1, 0, 1};
    int i, j;
    successor = (POSITION*) malloc ( ( NUMBER_CASES_AROUND + 1 ) * sizeof ( POSITION ) );
    for ( i = 0; i < 3; i++ ) {
        for ( j = 0; j < 3; j++ ) {
            if ( isInGraph ( graph, parent.X + tab[j], parent.Y + tab[i] ) ) {
                    successor[count].X = parent.X + tab[j];
                    successor[count].Y = parent.Y + tab[i];
                if ( getElementGraph ( graph, successor[count] ) != wallGraph ) {
                    count++;                    
                }
            }
        }
    }
    successor[0].X = count;
    return successor;
}
 





void setElementGraph ( GRAPH* graph, element value, short x, short y )
{
    setElementMatrix ( &(graph->graph), x, y, value );
}

GRAPH createGraph ( short width, short height )
{
    GRAPH newGraph;
    initGraph ( &newGraph );
    newGraph.graph = createMatrix ( width, height );
    return newGraph;   
}

void updateCoordFinishLine ( GRAPH* graph, POSITION newFinishLine, int index )
{
    setSizeFinishLine ( graph, getSizeFinishLine ( graph ) + 1 );
    addCoordFinishline ( graph, newFinishLine, index );
}

void updateGraph ( GRAPH* graph, POSITION myPilot, POSITION secoundPilot, POSITION thirdPilot )
{
    int i;
    POSITION competitor;
    static POSITION rounder[] = {
                            { 1, 0 },
                            { -1, 0 },
                            { 0, 1 },
                            { 0, -1 }
    };

    for ( i = 0; i < 4; i++ ) {
        if ( isInGraph ( graph, secoundPilot.X + rounder[i].X, secoundPilot.Y + rounder[i].Y ) ) {
            setElementGraph ( graph, aroundCarGraph, secoundPilot.X + rounder[i].X, secoundPilot.Y + rounder[i].Y );
        }
        if ( isInGraph ( graph, thirdPilot.X + rounder[i].X, thirdPilot.Y + rounder[i].Y ) ) {
            setElementGraph ( graph, aroundCarGraph, thirdPilot.X + rounder[i].X, thirdPilot.Y + rounder[i].Y );
        }
    }
    setElementGraph ( graph, carGraph, secoundPilot.X, secoundPilot.Y );
    setElementGraph ( graph, carGraph, thirdPilot.X, thirdPilot.Y );

    for ( i = 0; i < getSizeFinishLine ( graph); i++ ) {
        getCoordFinishLine ( graph, i, &competitor );
        if ( competitorIsClosestToFinish ( graph, myPilot, competitor ) ) {
            setClosestFinishLine ( graph, competitor );
        }
    }
}

void reverseGraph ( GRAPH* graph, POSITION previousSecoundPilot, POSITION previousThirdPilot )
{
    int i;
    static POSITION rounder[] = {
                            { 1, 0 },
                            { -1, 0 },
                            { 0, 1 },
                            { 0, -1 },
                            { 0, 0 }
    };

    for ( i = 0; i < 5; i++ ) {
        if ( isInGraph ( graph, previousSecoundPilot.X + rounder[i].X, previousSecoundPilot.Y + rounder[i].Y ) ) {
            setElementGraph ( graph, roadGraph, previousSecoundPilot.X + rounder[i].X, previousSecoundPilot.Y + rounder[i].Y );
        }
        if ( isInGraph ( graph, previousThirdPilot.X + rounder[i].X, previousThirdPilot.Y + rounder[i].Y ) ) {
            setElementGraph ( graph, roadGraph, previousThirdPilot.X + rounder[i].X, previousThirdPilot.Y + rounder[i].Y );
        }
    }
}



void destroyGraph(GRAPH graph) {
    destroyMatrix ( graph.graph );
}