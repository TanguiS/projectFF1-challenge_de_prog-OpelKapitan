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

#define MAX_LINE_LENGTH 1024

/**
 * @brief Initialize the map with the data provided in argument 
 * 
 * @param map : The DATA_MAP object to initialize
 * @param newXSize  : The width to initialize in the DATA_MAP object
 * @param newYSize  : The height to initialize in the DATA_MAP object
 * @param newGasLvl  : The gas level to initialize in the DATA_MAP object
 * @return DATA_MAP : the initialized object
 */
static DATA_MAP initDataMap  ( DATA_MAP map, short newXSize, short newYSize, short newGasLvl );
/**
 * @brief Writes the data provided from the arguments in the matrix of the map
 * 
 * @param map : The DATA_MAP to initialize with the data provided
 * @param data : A line of data that need to be written int the map's matrix
 * @param row : the column to which this line of data belongs
 */
static void putDataToMap ( DATA_MAP* map, char* data, int row );
/**
 * @brief Only for Debugging purposes
 * 
 * @param map 
 */
static void display ( DATA_MAP map );

DATA_MAP createMap ( short newXSize, short newYSize, short newGasLvl )
{
    DATA_MAP map;
    int i;
    map = initDataMap ( map, newXSize, newYSize , newGasLvl);
    map.map = ( char** ) malloc ( map.xSize * sizeof ( char* ) );
    assert ( map.map );
    for ( i = 0; i < map.xSize; i++ ) {
        map.map[i] = ( char* ) malloc ( map.ySize * sizeof ( char ) );
        assert ( map.map[i] );
    }
    map.map[0][0] = '0';
    return map;
}

static DATA_MAP initDataMap  ( DATA_MAP map, short newXSize, short newYSize, short newGasLvl )
{
    map.xSize = newXSize;
    map.ySize = newYSize;
    map.gasLvl = newGasLvl;
    map.map = NULL;
    return map;
}

static void putDataToMap ( DATA_MAP* map, char* data, int row )
{
    int i;
    
    for ( i = 0; i < map->xSize; i++ ) {
        map->map[i][row] = data[i];
    }
}

DATA_MAP readDataMap ()
{
    DATA_MAP map;
    int i;
    short xSize, ySize, gasLvl;
    char buf[MAX_LINE_LENGTH];

    fgets ( buf, MAX_LINE_LENGTH, stdin );
    sscanf ( buf, "%hd %hd %hd", &xSize, &ySize, &gasLvl );

    DEBUG_CHAR ( "=== > Lecture des Data < ===", ' ' );
    DEBUG_INT ( "Valeur de xSize : ", (int) xSize ); 
    DEBUG_INT ( "Valeur de ySize : ", (int) ySize ); 
    DEBUG_INT ( "Valeur de gasLvl : ", (int) gasLvl );

    map = createMap ( xSize, ySize, gasLvl );

    DEBUG_CHAR ( "=== > Map From readDataMap < ===", ' ' );
    DEBUG_INT ( "Verification des données de la matrice : xSize : ", map.xSize );
    DEBUG_INT ( "Verification des données de la matrice : ySize : ", map.ySize );
    DEBUG_INT ( "Verification du niveau de gaz : ", map.gasLvl );

    for ( i = 0; i < map.ySize; i++ ) {
        fgets ( buf, MAX_LINE_LENGTH, stdin );
        putDataToMap ( &map, buf, i );
    }
    fflush ( stderr );
    display ( map );
    return map;
}

static void display ( DATA_MAP map )
{
    int i, j;
    DEBUG_CHAR ( "\nAffichage de la map : ", ' ' );
    for ( i = 0; i < map.ySize; i++ ) {
        for ( j = 0; j < map.xSize; j++ ) {
            DEBUG_ONLY_CHAR ( map.map[j][i] );
        }
        DEBUG_ONLY_CHAR ( '\n' );
    }
}

boolean destroyDataMap ( DATA_MAP map )
{
    int i;

    for ( i = 0; i < map.ySize; i++ ) {
        free ( map.map[i] );
        map.map[i] = NULL;
    }
    free ( map.map );
    return true;
}