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
               // std::vector<Enemy> enemies;
                Enemy enemy;
                TileMap tm;
                bool collided = false;
                Rectangle boxCollision;
                bool CheckCollisionWithTiles();
                bool CheckCollisionWithEnemy();
};
