#include <raylib.h>
#include "Game.hpp"
int main()
{
        int w = 640;
        int h = 640;
        const int FPS = 60;
        InitWindow(w, h, "Platformer CPP");
        Game game;
        SetTargetFPS(FPS);
 
        while(!WindowShouldClose()) {
                game.Update();
                BeginDrawing();
                        ClearBackground(BLACK);
                        game.Draw();        
                EndDrawing();
        }

        CloseWindow();

        return 0;
}

