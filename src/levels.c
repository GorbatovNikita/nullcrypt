#include <stdlib.h>

#include "levels.h"
#include "errors.h"


/*
    Generates condition for given difficulty level
    Returns the pointer to variable that should be freed after
*/
GameMode *get_game_mode(int difficulty, char *title)
{
    GameMode *mode = malloc(sizeof(GameMode));


    int length = (difficulty + 1) * 4;
    int clear = 4;
    int encounters = (length - 4) / 4 * 3;
    int treasures = (length - 4) / 4;

    mode->title = title;
    mode->length = length;
    mode->encounters_quantity = encounters;
    mode->clear_rooms_quantity = clear;
    mode->treasures_quantity = treasures;

    mode->multiplier = 0.5 * difficulty;

    return mode;
}