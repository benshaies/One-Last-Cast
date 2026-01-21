#ifndef FISH_H
#define FISH_H
#include "raylib.h"

    typedef struct{
        int id;
        Rectangle rec;
        bool active;
        Color color; //Temporary
    }Fish;

    void fishInit(Fish *fish, int id, Vector2 pos);

    void fishUpdate(Fish *fish, Vector2 bobberPos);

    void fishDraw(Fish *fish);
      


#endif