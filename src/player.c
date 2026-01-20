#include "../headers/player.h"
#include "raymath.h"
#include "stdio.h"

Player player;

float velocityY = -5;
float velocityX = 2;
float gravity = 0.25f;


void playerInit(){
    //player specific inits
    player.pos = (Vector2){685, 475};
    player.rec = (Rectangle){player.pos.x, player.pos.y, 50, 100};
    player.isFishing = false;
    player.isCasting = false;
    
    //Rod specifc inits
    player.rod.bottomPoint = (Vector2){player.rec.x + player.rec.width/2, player.rec.y + player.rec.height/2};
    player.rod.topPoint = (Vector2){player.rod.bottomPoint.x + 75, player.rod.bottomPoint.y - 75};
    player.rod.bobberRec = (Rectangle){player.rod.topPoint.x, player.rod.topPoint.y, 25, 25};
    player.rod.gravity = gravity;
    player.rod.velocity = (Vector2){0,0};
    player.rod.direction = (Vector2){0,0};

}

void playerUpdate(){

    if(IsKeyPressed(KEY_SPACE) && !player.isCasting){
        //Set fishing state to true, set velocity and direction varaibles
        player.isCasting = true;
        player.rod.bobberRec = (Rectangle){player.rod.topPoint.x, player.rod.topPoint.y, 25, 25};
        player.rod.direction = Vector2Normalize((Vector2){player.rod.bottomPoint.x - player.rod.topPoint.x, player.rod.bottomPoint.y - player.rod.topPoint.y});
        player.rod.velocity = (Vector2){velocityX, velocityY};
    }


    //Updating the bobber position if casting
    if(player.isCasting){
        player.rod.bobberRec.x += player.rod.velocity.x*2;
        player.rod.bobberRec.y += player.rod.velocity.y*1.5;
        player.rod.velocity.y += player.rod.gravity;

        //Bobber hit water, change state to actively fishing
        if(player.rod.bobberRec.y >= 625){
            player.isCasting = false;
            player.isFishing = true;
            player.rod.velocity = (Vector2){0,0};
            player.rod.direction = (Vector2){0,0};
        }
    }
}

void playerDraw(){
    DrawRectangleRec(player.rec, BLACK);

    DrawLineEx(player.rod.bottomPoint, player.rod.topPoint, 2.5f, YELLOW);

    if(player.isFishing || player.isCasting){
        DrawRectangleRec(player.rod.bobberRec, RED);
    }   
        
    
}