#include "hero.h"
#include "errors.h"

#include <stdlib.h>
#include <string.h>


int set_hero(Hero *hero, char name[11], HeroClass hero_class, int level)
{
    hero->item_list = malloc(sizeof(Item) * HERO_BASE_LOAD_CAPACITY);

    if(!name)
    {
        return ERROR_BAD_HERO_NAME_DATA;
    }

    if(level <= 0)
    {
        return ERROR_BAD_HERO_LEVEL_DATA;
    }

    hero->name[0] = '\0';    
    strcat(hero->name, name);

    hero->hero_class = hero_class;
    hero->level = level;

    hero->item_list = malloc(sizeof(Item) * HERO_BASE_LOAD_CAPACITY);

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

    

    return EXIT_SUCCESS;
}

int set_hero_inventory(Hero *hero, Item base_item_list[3])
{
    if(hero->hero_class == SWORDSMAN)
    {
        hero->item_list[0] = base_item_list[0];
    }
    else if(hero->hero_class == MAGE)
    {
        hero->item_list[0] = base_item_list[1];
    }
    else
    {   
        hero->item_list[0] = base_item_list[2];
    }

    return EXIT_SUCCESS;
}