#ifndef FISH_H
#define FISH_H
#include "raylib.h"

    typedef struct{
        int id;
        Rectangle rec;
        bool active;
        Color color; //Temporary
        int rarityLevel;
    }Fish;

    void fishInit(Fish *fish, Vector2 pos, int currentLevel);

    void fishUpdate(Fish *fish, Vector2 bobberPos);

    void fishDraw(Fish *fish);

    void fishReset(Fish *fish);
      


#endif