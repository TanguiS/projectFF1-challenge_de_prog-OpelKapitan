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
 * @file diagonalAction.c
 * @brief This file contains the functions used to modify the diagonal action.
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <tangui.steimetz@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 28 mai 2022
 */


#include "../../include/direction/straightAction.h"


POSITION positionVector ( POSITION finalPosition, POSITION startPosition )
{
    finalPosition.X = finalPosition.X - startPosition.X;
    finalPosition.Y = finalPosition.Y - startPosition.Y;
    return finalPosition;
}

boolean areAligned ( POSITION A, POSITION B, POSITION C ) 
{
    return  (C.Y - A.Y) * (B.X - A.X) - (B.Y - A.Y) * (C.X - A.X ) == 0; 
}

POSITION hypotheticalNextPosition ( 
                                            POSITION nextPosition, 
                                            POSITION currentPosition, 
                                            SPEED currentSpeed 
                                         )
{
    nextPosition.X =  nextPosition.X - currentPosition.X - currentSpeed.X;
    nextPosition.Y =  nextPosition.Y - currentPosition.Y - currentSpeed.Y;
    return nextPosition;
}

void equilibrateSpeedX ( 
                                short pilotPositionX, short nextPositionX, 
                                short positionToGoX, short pilotSpeedX, 
                                ACCELERATION* nextAction 
                              )
{
    if ( pilotPositionX + pilotSpeedX != nextPositionX ) {
        if ( positionToGoX > 0 ) {
            choiceDirection ( right, nextAction );
        } else if ( positionToGoX == 0 ) {
            goStraightX ( nextAction );
        } else {
            choiceDirection ( left, nextAction );
        }
    } else {
        goStraightX ( nextAction );
    }
}

void equilibrateSpeedY ( 
                                short positionPilotY, short nextPositionY, 
                                short positionToGoY, short pilotSpeedY, 
                                ACCELERATION* nextAction 
                              )
{
    if ( positionPilotY + pilotSpeedY != nextPositionY ) {
        if ( positionToGoY > 0 ) {
            choiceDirection ( down, nextAction );
        } else if ( positionToGoY == 0 ) {
            goStraightY ( nextAction );
        } else {
            choiceDirection ( up, nextAction );
        }
    } else {
        goStraightY ( nextAction );
    }
}

PATH_LIST equilibrateSpeedForStraightLine ( 
                                                    PATH_LIST path, 
                                                    POSITION pilotPosition, 
                                                    SPEED pilotSpeed, 
                                                    ACCELERATION* nextAction 
                                                  )
{
    path_list_element nextPosition;
    POSITION positionToGo;
    if ( currentEqualsHead ( path ) ) {
        path = moveCurrentPathList ( path );
    }
    nextPosition = examineHeadPathList ( path );
    positionToGo = hypotheticalNextPosition ( nextPosition, pilotPosition, pilotSpeed );
    equilibrateSpeedX ( pilotPosition.X, nextPosition.X, positionToGo.X, pilotSpeed.X, nextAction );
    equilibrateSpeedY ( pilotPosition.X, nextPosition.Y, positionToGo.Y, pilotSpeed.Y, nextAction );
    return path;
}


boolean updatePathListIfstraightLine ( 
                                                PATH_LIST* path, 
                                                POSITION currentPosition, 
                                                GRAPH* graph 
                                            )
{
    POSITION nextPosition;
    POSITION goalPosition;
    POSITION previousGoalPosition;

    if ( isSand ( graph, currentPosition ) ) {
        return false;
    }
    *path = resetCurrentPathList ( *path );
    nextPosition = getCurrentPathListElement ( *path ); /* get head ca marche aussi */
    if ( nextPosition.X == -1 ) {
        return false;
    } else if ( isSand ( graph, nextPosition ) ) {
        return false;
    }
    goalPosition = getNextCurrentPathList ( *path );
    if ( goalPosition.X == -1 ) {
        return false;
    }
    previousGoalPosition = goalPosition;
    while ( goalPosition.X != -1 
                    && 
            areAligned ( currentPosition, nextPosition, goalPosition ) ) {
        *path = moveCurrentPathList ( *path );
        previousGoalPosition = goalPosition;
        goalPosition = getNextCurrentPathList ( *path );
        if ( isInGraph ( graph, goalPosition.X, goalPosition.Y ) ) {
            if ( isSand ( graph, goalPosition ) ) {
                break;
            }
        }
    }
    return areAligned ( currentPosition, nextPosition, previousGoalPosition );
}


