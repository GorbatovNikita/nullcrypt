#ifndef ENEMY_H
#define ENEMY_H

#define ENEMY_TYPE_AMOUNT 4
#define ENEMY_LEVEL_MODIFIER 0.25

#include "hero.h"

typedef enum Type
{
    ORC,
    GOBLIN,
    DRAGON,
    SLIME,
} Type;

typedef struct EnemyType
{
    Type type;
    float strength;
    float agility;
    float health;
} EnemyType;

typedef struct Enemy
{
    char name[11];
    EnemyType type;
    int level;
} Enemy;

int set_base_enemy_types(Enemy *_enemy_list);
int set_enemy(Enemy *enemy, EnemyType type);

int attack_hero(Enemy enemy, Hero *hero);

#endif