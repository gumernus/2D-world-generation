// g++ generating.cpp -o generating.exe -O1 -Wall -Wno-missing-braces -mwindows -static-libgcc -static-libstdc++ -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

#include <iostream>
#include <stdlib.h>
#include "include/raylib.h"

const float screenWidth = 1920;
const float screenHeight = 1080;

const int pixel = 16;
const int maxPixelsWidth = screenWidth/pixel;
const int maxPixelsHeight = screenHeight/pixel;

void drawColumn(int x, int y){
        for (int i = y*pixel; i <= maxPixelsHeight*pixel; i = i + pixel){
        if (i == y*pixel){ //top pixel
            DrawRectangle(pixel*x, i, pixel, pixel, GREEN);    
        }
        else if (i == y*pixel+pixel){ //secont top pixel
            DrawRectangle(pixel*x, i, pixel, pixel, DARKGREEN);    
        }
        else if (i == maxPixelsHeight*pixel){ //bottom pixel
            DrawRectangle(pixel*x, i, pixel, pixel, DARKGRAY);    
        }
        else{ //all between
            DrawRectangle(pixel*x, i, pixel, pixel, DARKBROWN);    
        }
    }
}

void drawTerrain(){
    for (int i = 0; i < maxPixelsWidth; i++){
    int random = rand() % 40 + 10;
    drawColumn(i,random);
    // drawColumn(i, i);
    }
}

int main(void)
{
    InitWindow(screenWidth, screenHeight, "Gumernus generating world");
    SetTargetFPS(360);

    //--------------------------------------------------------------------------------------

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        if (IsKeyPressed(KEY_F11))
 		{
            // see what display we are on right now
 			int display = GetCurrentMonitor();
 
            
            if (IsWindowFullscreen())
            {
                // if we are full screen, then go back to the windowed size
                SetWindowSize(screenWidth, screenHeight);
            }
            else
            {
                // if we are not full screen, set the window size to match the monitor we are on
                SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
            }
 
            // toggle the state
 			ToggleFullscreen();
 		}

        //--------------------------------------------------------------------------------------

        BeginDrawing();
            ClearBackground(SKYBLUE);
            drawTerrain();
            //----------------
            DrawText(TextFormat("screenWidth: %.0f", screenWidth), 20, screenHeight-30, 20, LIGHTGRAY);
            DrawText(TextFormat("screenHeight: %.0f", screenHeight), 20, screenHeight-50, 20, LIGHTGRAY);
            DrawText(TextFormat("maxPixelsWidth: %.0i", maxPixelsWidth), 20, screenHeight-70, 20, LIGHTGRAY);
            DrawText(TextFormat("maxPixelsHeight: %.0i", maxPixelsHeight), 20, screenHeight-90, 20, LIGHTGRAY);
        EndDrawing();


    }

    //--------------------------------------------------------------------------------------

    CloseWindow();

    return 0;
}


        // // vyrenderovat řádek pixelů
        // for (int i = 64; i <= maxPixelsWidth*pixel-pixel; i = i + pixel){
        //     if (i == 64){
        //         DrawRectangle(i, 0, pixel, pixel, PURPLE);        
        //     }
        //     else if (i == maxPixelsWidth*pixel-pixel){
        //         DrawRectangle(i, 0, pixel, pixel, GREEN);      
        //     }
        //     else{
        //         DrawRectangle(i, 0, pixel, pixel, RED);      
        //     }
        // }
