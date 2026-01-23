#include "../headers/game.h"
#include "../headers/world.h"
#include "../headers/player.h"
#include "../headers/fish.h"
#include "../headers/minigame.h"

const int GAME_WIDTH = 1280;
const int GAME_HEIGHT = 720;

RenderTexture2D target;

Player player;

Fish currentFish;

MiniGame fishGame;

//Temp timer
float timer = 0.0f;

void gameInit(){
    //Window init stuff
    InitWindow(GAME_WIDTH, GAME_HEIGHT, "One Last Cast");  
    SetTargetFPS(60);

    target = LoadRenderTexture(GAME_WIDTH, GAME_HEIGHT);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT); 

    //external entity Inits
    worldInit();
    playerInit(&player);

}

void gameUpdate(){
    worldUpdate();
    playerUpdate(&player);

    switch (player.state){
        case FISHING:
            timer += GetFrameTime();

            if(timer >= 2){
                timer = 0.0f;
                player.state = FISH_ON_LINE;
                fishInit(&currentFish, player.rod.bobber, player.level);
            }
            break;

        case TRYING_TO_CATCH:
            miniGameInit(&fishGame, currentFish.rarityLevel);
            player.state = MINI_GAME;
            break;

        case MINI_GAME:
            if(miniGameUpdate(&fishGame)){
                player.state = REELING_IN_FISH;
                miniGameReset(&fishGame);
            }
            break;

        case REELING_IN_FISH:
            fishUpdate(&currentFish, player.rod.bobber);
            break;
        
        case IDLE:
            fishReset(&currentFish);
            break;
    }
    
}

void gameResolutionDraw(){
    BeginDrawing();
        ClearBackground(WHITE);

        float scale = fmin(
            (float)GetScreenWidth()  / GAME_WIDTH,
            (float)GetScreenHeight() / GAME_HEIGHT
        );

        float scaledWidth  = GAME_WIDTH  * scale;
        float scaledHeight = GAME_HEIGHT * scale;

        float offsetX = (GetScreenWidth()  - scaledWidth)  * 0.5f;
        float offsetY = (GetScreenHeight() - scaledHeight) * 0.5f;

        Rectangle src = { 
            0, 0, 
            (float)target.texture.width, 
            -(float)target.texture.height   // flip vertically
        };

        Rectangle dst = {
            offsetX, offsetY,
            scaledWidth, scaledHeight
        };

        DrawTexturePro(target.texture, src, dst, (Vector2){0,0}, 0.0f, WHITE);

    EndDrawing();
}

void gameDraw(){
    BeginTextureMode(target);
        ClearBackground(WHITE);

        worldDraw();
        playerDraw(&player);

        fishDraw(&currentFish);

        miniGameDraw(&fishGame);

    
    EndTextureMode();

    gameResolutionDraw();

}