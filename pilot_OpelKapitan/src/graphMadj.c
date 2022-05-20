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
static boolean isCompetitorClosestToFinish ( GRAPH* graph, POSITION pilot, POSITION competitor );

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

static boolean isCompetitorClosestToFinish ( GRAPH* graph, POSITION pilot, POSITION competitor )
{
    POSITION closest;
    int lengthClosest;
    int lengthCompetitor;
    getClosestFinishLine ( graph, &closest );
    lengthClosest = length ( pilot, closest );
    lengthCompetitor = length ( pilot, competitor );
    fprintf ( stderr, "    Closest > competitor : %d\n", lengthClosest > lengthCompetitor );
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
    POSITION init = {SHRT_MAX, SHRT_MAX};
    setSizeFinishLine ( graph, INIT_SIZE );
    setClosestFinishLine ( graph, init );
}

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

POSITION* getSuccessorGraph ( GRAPH* graph, POSITION parent )
{
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

void updateClosetFinishLine ( GRAPH* graph, POSITION pilotPosition )
{
    int i;
    POSITION competitor;
    static POSITION tmp = {SHRT_MAX, SHRT_MAX};
    POSITION trash;
    setClosestFinishLine ( graph, tmp );
    for ( i = 0; i < (int) getSizeFinishLine ( graph ); i++ ) {
        getCoordFinishLine ( graph, i, &competitor );
        if ( isCompetitorClosestToFinish ( graph, pilotPosition, competitor ) ) {
            if ( !isCar ( graph, competitor ) ) {
                setClosestFinishLine ( graph, competitor );
            }
        }
    }
    getClosestFinishLine ( graph, &trash );
}


void updateGraph ( GRAPH* graph, POSITION secoundPilot, POSITION thirdPilot, POSITION previousSecound[5], POSITION previousThird[5] )
{
    int i;
    POSITION competitor;
    static POSITION rounder[] = {
                            { 1, 0 },
                            { -1, 0 },
                            { 0, 1 },
                            { 0, -1 }
    };
    previousSecound[0].X = secoundPilot.X;
    previousSecound[0].Y = secoundPilot.Y;
    previousThird[0].Y = thirdPilot.Y;
    previousThird[0].X = thirdPilot.X;


    for ( i = 0; i < 4; i++ ) {
        competitor.X = secoundPilot.X + rounder[i].X;
        competitor.Y = secoundPilot.Y + rounder[i].Y;
        if ( isInGraph ( graph, competitor.X, competitor.Y ) ) {
            if (isRoad(graph, competitor)){
                setElementGraph ( graph, aroundCarGraph, secoundPilot.X + rounder[i].X, secoundPilot.Y + rounder[i].Y );
                previousSecound[i+1].X = competitor.X;
                previousSecound[i+1].Y = competitor.Y;
            } else {
                previousSecound[i+1].X = -1;
                previousSecound[i+1].Y = -1;
            }
        }
        competitor.X = thirdPilot.X + rounder[i].X;
        competitor.Y = thirdPilot.Y + rounder[i].Y;
        if ( isInGraph ( graph, competitor.X, competitor.Y + rounder[i].Y ) && isRoad(graph, competitor) ) {
            setElementGraph ( graph, aroundCarGraph, thirdPilot.X + rounder[i].X, thirdPilot.Y + rounder[i].Y );
            previousThird[i+1].X = competitor.X;
            previousThird[i+1].Y = competitor.Y;
        } else {
            previousThird[i+1].X = -1;
            previousThird[i+1].Y = -1;
        }
    }
    setElementGraph ( graph, carGraph, secoundPilot.X, secoundPilot.Y );
    setElementGraph ( graph, carGraph, thirdPilot.X, thirdPilot.Y );
}

void reverseGraph ( GRAPH* graph,GRAPH* referenceGraph, POSITION previousSecound[5], POSITION previousThird[5] )
{
   int i;
   for (i=0; i<5; i++) {
       if (previousSecound[i].X != -1 && previousSecound[i].Y != -1) {
           setElementGraph ( graph, getElementGraph(referenceGraph, previousSecound[i]), previousSecound[i].X, previousSecound[i].Y );
       }
       if (previousThird[i].X != -1 && previousThird[i].Y != -1) {
           setElementGraph ( graph, getElementGraph(referenceGraph, previousThird[i]), previousThird[i].X, previousThird[i].Y );
       }
   }
}

void destroyGraph(GRAPH graph) {
    destroyMatrix ( graph.graph );
}