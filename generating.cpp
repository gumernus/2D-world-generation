// g++ generating.cpp -o generating.exe -O1 -Wall -Wno-missing-braces -mwindows -static-libgcc -static-libstdc++ -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

#include <iostream>
#include "include/raylib.h"

void drawPixel(){

}

int main(void)
{
    const float screenWidth = 1920/2;
    const float screenHeight = 1080/2;

    const int pixel = 16;
    const float maxPixelsWidth = screenWidth/pixel;
    const float maxPixelsHeight = screenHeight/pixel;

    InitWindow(screenWidth, screenHeight, "Gumernus generating world");
    SetTargetFPS(360);

    //--------------------------------------------------------------------------------------

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        BeginDrawing();
        ClearBackground(BLACK);

        //----------------

        // vyrenderovat 0Y maxX pixelů
        for (int i = 0; i < maxPixelsWidth*pixel; i = i + pixel){
            DrawRectangle(i, 0, pixel, pixel, RED);    
        }

        // vyrenderovat maxY 0X pixelů
        for (int i = 0; i < maxPixelsHeight*pixel; i = i + pixel){
            DrawRectangle(0, i, pixel, pixel, BLUE);    
        }

        //----------------

        DrawText(TextFormat("screenWidth: %.0f", screenWidth), 10, screenHeight-30, 20, LIGHTGRAY);
        DrawText(TextFormat("screenHeight: %.0f", screenHeight), 10, screenHeight-50, 20, LIGHTGRAY);
        DrawText(TextFormat("maxPixelsWidth : %.0f", maxPixelsWidth), 10, screenHeight-70, 20, LIGHTGRAY);
        DrawText(TextFormat("maxPixelsHeight : %.0f", maxPixelsHeight), 10, screenHeight-90, 20, LIGHTGRAY);

        //----------------

        EndDrawing();
    }

    //--------------------------------------------------------------------------------------

    CloseWindow();

    return 0;
}
