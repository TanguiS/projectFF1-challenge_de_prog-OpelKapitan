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
 * @file communicatorWithGDC.h
 * @brief This file is the prototypes used by communicatorWithGDC.c functions.
 */

/**
 * @author PICQUE Kylian <picque.kylian@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.3
 * @date 05 avril 2022
 */

#ifndef __COMMUNICATOR_W_GDC__HH__
#define __COMMUNICATOR_W_GDC__HH__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "util.h"
#include "graphMadj.h"
#include "pilotManagement.h"

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
 * @brief Read the data sent by the GDC
 * 
 * @param gasLvl : the gas level sent by the GDC
 * @param graph : the Graph object initialized
 * @return 
 */
void readDataFromGDC ( short* gasLvl, GRAPH* graph );

#endif /* __COMMUNICATOR_W_GDC__HH__ */