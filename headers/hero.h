#ifndef HERO_H
#define HERO_H

//Swordsman's base stats
#define SWORDSMAN_STRENGTH 4
#define SWORDSMAN_AGILITY 2
#define SWORDSMAN_HEALTH 75

//Archer's base stats
#define ARCHER_STRENGTH 3
#define ARCHER_AGILITY 5
#define ARCHER_HEALTH 65

//Mage's base stats
#define MAGE_STRENGTH 6
#define MAGE_AGILITY 1
#define MAGE_HEALTH 55

//General base stats
#define HERO_BASE_LOAD_CAPACITY 3


typedef enum HeroClass
{
    SWORDSMAN,
    ARCHER,
    MAGE,
}HeroClass;

typedef struct Hero
{
    char *name;
    HeroClass hero_class;
    int level;
    int strength;
    int agility;
    int health;
    int load_capacity;
} Hero;

Hero create_hero(
    char *name,
    HeroClass hero_class,
    int level
);




#endif