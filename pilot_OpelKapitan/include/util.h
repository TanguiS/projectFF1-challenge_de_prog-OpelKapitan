/*
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
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.1
 * @date 06 avril 2022
 */

#ifndef __UTIL_HH__
#define __UTIL_HH__

#define MAX_LINE_LENGTH 1024    /**< the maximum length of a line */
#define BOOSTS_AT_START 5       /**< the number of boosts at start */
#define NUMBER_CASES_AROUND 8   /**< The number of cases around a case */

/**
 * @brief Enumeration of a boolean type
 */
typedef enum {
    false,                      /**< false boolean */
    true                        /**< true boolean */
} boolean;

/**
 * @brief A structure to represent the position 
 */
typedef struct _position {
    short X;                    /**< X position */
    short Y;                    /**< Y position */
} _position;
/**
 * @brief Position object declaration 
 */
typedef struct _position POSITION;

/**
 * @brief A structure to represent the speed 
 */
typedef struct _speed {
    short X;                    /**< X speed */
    short Y;                    /**< Y speed */
} _speed;
/**
 * @brief Speed object declaration 
 */
typedef struct _speed SPEED;

/**
 * @brief A structure to represent the acceleration 
 */
typedef struct _acceleration {
    short X;                    /**< X acceleration */
    short Y;                    /**< Y acceleration */
} _acceleration;

/**
 * @brief Acceleration object declaration 
 */
typedef struct _acceleration ACCELERATION;

/**
 * @brief Element type declaration 
 */
typedef char element;

#endif /* __UTIL_HH__ */