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
 * @version 1.0.1
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

#ifndef DEBUG
/**
 * @brief Only for Debugging purposes
 * 
 * @param map 
 */
static void displayMap ( DATA_MAP map );
#endif

static void setDataMapGraph ( DATA_MAP* map, GRAPH* graph, char* data, int row )
{
    int i;
    coord coordFinishLine;
    
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
            coordFinishLine[0] = i;
            coordFinishLine[1] = row;
            updateCoordFinishLine ( graph, coordFinishLine, getSizeFinishLine ( graph ) );

        }
    }
}

#ifndef DEBUG
static void displayMap ( DATA_MAP map )
{
    int i, j;
    DEBUG_CHAR ( "\nAffichage de la map avec matrix: ", ' ' );
    for ( i = 0; i < getHeightMap ( &map ); i++ ) {
        for ( j = 0; j < getWidthMap ( &map ); j++ ) {
            DEBUG_ONLY_CHAR ( getElementMap ( &map, j, i ) );
        }
        DEBUG_ONLY_CHAR ( '\n' );
    }
}
#endif

DATA_MAP createMap ( short newWidth, short newHeight )
{
    DATA_MAP map;
    map = createMatrix ( newWidth, newHeight );
    return map;
}

DATA_MAP readDataMapGraph ( short* gasLvl, GRAPH* graph )
{
    DATA_MAP map;
    int i;
    short width, height;
    char buf[MAX_LINE_LENGTH];

    fgets ( buf, MAX_LINE_LENGTH, stdin );
    sscanf ( buf, "%hd %hd %hd", &width, &height, gasLvl );

    DEBUG_CHAR ( "=== > Lecture des Data < ===", ' ' );
    DEBUG_INT ( "Valeur de width : ", (int) width ); 
    DEBUG_INT ( "Valeur de height : ", (int) height ); 
    DEBUG_INT ( "Valeur de gasLvl : ", (int) *gasLvl );

    map = createMap ( width, height );
    *graph = createGraph ( width, height );

    for ( i = 0; i < getHeightMap ( &map ); i++ ) {
        fgets ( buf, MAX_LINE_LENGTH, stdin );
        setDataMapGraph ( &map, graph, buf, i );
    }
    #ifndef DEBUG
        displayMap ( map );
    #endif
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

short getElementMap ( DATA_MAP* map, int x, int y )
{
   return getElementMatrix ( map, x, y );
}

boolean destroyMap ( DATA_MAP map )
{
    destroyMatrix ( map );
    return true;
}