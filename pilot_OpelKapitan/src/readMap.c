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
 * @version 1.0.0
 * @date 05 avril 2022
 */

#include "readMap.h"

#define MAX_LINE_LENGTH 1024

static DATA_MAP initDataMap  ( DATA_MAP map, short newXSize, short newYSize, short newGasLvl );
static void putDataToMap ( DATA_MAP* map, char* data, int row );
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
    fprintf ( stderr, "DS CREATE MAP : %c\n", map.map[0][0] );
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

    fprintf  ( stderr, " ON A %hd %hd %hd\n", xSize, ySize, gasLvl );

    map = createMap ( xSize, ySize, gasLvl );

    fprintf ( stderr, "=== > Map From readDataMap < ===\n" );
    fprintf ( stderr, "Size %d x %d\n", map.xSize, map.ySize );
    fprintf ( stderr, "Gas at start %d \n\n", map.gasLvl );

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
    fprintf ( stderr, "Display Map : \n\n" );
    for ( i = 0; i < map.ySize; i++ ) {
        for ( j = 0; j < map.xSize; j++ ) {
            fprintf ( stderr, "%c", map.map[j][i] );
        }
        fprintf ( stderr, "\n" );
    }
}

void destroyMAdj ( DATA_MAP map )
{
    int i;

    for ( i = 0; i < map.ySize; i++ ) {
        free ( map.map[i] );
        map.map[i] = NULL;
    }
    free ( map.map );
}