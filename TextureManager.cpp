#include <raylib.h>
#include "TextureManager.hpp"

TextureManager::TextureManager()
{
}

void TextureManager::LoadTextures()
{
         tex[0] = LoadTexture("assets/spr_grass.png");//
         tex[1] = LoadTexture("assets/spr_water.png");//
         tex[2] = LoadTexture("assets/spr_wall.png");//
         tex[3] = LoadTexture("assets/spr_sign.png");//
         tex[4] = LoadTexture("assets/spr_grassLedge.png");//
         tex[5] = LoadTexture("assets/spr_grassVertical.png");
}

void TextureManager::RenderTextures(int tileMesh[20][20])
{
        int tileSize = 32;

        for(int y = 0; y < 20; y++) {
                for(int x = 0; x < 20; x++) {
                        int tileType = tileMesh[y][x];
                        DrawTexture(tex[tileType], x * tileSize, y * tileSize, WHITE);
                }
        }
}

