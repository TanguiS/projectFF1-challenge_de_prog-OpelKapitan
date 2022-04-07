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
 * @version 1.0.0
 * @date 05 avril 2022
 */

#ifndef __READMAP_HH__
#define __READMAP_HH__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "util.h"
#include "dataPilot.h"

/**
 * @brief It is an object that represents the map
 */
typedef struct _dataMap {
    /*@{*/
    short xSize; /**< the width of the map */
    short ySize; /**< the height of the map */
    short gasLvl; /** ne va pas rester ici @TODO */
    char** map; /**< the matrix that represents the map */
    /*@}*/
} _dataMap;
/**
 * @brief The DATA_MAP object from the _dataMap struct
 */
typedef struct _dataMap DATA_MAP;

/**
 * @brief Create a Map object
 * 
 * @param newXSize : the width of the map
 * @param newYSize  : the height of the map
 * @param newgasLvl : Fuel available at the beginning of the race
 * @return DATA_MAP 
 */
DATA_MAP createMap ( short newXSize, short newYSize, short newgasLvl );

/**
 * @brief Reads the data provided by the GDP and provides it to the object DATA_MAP
 * 
 * @return DATA_MAP : The DATA_MAP initialized and filled from the data provided by the GDP
 */
DATA_MAP readDataMap ();

/**
 * @brief Destroy a DATA_MAP object
 * 
 * @param map : the map to destroy
 * @return boolean : If everything went well 
 */
boolean destroyDataMap ( DATA_MAP map );

#endif /* __READMAP_HH__ */
