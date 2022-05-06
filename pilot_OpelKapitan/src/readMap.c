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
 * @brief Sets the value in the image object
 * 
 * @param map : The map object
 * @param newWidth : the new width of the map
 */
static void setWidthMap ( DATA_MAP* map, short newWidth );

/**
 * @brief Sets the value in the image object
 * 
 * @param map : the map object
 * @param newHeight : the new height of the map
 */
static void setHeightMap ( DATA_MAP* map, short newHeight );

/**
 * @brief Initialize the map with the data provided in argument 
 * 
 * @param map : The DATA_MAP object to initialize
 * @param newWidth  : The width to initialize in the DATA_MAP object
 * @param newHeight  : The height to initialize in the DATA_MAP object
 * @return DATA_MAP : the initialized object
 */
static DATA_MAP initDataMap  ( DATA_MAP map, short newWidth, short newHeight );
/**
 * @brief Writes the data provided from the arguments in the matrix of the map
 * 
 * @param map : The DATA_MAP to initialize with the data provided
 * @param data : A line of data that need to be written int the map's matrix
 * @param row : the column to which this line of data belongs
 */
static void setDataToMapGraph ( DATA_MAP* map, GRAPH* graph, char* data, int row );

static void setElementToGraph ( GRAPH* graph, element value, int x, int y );

static void setElementToGraph ( GRAPH* graph, element value, int x, int y )
{
    graph->graph[x][y] = value;
}

#ifndef DEBUG
/**
 * @brief Only for Debugging purposes
 * 
 * @param map 
 */
static void display ( DATA_MAP map );
#endif

static void setDataToMapGraph ( DATA_MAP* map, GRAPH* graph, char* data, int row )
{
    int i;
    coord coordFinishLine;
    
    for ( i = 0; i < getWidthMap ( map ); i++ ) {
        /* map->map[i][row] = data[i]; */
        /* map->matrix[i][row] = data[i]; */
        setElementMatrix ( map, i, row, data[i] );
        if ( data[i] == wall ) {
            setElementToGraph ( graph, wallGraph, i, row );
        } else if ( data[i] == road ) {
            setElementToGraph ( graph, roadGraph, i, row );
        } else if ( data[i] == sand ) {
            setElementToGraph ( graph, sandGraph, i, row );
        } else if ( data[i] == finishLine ) {
            setElementToGraph ( graph, finishLineGraph, i, row );
            coordFinishLine[0] = i;
            coordFinishLine[1] = row;
            updateCoordFinishLine ( graph, coordFinishLine, getSizeFinishLine ( graph ) );

        }
    }
}

static void setWidthMap ( DATA_MAP* map, short newWidth )
{
    map->width = newWidth;
}

static void setHeightMap ( DATA_MAP* map, short newHeight )
{
    map->height = newHeight;
}

static DATA_MAP initDataMap  ( DATA_MAP map, short newWidth, short newHeight )
{
    /*
    setWidthMap ( &map, newWidth );
    setHeightMap ( &map, newHeight );
    map.map = NULL;
    */
    return map;
}

#ifndef DEBUG
static void display ( DATA_MAP map )
{
    int i, j;
    DEBUG_CHAR ( "\nAffichage de la map : ", ' ' );
    for ( i = 0; i < getHeightMap ( &map ); i++ ) {
        for ( j = 0; j < getWidthMap ( &map ); j++ ) {
            DEBUG_ONLY_CHAR ( getMapElement ( &map, j, i ) );
        }
        DEBUG_ONLY_CHAR ( '\n' );
    }
}
#endif

DATA_MAP createMap ( short newWidth, short newHeight )
{
    DATA_MAP map;
    int i;
    /*
    map = initDataMap ( map, newWidth, newHeight );
    map.map = ( char** ) malloc ( map.width * sizeof ( char* ) );
    assert ( map.map );
    for ( i = 0; i < map.width; i++ ) {
        map.map[i] = ( char* ) malloc ( map.height * sizeof ( char ) );
        assert ( map.map[i] );
    } 
    */
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
        setDataToMapGraph ( &map, graph, buf, i );
    }
    #ifndef DEBUG
        display ( map );
    #endif
    return map;
}

short getWidthMap ( DATA_MAP* map )
{
    /*
    return map.width;
    */
    return getWidthMatrix ( map );
}

short getHeightMap ( DATA_MAP* map )
{
    /*
    return map.height;
    */
   return getHeightMatrix ( map );
}

short getMapElement ( DATA_MAP* map, int x, int y )
{
    /*
    return map.map[x][y];
    */
   return getElementMatrix ( map, x, y );
}

boolean destroyDataMap ( DATA_MAP map )
{
    int i;

    for ( i = 0; i < getWidthMap ( &map ); i++ ) {
        free ( map.matrix[i] );
        map.matrix[i] = NULL;
    }
    free ( map.matrix );
    return true;
}