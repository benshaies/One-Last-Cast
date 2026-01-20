#include "raylib.h"
#include "stdio.h"
#include "../headers/game.h"

const int screenWidth = 1280;
const int screenHeight = 720;

bool isBorderless = false;

void toggleBorderless(){
    if(IsKeyPressed(KEY_F11)){
        isBorderless = !isBorderless;

        if (isBorderless)
        {
            ToggleBorderlessWindowed();

            int monitor = GetCurrentMonitor();
            Vector2 pos = GetMonitorPosition(monitor);

            SetWindowPosition(pos.x, pos.y);
            SetWindowSize(GetMonitorWidth(monitor), GetMonitorHeight(monitor));
        }
        else
        {
            ToggleBorderlessWindowed();
            SetWindowSize(1280, 720);  
            SetWindowPosition(100, 100);
        }
    }   
}



int main(void){

    gameInit();
    while (!WindowShouldClose()){
        gameUpdate();
        gameDraw();

        toggleBorderless();
    }

    CloseWindow();
    return 0;
}