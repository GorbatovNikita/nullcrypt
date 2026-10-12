#ifndef LEVELS_H
#define LEVELS_H

/*
Level lengths that are associated with different difficulty types
*/

typedef struct GameMode
{
    char title[11];
    int diffuculty;
    int length;
    int clear_rooms_quantity;
    int encounters_quantity;
    int treasures_quantity;
    float multiplier;
} GameMode;

typedef enum LevelType
{
    CLEAR,
    ENCOUNTER,
    TREASURE
} LevelType;

typedef struct Level
{
    struct Level *next_level;
    LevelType type;
    
} Level;

int set_game_mode(int difficulty, char *title, GameMode *game_mode);

int generate_map(GameMode *difficulty, Level *start_node);

#endif