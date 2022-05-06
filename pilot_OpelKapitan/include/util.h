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
 * @file util.h
 * @brief This file is for util type declaration.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 06 avril 2022
 */

#ifndef __UTIL_HH__
#define __UTIL_HH__

#define MAX_LINE_LENGTH 1024    /**< the maximum length of a line */
#define SIZE_COORD 2            /**< the dimension of the coordinate */
#define BOOSTS_AT_START 5       /**< the number of boosts at start */

/**
 * @brief Enumeration of a boolean type
 */
typedef enum {
    false,                      /**< false boolean */
    true                        /**< true boolean */
} boolean;

/**
 * @brief Coordinate type declaration
 */
typedef short coord[SIZE_COORD];

/**
 * @brief Element type declaration 
 */
typedef char element;

#endif /* __UTIL_HH__ */