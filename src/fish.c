#include "../headers/fish.h"

const int rarityOneAmount = 10;
const int rarityTwoAmount = 8;
const int rarityThreeAmount = 6;
const int rarityFourAmount = 3;
const int rarityFiveAmount = 1;

void fishInit(Fish *fish, Vector2 pos, int currentLevel){
    fish->active = true;
    
    fish->id = 1;
    fish->rec = (Rectangle){pos.x, pos.y, 50, 25};

    switch (currentLevel){
        case 1:
            fish->id = GetRandomValue(1, rarityOneAmount + rarityTwoAmount);
            if(fish->id > 0 && fish->id <= rarityOneAmount){
                fish->rarityLevel = 1;
                fish->color = BLACK;
            }
            else if(fish->id > rarityOneAmount && fish->id <= rarityOneAmount + rarityTwoAmount){
                fish->rarityLevel = 2;
                fish->color = GOLD;
            }
            break;
        case 2:

        case 3:

    }

    
}

void fishUpdate(Fish *fish, Vector2 bobberPos){

    if(fish->active){
        fish->rec.x = bobberPos.x;
        fish->rec.y = bobberPos.y;
    }
}

void fishDraw(Fish *fish){
    if(fish->active){
        DrawRectangleRec(fish->rec, fish->color);
    }
}

void fishReset(Fish *fish){
    fish->active = false;
    fish->color = BLUE;
    fish->id = 0;
    fish->rec = (Rectangle){0,0, 0, 0};
}
