#pragma once
#include <raylib.h>

class TextureManager {
        public:
                TextureManager();
                Texture2D tex[6];
                int type;
                void LoadTextures();
                void RenderTextures(int tileMesh[20][20]);
};
