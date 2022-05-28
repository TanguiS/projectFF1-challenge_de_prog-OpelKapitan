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
 * @file actionModificator.h
 * @brief This file contains the prototypes used to modify the action.
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <tangui.steimetz@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 15 avril 2022
 */

#ifndef __ACTION_MODIFICATOR_HH__
#define __ACTION_MODIFICATOR_HH__

#include "../tools/util.h"

#define NUMBER_DIRECTION 8  /**< the number of basic directions */
#define ACTION 1            /**< the classic Action value */
#define BOOSTED_ACTION 2    /**< the boost Action value */
#define STRAIGHT_ACTION 0   /**< the straight Action value */
#define MAX_SPEED 5         /**< the maximum speed that we fixed */
#define MAX_SPEED_DIA 3     /**< the maximum speed that we fixed for a diagonal */

/**
 * @brief Enumeration of a direction type.
 */
typedef enum {
    right,                  /**< the right direction */
    left,                   /**< the left direction */
    up,                     /**< the up direction */
    down,                   /**< the down direction */

    boostRight,             /**< the right direction with a boost */
    boostLeft,              /**< the left direction with a boost */
    boostUp,                /**< the up direction with a boost */
    boostDown               /**< the down direction with a boost */
} direction;

/**
 * @brief Declaration of a function pointer to redirect 
 *        to the correct function to calculate the next action
 * 
 * @param action the next determined action 
 * @return void 
 */
typedef void directionFunction ( ACCELERATION* action );

/**
 * @brief Set action to right
 * 
 * @param action the action determined
 */
void goRight ( ACCELERATION* action );

/**
 * @brief Set action to left
 * 
 * @param action the action determined
 */
void goLeft ( ACCELERATION* action );

/**
 * @brief Set action to up
 * 
 * @param action the action determined
 */
void goUp ( ACCELERATION* action  );

/**
 * @brief Set action to down
 * 
 * @param action the action determined
 */
void goDown ( ACCELERATION* action  );

/**
 * @brief Add +1 to the the horrizontal acceleration.
 * 
 * @param action The action determined.
 */
void addRight ( ACCELERATION* action );

/**
 * @brief Add -1 to the the horrizontal acceleration.
 * 
 * @param action The action determined.
 */
void addLeft ( ACCELERATION* action );

/**
 * @brief Add -1 to the the vertical acceleration.
 * 
 * @param action The action determined.
 */
void addUp ( ACCELERATION* action  );

/**
 * @brief Add +1 to the the vertical acceleration.
 * 
 * @param action The action determined.
 */
void addDown ( ACCELERATION* action  );

/**
 * @brief Set action to straight
 * 
 * @param action the action determined
 */
void goStraight ( ACCELERATION* action );

/**
 * @brief Set action to straight towards X
 * 
 * @param action the action determined
 */
void goStraightX ( ACCELERATION* action );

/**
 * @brief Set action to straight towards Y
 * 
 * @param action the action determined
 */
void goStraightY ( ACCELERATION* action );

/**
 * @brief Set action to right with a boost
 * 
 * @param action the action determined
 */
void goBoostRight ( ACCELERATION* action );

/**
 * @brief Set action to left with a boost
 * 
 * @param action the action determined
 */
void goBoostLeft ( ACCELERATION* action );

/**
 * @brief Set action to up with a boost
 * 
 * @param action the action determined
 */
void goBoostUp ( ACCELERATION* action );

/**
 * @brief Set action to down with a boost
 * 
 * @param action the action determined
 */
void goBoostDown ( ACCELERATION* action );

/**
 * @brief Set action to slow down thanks to directionToSlow.
 * 
 * @param directionToSlow the hypotthetical acceleration.
 * @param action the action determiated.
 */
void slowDown ( POSITION directionToSlow, ACCELERATION* action );

/**
 * @brief Set action to slow down towards X
 * 
 * @param speedToSlow the speed of the pilot to remove
 * @param action the action determined
 */
void slowDownX ( SPEED speedToSlow, ACCELERATION* action );

/**
 * @brief Set action to slow down towards Y
 * 
 * @param speedToSlow the speed of the pilot to remove
 * @param action the action determined
 */
void slowDownY ( SPEED speedToSlow, ACCELERATION* action );

/**
 * @brief Set action to slow down towards X.
 * 
 * @param speedToSlow the speed of the pilot to remove.
 * @param action the action determined.
 */
void slowDownDecrementX ( SPEED speedToSlow, ACCELERATION* action );

/**
 * @brief Set action to slow down towards Y.
 * 
 * @param speedToSlow the speed of the pilot to remove.
 * @param action the action determined.
 */
void slowDownDecrementY ( SPEED speedToSlow, ACCELERATION* action );

/**
 * @brief Set action to accelerate towards the direction
 * 
 * @param directionToAccelerate the direction of the pilot
 * @param action the action determined
 */
void accelerate ( POSITION directionToAccelerate, ACCELERATION* action );

#endif /* __ACTION_MODIFICATOR_HH__ */