#include "../headers/game.h"
#include "../headers/world.h"
#include "../headers/player.h"

const int GAME_WIDTH = 1280;
const int GAME_HEIGHT = 720;

RenderTexture2D target;

void gameInit(){
    //Window init stuff
    InitWindow(GAME_WIDTH, GAME_HEIGHT, "One Last Cast");  
    SetTargetFPS(60);

    target = LoadRenderTexture(GAME_WIDTH, GAME_HEIGHT);
    SetTextureFilter(target.texture, TEXTURE_FILTER_POINT); 

    //external entity Inits
    worldInit();
    playerInit();


}

void gameUpdate(){
    worldUpdate();
    playerUpdate();
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
        playerDraw();
    
    EndTextureMode();

    gameResolutionDraw();

}