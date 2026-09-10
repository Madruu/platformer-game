#pragma once
#include <raylib.h>
#include "TextureManager.hpp"
class TileMap {
        public:
                TileMap();
                void Draw();
                TextureManager txm;
};
