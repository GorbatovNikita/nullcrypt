#ifndef GAME_H
#define GAME_H

#include <time.h>

#include "levels.h"
#include "errors.h"

typedef struct Game
{
    char *title;
    struct tm creation_date;
    Level *current_level;
} Game;

int get_instance(Level *start_level);
int close_game(Game *game);

#endif