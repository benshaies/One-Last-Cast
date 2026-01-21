#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

    typedef enum{
        IDLE,
        CASTING,
        FISHING,
        REELING_IN,
        FISH_ON_LINE,
        REELING_IN_FISH,
    }State;

    typedef struct{
        Vector2 bottomPoint;
        Vector2 topPoint;
        Vector2 bobber;

        float gravity;
        Vector2 velocity;
        Vector2 direction;

        //Catching fish
        Vector2 start;
        Vector2 end;
        float t;
        float speed;
        float arcHeight;
    }Rod;


    typedef struct{
        Vector2 pos;
        Rectangle rec;

        State state;
        
        Rod rod;
    }Player;


    void playerInit(Player *player);

    void playerUpdate(Player *player);

    void playerDraw(Player *player);

#endif