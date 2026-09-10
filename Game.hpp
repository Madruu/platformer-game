#pragma once
#include <raylib.h>
#include <vector>
#include "Player.hpp"
#include "Enemy.hpp"
#include "Coin.hpp"
#include "TileMap.hpp"

class Game {
        public:
                Game();
                ~Game();
                void Draw();
                void Update();
        private:
                void Init();
                bool isRunning;
                void SpawnCoin(Vector2 coinPos);
                std::vector<Coin> coins;
                Player player;
                Enemy enemy;
                TileMap tm;
                void CheckCollision();
};
