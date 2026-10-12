#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "items.h"

int main(void)
{
    srand(time(NULL));

    Item item;

    ItemClass item_class_list[ITEM_CLASS_AMOUNT];
    Enchantment enchantment_list[ENCHANTMENT_AMOUNT];
    Tier tier_list[TIER_AMOUNT];

    set_item_class_list(item_class_list);
    set_enchantment_list(enchantment_list);
    set_tier_list(tier_list);

    while(item.tier.type != LEGENDARY)
    {

    set_random_item(&item, enchantment_list, item_class_list, tier_list);

    printf("%s\n %f\n %f\n %f\n",
           item.title, item.agility, item.strength, item.health);
    }

    return 0;
}

/*
                                                       |
                                                        \.
                                                        /|.
                                                      /  `|.
                                                    /     |.
                                                  /       |.
                                                /         `|.
                                              /            |.
                                            /              |.
                                          /                |.
     __                                 /                  `|.
      -\                              /                     |.
        \\                          /                       |.
          \\                      /                         |.
           \|                   /                           |\
             \#####\          /                             ||
         ==###########>     /                               ||
          \##==      \    /                                 ||
     ______ =       =|__/___                                ||
 ,--' ,----`-,__ ___/'  --,-`-==============================##==========>
\               '        ##_______ ______   ______,--,____,=##,__
 `,    __==    ___,-,__,--'#'  ==='      `-'              | ##,-/
   `-,____,---'       \####\              |        ____,--\_##,/
       #_              |##   \  _____,---==,__,---'         ##
        #              ]===--==\                            ||
        #,             ]         \                          ||
         #_            |           \                        ||
          ##_       __/'             \                      ||
           ####='     |                \                    |/
            ###       |                  \                  |.
            ##       _'                    \                |.
           ###=======]                       \              |.
          ///        |                         \           ,|.
          //         |                           \         |.
                                                   \      ,|.
                                                     \    |.
                                                       \  |.
                                                         \|.
                                                         /.
                                                        |
*/

/*
                    ____ 
                  .'* *.'
               __/_*_*(_
              / _______ \
             _\_)/___\(_/_ 
            / _((\- -/))_ \
            \ \())(-)(()/ /
             ' \(((()))/ '
            / ' \)).))/ ' \
           / _ \ - | - /_  \
          (   ( .;''';. .'  )
          _\"__ /    )\ __"/_
            \/  \   ' /  \/
             .'  '...' ' )
              / /  |  \ \
             / .   .   . \
            /   .     .   \
           /   /   |   \   \
         .'   /    b    '.  '.
     _.-'    /     Bb     '-. '-._ 
 _.-'       |      BBb       '-.  '-. 
(___________\____.dBBBb.________)____)

*/

/*

                   _.--.    .--._
                 ."  ."      ".  ".
                ;  ."    /\    ".  ;
                ;  '._,-/  \-,_.`  ;
                \  ,`  / /\ \  `,  /
                 \/    \/  \/    \/
                 ,=_    \/\/    _=,
                 |  "_   \/   _"  |
                 |_   '"-..-"'   _|
                 | "-.        .-" |
                 |    "\    /"    |
                 |      |  |      |
         ___     |      |  |      |     ___
     _,-",  ",   '_     |  |     _'   ,"  ,"-,_
   _(  \  \   \"=--"-.  |  |  .-"--="/   /  /  )_
 ,"  \  \  \   \      "-'--'-"      /   /  /  /  ".
!     \  \  \   \                  /   /  /  /     !
:      \  \  \   \                /   /  /  /      : 

*/