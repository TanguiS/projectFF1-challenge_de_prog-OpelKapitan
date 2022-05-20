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
 * @file readMap.c
 * @brief This file is the functions to read a map.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.3
 * @date 05 avril 2022
 */

#include "readMap.h"
#include "debugMode.h"

/**
 * @brief Writes the data provided from the arguments in the matrix of the map
 * 
 * @param map : The DATA_MAP to initialize with the data provided
 * @param data : A line of data that need to be written int the map's matrix
 * @param row : the column to which this line of data belongs
 */
static void setDataMapGraph ( DATA_MAP* map, GRAPH* graph, char* data, int row );

static void setDataMapGraph ( DATA_MAP* map, GRAPH* graph, char* data, int row )
{
    int i;
    POSITION finishLinePosition;
    
    for ( i = 0; i < getWidthMap ( map ); i++ ) {
        setElementMatrix ( map, i, row, data[i] );
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
            updateCoordFinishLine ( graph, finishLinePosition, getSizeFinishLine ( graph ) );
        }
    }
}

DATA_MAP createMap ( short newWidth, short newHeight )
{
    DATA_MAP map;
    map = createMatrix ( newWidth, newHeight );
    return map;
}

DATA_MAP readDataFromGDC ( short* gasLvl, GRAPH* graph, GRAPH* referenceGraph )
{
    DATA_MAP map;
    int i;
    short width, height;
    char buf[MAX_LINE_LENGTH];
    char* trash;

    trash = fgets ( buf, MAX_LINE_LENGTH, stdin );
    sscanf ( buf, "%hd %hd %hd", &width, &height, gasLvl );

    map = createMap ( width, height );
    *graph = createGraph ( width, height );
    *referenceGraph = createGraph ( width, height);

    for ( i = 0; i < getHeightMap ( &map ); i++ ) {
        trash = fgets ( buf, MAX_LINE_LENGTH, stdin );
        setDataMapGraph ( &map, graph, buf, i );
        setDataMapGraph ( &map, referenceGraph, buf, i);
    }
    trash = trash;
    return map;
}

short getWidthMap ( DATA_MAP* map )
{
    return getWidthMatrix ( map );
}

short getHeightMap ( DATA_MAP* map )
{
   return getHeightMatrix ( map );
}

short getElementMap ( DATA_MAP* map, POSITION coord )
{
   return getElementMatrix ( map, coord.X, coord.Y );
}

boolean destroyMap ( DATA_MAP map )
{
    destroyMatrix ( map );
    return true;
}