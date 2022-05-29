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
 * @file communicatorWithGDC.c
 * @brief This file is used to communicate with the GDC.
 * @author PICQUE Kylian <picque.kylian@ecole.ensicaen.Fr>
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.3
 * @date 05 avril 2022
 */

#include "../include/communicatorWithGDC.h"

/**
 * @brief Writes the data provided from the arguments in the matrix of the graph
 * 
 * @param graph : The GRAPH to initialize with the data provided
 * @param data : A line of data that need to be written int the map's matrix
 * @param row : the column to which this line of data belongs
 */
static void setDataGraph ( GRAPH* graph, char* data, int row );

static void setDataGraph ( GRAPH* graph, char* data, int row )
{
    int i;
    POSITION finishLinePosition;
    
    for ( i = 0; i < getWidthGraph ( graph ); i++ ) {
        if ( data[i] == wall ) {
            setElementGraph ( graph, wallGraph, i, row );
        } else if ( data[i] == road ) {
            setElementGraph ( graph, roadGraph, i, row );
        } else if ( data[i] == sand ) {
            setElementGraph ( graph, sandGraph, i, row );
        } else if ( data[i] == finishLine ) {
            setElementGraph ( graph, finishLineGraph, i, row );
            finishLinePosition.X = i;
            finishLinePosition.Y = row;
            updateCoordFinishLine ( 
                                    graph, finishLinePosition, 
                                    getSizeFinishLine ( graph ) 
                                  );
        }
    }
}

void readDataFromGDC ( short* fuelLevel, GRAPH* graph, GRAPH* referenceGraph )
{
    int i;
    short width, height;
    char buf[MAX_LINE_LENGTH];
    char* trash;

    trash = fgets ( buf, MAX_LINE_LENGTH, stdin );
    sscanf ( buf, "%hd %hd %hd", &width, &height, fuelLevel );

    *graph = createGraph ( width, height );
    *referenceGraph = createGraph ( width, height);

    for ( i = 0; i < getHeightGraph ( graph ); i++ ) {
        trash = fgets ( buf, MAX_LINE_LENGTH, stdin );
        setDataGraph ( graph, buf, i );
        setDataGraph ( referenceGraph, buf, i );
    }
    trash = trash;
}

void updatePositionPilotFromGDC ( 
                                    POSITION* myPilot, 
                                    POSITION* secondPilot, 
                                    POSITION* thirdPilot 
                                )
{
    char buf[MAX_LINE_LENGTH];
    char* trash;

    trash = fgets ( buf, MAX_LINE_LENGTH, stdin );
    sscanf ( buf, "%hd %hd %hd %hd %hd %hd",
                    &(myPilot->X),          &(myPilot->Y),
                    &(secondPilot->X),      &(secondPilot->Y),
                    &(thirdPilot->X),       &(thirdPilot->Y)
            );
    trash = trash;
}

void deliverAction ( ACCELERATION actionToDeliver )
{
    fprintf ( stdout, "%hd %hd", actionToDeliver.X, actionToDeliver.Y );
    fflush ( stdout );                /* CAUTION : This is necessary  */
}