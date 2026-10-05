#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "levels.h"

int main()
{

    GameMode *difficulty = get_game_mode(5, "hard");
    printf("\n");

    Level *cur_level = generate_map(difficulty);

    while(cur_level->next_level)
    {
        printf("%d ", cur_level->type);
        cur_level = cur_level->next_level;
    }

    
    free(cur_level);
    free(difficulty);


    return 0;
}