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
 * @version 1.0.3
 * @date 05 avril 2022
 */

#ifndef __READMAP_HH__
#define __READMAP_HH__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "util.h"
#include "graphMadj.h"
#include "matrix.h"

/**
 * @brief Enumeration of the values of a map 
 */
typedef enum {
    road        = '#',      /**< the road value */
    wall        = '.',      /**< the wall value */
    finishLine  = '=',      /**< the finishLine value */
    sand        = '~'       /**< the sand value */
} mapValues;

/**
 * @brief It is an object that represents the map
 */
typedef struct _matrix DATA_MAP;

/**
 * @brief Get the Width Map object
 * 
 * @param map : the DATA_MAP objet
 * @return short : the width of the map
 */
short getWidthMap ( DATA_MAP* map );

/**
 * @brief Get the Height Map object
 * 
 * @param map : the map object
 * @return short : the height of the map
 */
short getHeightMap ( DATA_MAP* map );


/**
 * @brief Get the Element Map object
 * 
 * @param map : the map object
 * @param coord : the coordinate of the wanted element
 * @return short : the element
 */
short getElementMap ( DATA_MAP* map, POSITION coord );

/**
 * @brief Create a Map object
 * 
 * @param width : the width of the map
 * @param height  : the height of the map
 * @return DATA_MAP 
 */
DATA_MAP createMap ( short width, short height );

/**
 * @brief Read the data sent by the GDC
 * 
 * @param gasLvl : the gas level sent by the GDC
 * @param graph : the Graph object initialized
 * @return DATA_MAP : the Map object initialized
 */
DATA_MAP readDataFromGDC ( short* gasLvl, GRAPH* graph, GRAPH* referenceGraph );

/**
 * @brief Destroy a DATA_MAP object
 * 
 * @param map : the map to destroy
 * @return boolean : If everything went well 
 */
boolean destroyMap ( DATA_MAP map );

#endif /* __READMAP_HH__ */