#include "../headers/fish.h"

void fishInit(Fish *fish, int id, Vector2 pos){
    fish->active = true;
    fish->color = BLACK;
    fish->id = id;
    fish->rec = (Rectangle){pos.x, pos.y, 50, 25};
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
