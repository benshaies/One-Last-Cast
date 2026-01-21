#include "../headers/player.h"
#include "raymath.h"
#include "stdio.h"


float velocityY = -3;
float velocityX = 2;
float gravity = 0.25f;


void playerInit(Player *player){
    //player specific inits
    player->pos = (Vector2){685, 475};
    player->rec = (Rectangle){player->pos.x, player->pos.y, 50, 100};
    player->state = IDLE;

    //Rod specifc inits
    player->rod.bottomPoint = (Vector2){player->rec.x + player->rec.width/2, player->rec.y + player->rec.height/2};
    player->rod.topPoint = (Vector2){player->rod.bottomPoint.x + 75, player->rod.bottomPoint.y - 75};
    player->rod.bobber = player->rod.topPoint;

    player->rod.gravity = gravity;
    player->rod.velocity = (Vector2){0,0};
    player->rod.direction = (Vector2){0,0};

    player->rod.end = player->rod.topPoint;
    player->rod.start = player->rod.bobber;
    player->rod.t = 0.0f;
    player->rod.speed = 2.0f;
    player->rod.arcHeight = 250.0f;
}

void playerUpdate(Player *player){

    switch (player->state){
        case IDLE:
            
            //Set fishing state to true, set velocity and direction varaibles
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                
                player->state = CASTING;
                player->rod.bobber = player->rod.topPoint;
                player->rod.direction = Vector2Normalize((Vector2){player->rod.bottomPoint.x - player->rod.topPoint.x, player->rod.bottomPoint.y - player->rod.topPoint.y});
                player->rod.velocity = (Vector2){velocityX, velocityY};
            }

            //Changing road angle
            if(IsKeyPressed(KEY_A)){
            player->rod.topPoint.x -= 5;
            }
            else if(IsKeyPressed(KEY_D)){
                player->rod.topPoint.x += 5;
            }

            break;

        case CASTING:
            //Apply velocity to bobber
            player->rod.bobber.x += player->rod.velocity.x * -player->rod.direction.x * 7.5;
            player->rod.bobber.y += player->rod.velocity.y * player->rod.direction.y * 7.5;
            player->rod.velocity.y += player->rod.gravity;

            //Bobber hit water, change state to actively fishing
            if(player->rod.bobber.y >= 625){
                player->state = FISHING;
                player->rod.velocity = (Vector2){0,0};
                player->rod.direction = (Vector2){0,0};
            }
            break;

        case FISHING:

            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                player->state = REELING_IN;
            }
            break;

        case REELING_IN:

            //Slowly reel in bobber
            if(player->rod.bobber.x > player->rod.topPoint.x){
            player->rod.bobber.x -= 3.5f;
            }
            else if(player->rod.bobber.y > player->rod.topPoint.y){
                player->rod.bobber.y -= 3.0f;
            }
            else{
                player->state = IDLE;
            }
            break;
        
        case FISH_ON_LINE:
            if(IsMouseButtonPressed(MOUSE_BUTTON_LEFT)){
                player->state = REELING_IN_FISH;
                player->rod.start = player->rod.bobber;
                player->rod.end = player->rod.topPoint;
            }
            break;

        case REELING_IN_FISH:
            
            player->rod.t += GetFrameTime() * player->rod.speed;
            if(player->rod.t > 1.0f){
                player->rod.t = 1.0f;
            }

            player->rod.bobber.x = player->rod.start.x + (player->rod.end.x - player->rod.start.x) * player->rod.t;
            player->rod.bobber.y = player->rod.start.y + (player->rod.end.y - player->rod.start.y) * player->rod.t;

            float arc = sinf(player->rod.t * PI) * player->rod.arcHeight;
            player->rod.bobber.y -= arc;

            if(CheckCollisionPointCircle(player->rod.topPoint, player->rod.bobber, 10)){
                player->state = IDLE;
                player->rod.t = 0;
            }
            

            

    }
    
}

void playerDraw(Player *player){
    DrawRectangleRec(player->rec, BLACK);

    DrawLineEx(player->rod.bottomPoint, player->rod.topPoint, 10.0f, YELLOW);


   
    DrawLineEx(player->rod.topPoint, (Vector2){player->rod.bobber.x, player->rod.bobber.y}, 3.0f, BLACK);
    DrawCircleV(player->rod.bobber, 12.5f, player->state != FISH_ON_LINE ? RED : GREEN);   
        
    
}