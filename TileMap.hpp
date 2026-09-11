#pragma once
#include <raylib.h>
#include <vector>
#include "TextureManager.hpp"
class TileMap {
        public:
                TileMap();
                void Draw();
                std::vector<Rectangle> GetRect();
                TextureManager txm;
};
