#include "hero.h"


Hero create_hero(
    char *name,
    HeroClass hero_class,
    int level
)
{
    Hero *hero = malloc(sizeof(Hero));
    
    hero->name = name;
    hero->hero_class = hero_class;
    hero->level = level;

    if(hero_class == MAGE)
    {
        hero->strength = MAGE_STRENGTH;
        hero->agility = MAGE_AGILITY;
        hero->health = MAGE_HEALTH;
        
    }
    else if(hero_class == SWORDSMAN)
    {
        hero->strength = SWORDSMAN_STRENGTH;
        hero->agility = SWORDSMAN_AGILITY;
        hero->health = SWORDSMAN_HEALTH;
        
    }
    else
    {
        hero->strength = ARCHER_STRENGTH;
        hero->agility = ARCHER_AGILITY;
        hero->health = ARCHER_HEALTH;
        
    }
    hero->load_capacity = HERO_BASE_LOAD_CAPACITY;

    return *hero;
}