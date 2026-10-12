#include "items.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>


int set_item_class_list(ItemClass *_item_class_list)
{
    // setting sword

    ItemClass sword;
    sword.agility_buff = -1;
    sword.strength_buff = 2;
    sword.health_buff = 1;
    sword.title = "Меч";
    sword.type = SWORD;

    // setting staff

    ItemClass staff;
    staff.agility_buff = -1;
    staff.strength_buff = 3;
    staff.health_buff = 0;
    staff.title = "Посох";
    staff.type = STAFF;

    // setting bow

    ItemClass bow;
    bow.agility_buff = 1;
    bow.strength_buff = 2;
    bow.health_buff = 0;
    bow.title = "Лук";
    bow.type = BOW;

    // setting shield

    ItemClass shield;
    shield.agility_buff = -1;
    shield.strength_buff = 0;
    shield.health_buff = 3;
    shield.title = "Щит";
    shield.type = SHIELD;

    // setting list

    _item_class_list[0] = sword;
    _item_class_list[1] = staff;
    _item_class_list[2] = bow;
    _item_class_list[3] = shield;

    return 0;
}

int set_enchantment_list(Enchantment *_enchantment_list)
{
    //setting strength

    Enchantment strength;
    strength.agility_buff = 0;
    strength.health_buff = 0;
    strength.strength_buff = 1;
    strength.title = " Силы";
    strength.type = STRENGTH;

    //setting agility
    
    Enchantment agility;
    agility.agility_buff = 1;
    agility.health_buff = 0;
    agility.strength_buff = 0;
    agility.title = " Ловкости";
    agility.type = AGILITY;

    //setting health
    
    Enchantment health;
    health.agility_buff = 0;
    health.health_buff = 1;
    health.strength_buff = 0;
    health.title = " Здоровья";
    health.type = HEALTH;

    //setting list

    _enchantment_list[0] = strength;
    _enchantment_list[1] = agility;
    _enchantment_list[2] = health;

    return 0;
}

int set_tier_list(Tier *_tier_list)
{
    //setting common

    Tier common;
    common.title = "Обычный ";
    common.multilier = 1;
    common.type = COMMON;
    
    //setting rare
    
    Tier rare;
    rare.title = "Редкий ";
    rare.multilier = 1.5;
    rare.type = RARE;
     
    //setting epic
    
    Tier epic;
    epic.title = "Эпический ";
    epic.multilier = 2;
    epic.type = EPIC;
     
    //setting legendary
    
    Tier legendary;
    legendary.title = "Легендарный ";
    legendary.multilier = 3;
    legendary.type = LEGENDARY;


    _tier_list[0] = common;
    _tier_list[1] = rare;
    _tier_list[2] = epic;
    _tier_list[3] = legendary;


    return 0;
}


int set_random_item(Item *item, Enchantment *_enchantment_list, ItemClass *_item_class_list, Tier *_tier_list)
{
    int enchantment_idx, item_class_idx, tier;
    char title[100] = "";

    enchantment_idx = rand() % ENCHANTMENT_AMOUNT;
    item_class_idx = rand() % ITEM_CLASS_AMOUNT;
    tier = rand() % 100 + 1;

    Enchantment enchantment = _enchantment_list[enchantment_idx];
    ItemClass item_class = _item_class_list[item_class_idx];
    Tier item_tier;
    

    if(tier <= 2)
    {
        item_tier = _tier_list[3];
    }    
    else if(tier > 2 && tier <= 10)
    {
        item_tier = _tier_list[2];
    }
    else if(tier > 10 && tier <= 25)
    {
        item_tier = _tier_list[1];
    }
    else
    {
        item_tier = _tier_list[0];
    }

    snprintf(title, sizeof(title), "%s%s%s",
         item_tier.title, item_class.title, enchantment.title);

    
    item->title[0] = '\0';
    item->agility = (item_class.agility_buff + enchantment.agility_buff) * item_tier.multilier;
    item->strength = (item_class.strength_buff + enchantment.strength_buff) * item_tier.multilier;
    item->health = (item_class.health_buff + enchantment.health_buff) * item_tier.multilier;
    item->tier = item_tier;

    strcat(item->title, title);

    return 0;

}
