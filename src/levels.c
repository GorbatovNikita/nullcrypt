#include <stdlib.h>

#include "levels.h"
#include "errors.h"
#include "utils.h"


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

int *_get_levelmap_data(GameMode difficulty)
{
    int length = difficulty.clear_rooms_quantity + difficulty.encounters_quantity + difficulty.treasures_quantity;
    int *levelmap_data = malloc(sizeof(int) * length);


    for(int enc_idx = 0; enc_idx < difficulty.encounters_quantity; enc_idx ++)
    {
        levelmap_data[enc_idx] = ENCOUNTER;
    }
    for(int trs_idx = difficulty.encounters_quantity; trs_idx < (difficulty.treasures_quantity + difficulty.encounters_quantity); trs_idx ++)
    {
        levelmap_data[trs_idx] = TREASURE;
    }
    for(int clear_idx = difficulty.encounters_quantity + difficulty.treasures_quantity; clear_idx < length; clear_idx++)
    {
        levelmap_data[clear_idx] = CLEAR;
    }

    shuffle(levelmap_data, length);

    return levelmap_data;
}

Level *generate_map(GameMode *difficulty)
{
    int length = difficulty->length;
    int *levelmap_data = _get_levelmap_data(*difficulty);
    
    Level *start_node = malloc(sizeof(Level));
    Level *current_node = start_node;

    for(int i = 0; i < length; i++)
    {
        current_node->type = levelmap_data[i];
        
        Level *new_node = malloc(sizeof(Level));
        current_node->next_level = new_node;

        current_node = new_node;
    }
    current_node->next_level = NULL;

    free(levelmap_data);

    return start_node;
}