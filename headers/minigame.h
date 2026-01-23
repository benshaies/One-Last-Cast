#ifndef MINIGAME_H
#define MINIGAME_H
#include "raylib.h"

    typedef struct{
        bool isActive;
        Rectangle rec;
        Rectangle containerRec;
        Rectangle sweetSpotRec;
        Rectangle arrowRec;

        float arrowSpeed;
        int arrowDirection; 
    }MiniGame;

    void miniGameInit(MiniGame *fishGame, int rarity);

    bool miniGameUpdate(MiniGame *fishGame);

    void miniGameDraw(MiniGame *fishGame);

    void miniGameReset(MiniGame *fishGame);



#endif