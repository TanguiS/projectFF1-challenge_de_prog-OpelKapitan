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

typedef struct _dataMap {
    short xSize;
    short ySize;
    short gasLvl;
    char** map;
} _dataMap;
typedef struct _dataMap DATA_MAP;

DATA_MAP createMap ( short newXSize, short newYSize, short newgasLvl );

DATA_MAP readDataMap ();

void destroyDataMap ( DATA_MAP map );


#endif /* __READMAP_HH__ */
