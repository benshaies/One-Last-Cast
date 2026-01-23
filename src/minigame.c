#include "../headers/minigame.h"

void miniGameInit(MiniGame *fishGame, int rarity){
    fishGame->isActive = true;
    //fishGame->rec = (Rectangle){ 600, 110, 500, 500};
    fishGame->containerRec = (Rectangle){950, 150, 100, 400};
    
    fishGame->arrowDirection = 1;

    switch (rarity){
        case 1:
            fishGame->sweetSpotRec = (Rectangle){fishGame->containerRec.x, GetRandomValue(fishGame->containerRec.y, fishGame->containerRec.height + fishGame->containerRec.y - 100), 100, 75};
            fishGame->arrowSpeed = 8.0f;
            fishGame->arrowRec = (Rectangle){fishGame->containerRec.x, fishGame->containerRec.y, 100, 25};
            break;
        case 2:
            fishGame->sweetSpotRec = (Rectangle){fishGame->containerRec.x, GetRandomValue(fishGame->containerRec.y, fishGame->containerRec.height + fishGame->containerRec.y - 100), 100, 50};
            fishGame->arrowSpeed = 10.0f;
            fishGame->arrowRec = (Rectangle){fishGame->containerRec.x, fishGame->containerRec.y, 100, 25};
            break;
        case 3:

        case 4:

        case 5:

    }

}

bool miniGameUpdate(MiniGame *fishGame){
    if(fishGame->isActive){
        fishGame->arrowRec.y += fishGame->arrowSpeed * fishGame->arrowDirection;

        if(!CheckCollisionRecs(fishGame->arrowRec, (Rectangle){fishGame->containerRec.x, fishGame->containerRec.y + 25, fishGame->containerRec.width, fishGame->containerRec.height - 50})){
            fishGame->arrowDirection *= -1;
        }

        if(CheckCollisionRecs(fishGame->arrowRec, fishGame->sweetSpotRec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
            return true;
        }
        else{
            return false;
        }

    }
}

void miniGameDraw(MiniGame *fishGame){
    if(fishGame->isActive){
        DrawRectangleRec(fishGame->rec, BLACK);
        DrawRectangleRec(fishGame->containerRec, RED);
        DrawRectangleRec(fishGame->sweetSpotRec, GREEN);
        DrawRectangleRec(fishGame->arrowRec, BLACK);
    }
}

void miniGameReset(MiniGame *fishGame){
    fishGame->isActive = false;
}