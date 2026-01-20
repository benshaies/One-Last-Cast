#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"



    typedef struct{
        Vector2 bottomPoint;
        Vector2 topPoint;
        Rectangle bobberRec;

        float gravity;
        Vector2 velocity;
        Vector2 direction;
    }Rod;


    typedef struct{
        Vector2 pos;
        Rectangle rec;
        bool isFishing;
        bool isCasting;
        
        Rod rod;
    }Player;

    
    extern Player player;

    void playerInit();

    void playerUpdate();

    void playerDraw();

#endif