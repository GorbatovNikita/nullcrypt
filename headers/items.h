#ifndef ITEMS_H
#define ITEMS_H

#define COMMON_NAME "Обычный"
#define RARE_NAME "Редкий"
#define EPIC_NAME "Эпический"
#define LEGENDARY_NAME "Легендарный"

#define ITEM_CLASS_AMOUNT 4
#define ENCHANTMENT_AMOUNT 4
#define TIER_AMOUNT 4

//Enums for item's param description
typedef enum ItemClassType
{
    SWORD,
    STAFF,
    BOW,
    SHIELD,
} ItemClassType;

typedef enum EnchantmentType
{
    STRENGTH,
    HEALTH,
    AGILITY,
    BLANK,
} EnchantmentType;

typedef enum TierType
{
    COMMON,
    RARE,
    EPIC,
    LEGENDARY,
} TierType;

// Structs that are describing Item's parameters

typedef struct Enchantment
{
    char *title;
    EnchantmentType type;
    int agility_buff;
    int strength_buff;
    int health_buff;

} Enchantment;

typedef struct ItemClass
{
    char *title;
    ItemClassType type;
    int agility_buff;
    int strength_buff;
    int health_buff;

} ItemClass;

typedef struct Tier
{
    char *title;
    TierType type;
    float multilier;
} Tier;


typedef struct Item
{
    char title[100];
    Tier tier;
    float agility;
    float strength;
    float health;
} Item;

int set_random_item(Item *item, Enchantment *_enchantment_list, ItemClass *_item_class_list, Tier *_tier_list);
int set_enchantment_list(Enchantment *_enchantment_list);
int set_item_class_list(ItemClass *_item_class_list);
int set_tier_list(Tier *_tier_list);
int set_item(Item *item, Enchantment enchantment, ItemClass item_class, Tier tier);
int set_base_items_list(Item *item, Enchantment *_enchantment_list, ItemClass *_item_class_list, Tier *_tier_list);

#endif