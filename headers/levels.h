#ifndef LEVELS_H
#define LEVELS_H

/*
Level lengths that are associated with different difficulty types
*/

typedef struct GameMode
{
    char *title;
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

Level generate_map(LevelType *levelmap_data, int length);


#endif