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
 * @file actionModificator.c
 * @brief This file contains the functions used to modify the action.
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <tangui.steimetz@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 15 avril 2022
 */

#include "../../include/direction/actionModificator.h"

void goRight ( ACCELERATION* action ) {
    action->X = STRAIGHT_ACTION + ACTION;
}

void goLeft ( ACCELERATION* action ) {
    action->X = STRAIGHT_ACTION - ACTION;
}

void goUp ( ACCELERATION* action  ) {
    action->Y = STRAIGHT_ACTION - ACTION;
}

void goDown ( ACCELERATION* action  ) {
    action->Y = STRAIGHT_ACTION + ACTION;
}

void addRight ( ACCELERATION* action ) {
    action->X += STRAIGHT_ACTION + ACTION;
}

void addLeft ( ACCELERATION* action ) {
    action->X += STRAIGHT_ACTION - ACTION;
}

void addUp ( ACCELERATION* action  ) {
    action->Y += STRAIGHT_ACTION - ACTION;
}

void addDown ( ACCELERATION* action  ) {
    action->Y += STRAIGHT_ACTION + ACTION;
}

void goStraight ( ACCELERATION* action ) {
    action->X = STRAIGHT_ACTION;
    action->Y = STRAIGHT_ACTION;
}

void goStraightX ( ACCELERATION* action ) {
    action->X = STRAIGHT_ACTION;
}

void goStraightY ( ACCELERATION* action ) {
    action->Y = STRAIGHT_ACTION;
}

void goBoostRight ( ACCELERATION* action ) {
    action->X = STRAIGHT_ACTION + BOOSTED_ACTION;
}

void goBoostLeft ( ACCELERATION* action ) {
    action->X = STRAIGHT_ACTION - BOOSTED_ACTION;
}

void goBoostUp ( ACCELERATION* action ) {
    action->Y = STRAIGHT_ACTION - BOOSTED_ACTION;
}

void goBoostDown ( ACCELERATION* action ) {
    action->Y = STRAIGHT_ACTION + BOOSTED_ACTION;
}

void slowDown ( POSITION directionToSlow, ACCELERATION* action )
{
    if ( directionToSlow.X > STRAIGHT_ACTION ) {
        goLeft ( action );
    } else if ( directionToSlow.X == STRAIGHT_ACTION ) {
        action->X = STRAIGHT_ACTION;
    }  else {
        goRight ( action );
    }
    if ( directionToSlow.Y > STRAIGHT_ACTION ) {
        goUp ( action );
    } else if ( directionToSlow.Y == STRAIGHT_ACTION ) {
        action->Y = STRAIGHT_ACTION;
    }  else {
        goDown ( action );
    }
}

void slowDownX ( SPEED speedToSlow, ACCELERATION* action )
{
    if ( speedToSlow.X > STRAIGHT_ACTION ) {
        goLeft ( action );
    }  else {
        goRight ( action );
    }
}

void slowDownY ( SPEED speedToSlow, ACCELERATION* action )
{
    if ( speedToSlow.Y > STRAIGHT_ACTION ) {
        goUp ( action );
    } else {
        goDown ( action );
    }
}

void slowDownDecrementX ( SPEED speedToSlow, ACCELERATION* action ) {
    if ( speedToSlow.X > STRAIGHT_ACTION ) {
        addLeft ( action );
    }  else {
        addRight ( action );
    }
}

void slowDownDecrementY ( SPEED speedToSlow, ACCELERATION* action ) {
    if ( speedToSlow.Y > STRAIGHT_ACTION ) {
        addUp ( action );
    } else {
        addDown ( action );
    }
}

void accelerate ( POSITION directionToAccelerate, ACCELERATION* action )
{
    if ( directionToAccelerate.X > STRAIGHT_ACTION ) {
        goRight ( action );
    } else if ( directionToAccelerate.X == STRAIGHT_ACTION ) {
        action->X = STRAIGHT_ACTION;
    } else {
        goLeft ( action );
    }
    if ( directionToAccelerate.Y > STRAIGHT_ACTION ) {
        goDown ( action );
    } else if ( directionToAccelerate.Y == STRAIGHT_ACTION ) {
        action->Y = STRAIGHT_ACTION;
    } else {
        goUp ( action );
    } 
}

void choiceDirection ( direction choice, ACCELERATION* action )
{
    directionFunction* directionTab[NUMBER_DIRECTION] = 
    {
        goRight, goLeft, goUp, goDown,
        goBoostRight, goBoostLeft, goBoostUp, goBoostDown
    };
    directionTab[choice]( action );
}

void basicNextAction ( POSITION positionToGo, ACCELERATION* nextAction )
{
    if ( positionToGo.X > STRAIGHT_ACTION ) {
        choiceDirection ( right, nextAction );
    } else if ( positionToGo.X == STRAIGHT_ACTION ) {
        goStraightX ( nextAction );
    } else {
        choiceDirection ( left, nextAction );
    }
    if ( positionToGo.Y > STRAIGHT_ACTION ) {
        choiceDirection ( down, nextAction );
    } else if ( positionToGo.Y == STRAIGHT_ACTION ) {
        goStraightY ( nextAction );
    } else {
        choiceDirection ( up, nextAction );
    }
}

void boostNextAction ( POSITION positionToGo, ACCELERATION* nextAction )
{
    if ( positionToGo.X > 0 ) {
        if ( positionToGo.X == 1 ) {
            choiceDirection ( right, nextAction );
        } else {
            choiceDirection ( boostRight, nextAction );
        }
    } else if ( positionToGo.X == 0 ) {
        goStraightX ( nextAction );
    } else {
        if ( positionToGo.X == -1 ) {
            choiceDirection ( left, nextAction );
        } else {
            choiceDirection ( boostLeft, nextAction );
        }
    }
    if ( positionToGo.Y > 0 ) {
        if ( positionToGo.Y == 1 ) {
            choiceDirection ( down, nextAction );
        } else {
            choiceDirection ( boostDown, nextAction );
        }
    } else if ( positionToGo.Y == 0 ) {
        nextAction->Y = 0;
        goStraightY ( nextAction );
    } else {
        if ( positionToGo.Y == -1 ) {
            choiceDirection ( up, nextAction );
        } else {
            choiceDirection ( boostUp, nextAction );
        }
    }
}