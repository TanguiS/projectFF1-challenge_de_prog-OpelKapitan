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
 * @file readMap.h
 * @brief This file is the prototypes used by readMap.c functions.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.2
 * @date 05 avril 2022
 */

#ifndef __READMAP_HH__
#define __READMAP_HH__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "util.h"

typedef enum {
    road = '#',
    wall = '.',
    finishLine = '=',
    sand = '~'
} mapValues;

/**
 * @brief It is an object that represents the map
 */
typedef struct _dataMap {
    /*@{*/
    short width; /**< the width of the map */
    short height; /**< the height of the map */
    char** map; /**< the matrix that represents the map */
    /*@}*/
} _dataMap;
/**
 * @brief The DATA_MAP object from the _dataMap struct
 */
typedef struct _dataMap DATA_MAP;

/**
 * @brief Get the Width Map object
 * 
 * @param map : the DATA_MAP objet
 * @return short : the width of the map
 */
short getWidthMap ( DATA_MAP map );

/**
 * @brief Get the Height Map object
 * 
 * @param map : the map object
 * @return short : the height of the map
 */
short getHeightMap ( DATA_MAP map );

/**
 * @brief Get the Map Element object
 * 
 * @param map : the map object
 * @param x : the x coordinate of the element
 * @param y : the y coordiante of the element
 * @return short : the elemets 
 */
short getMapElement ( DATA_MAP map, int x, int y );

/**
 * @brief Create a Map object
 * 
 * @param newXSize : the width of the map
 * @param newYSize  : the height of the map
 * @return DATA_MAP 
 */
DATA_MAP createMap ( short newXSize, short newYSize );

/**
 * @brief Reads the data provided by the GDP and provides it to the object DATA_MAP
 * 
 * @return DATA_MAP : The DATA_MAP initialized and filled from the data provided by the GDP
 */
DATA_MAP readDataMap ( short* gasLvl );

/**
 * @brief Destroy a DATA_MAP object
 * 
 * @param map : the map to destroy
 * @return boolean : If everything went well 
 */
boolean destroyDataMap ( DATA_MAP map );

#endif /* __READMAP_HH__ */