void addActionToGroup ( 
                            short length, short currentSpeed, 
                            short startingIndex, POSITION startPosition, 
                            POSITION finalPosition, ACCELERATION* actions 
                              )
{
    int i;
    short decelerationPosition;
    short nextHypoteticalPosition = 0;
    short hypoteticalSpeed = abs ( currentSpeed );
    short remainingDistance;
    short numberStraightAction;
    short distanceHypoteticalyDriven;

    if ( hypoteticalSpeed == 0 ) {
        decelerationPosition = 0;
    } else {
        decelerationPosition = hypoteticalSpeed - 1;
    }
    distanceHypoteticalyDriven = decelerationPosition + nextHypoteticalPosition 
                                    + hypoteticalSpeed;
    while ( (distanceHypoteticalyDriven < length - distanceHypoteticalyDriven ) 
                                        && ( hypoteticalSpeed != MAX_SPEED ) ) {
        hypoteticalSpeed++;
        nextHypoteticalPosition += hypoteticalSpeed;
        decelerationPosition += hypoteticalSpeed - 1;
        distanceHypoteticalyDriven = decelerationPosition 
                                        + nextHypoteticalPosition 
                                        + hypoteticalSpeed;
        accelerate ( 
                    positionVector ( finalPosition, startPosition ), 
                    &actions[startingIndex] 
                   );
        startingIndex++;
    }
    remainingDistance = length - distanceHypoteticalyDriven;
    if ( remainingDistance >= hypoteticalSpeed ) {
        numberStraightAction = 
            (short) ( (float) ( remainingDistance ) / (float)(hypoteticalSpeed) );
        for ( i = 0; i < numberStraightAction; i++ ) {
            goStraight ( &actions[startingIndex] );
            startingIndex++;
        }
        remainingDistance -= hypoteticalSpeed * numberStraightAction;
        nextHypoteticalPosition += hypoteticalSpeed * numberStraightAction;
    }
    for ( i = 1; i < hypoteticalSpeed; i++ ) {
        if ( remainingDistance == hypoteticalSpeed - i ) {
            nextHypoteticalPosition += 2 * (hypoteticalSpeed - i);
            slowDown ( 
                        positionVector ( finalPosition, startPosition ), 
                        &actions[startingIndex] 
                     );
            startingIndex++;
            goStraight ( &actions[startingIndex] );
            startingIndex++;
        } else {
            slowDown ( 
                        positionVector ( finalPosition, startPosition ), 
                        &actions[startingIndex] 
                     );
            startingIndex++;
            nextHypoteticalPosition += hypoteticalSpeed - i;
        }
    }
    actions[0].X = startingIndex;
    actions[0].Y = 0;
}

void addActionToGroupDiagonal ( 
                            short length, short currentSpeed, 
                            short startingIndex, POSITION startPosition, 
                            POSITION finalPosition, ACCELERATION* actions 
                              )
{
    int i;
    short decelerationPosition;
    short nextHypoteticalPosition = 0;
    short hypoteticalSpeed = abs ( currentSpeed );
    short remainingDistance;
    short numberStraightAction;
    short distanceHypoteticalyDriven;

    if ( hypoteticalSpeed == 0 ) {
        decelerationPosition = 0;
    } else {
        decelerationPosition = hypoteticalSpeed - 1;
    }
    distanceHypoteticalyDriven = decelerationPosition + nextHypoteticalPosition 
                                    + hypoteticalSpeed;
    while ( (distanceHypoteticalyDriven < length - distanceHypoteticalyDriven ) 
                                        && ( hypoteticalSpeed != MAX_SPEED_DIA ) ) {
        hypoteticalSpeed++;
        nextHypoteticalPosition += hypoteticalSpeed;
        decelerationPosition += hypoteticalSpeed - 1;
        distanceHypoteticalyDriven = decelerationPosition 
                                        + nextHypoteticalPosition 
                                        + hypoteticalSpeed;
        accelerate ( 
                    positionVector ( finalPosition, startPosition ), 
                    &actions[startingIndex] 
                   );
        startingIndex++;
    }
    remainingDistance = length - distanceHypoteticalyDriven;
    if ( remainingDistance >= hypoteticalSpeed ) {
        numberStraightAction = 
            (short) ( (float) ( remainingDistance ) / (float)(hypoteticalSpeed) );
        for ( i = 0; i < numberStraightAction; i++ ) {
            goStraight ( &actions[startingIndex] );
            startingIndex++;
        }
        remainingDistance -= hypoteticalSpeed * numberStraightAction;
        nextHypoteticalPosition += hypoteticalSpeed * numberStraightAction;
    }
    for ( i = 1; i < hypoteticalSpeed; i++ ) {
        if ( remainingDistance == hypoteticalSpeed - i ) {
            nextHypoteticalPosition += 2 * (hypoteticalSpeed - i);
            slowDown ( 
                        positionVector ( finalPosition, startPosition ), 
                        &actions[startingIndex] 
                     );
            startingIndex++;
            goStraight ( &actions[startingIndex] );
            startingIndex++;
        } else {
            slowDown ( 
                        positionVector ( finalPosition, startPosition ), 
                        &actions[startingIndex] 
                     );
            startingIndex++;
            nextHypoteticalPosition += hypoteticalSpeed - i;
        }
    }
    actions[0].X = startingIndex;
    actions[0].Y = 0;
}