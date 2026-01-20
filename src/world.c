#include "../headers/world.h"

Rectangle waterRec;
Rectangle boatRec;

void worldInit(){
    waterRec = (Rectangle){0, 600, 1280, 120};
    boatRec = (Rectangle){350, 550, 400, 100};
}

void worldUpdate(){

}

void worldDraw(){
    DrawRectangleRec(waterRec, BLUE);
    DrawRectangleRec(boatRec, BROWN);
}