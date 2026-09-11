#include <raylib.h>
#include "Game.hpp"
#include <vector>
Game::Game()
{
        Init();       
}

Game::~Game()
{
        isRunning = false;
}

void Game::Init()
{
        isRunning = true;
        SpawnCoin({ 300.0f, 200.0f });
}

void Game::Update() {
        if(isRunning)
        {
                player.Update();
                player.MoveXAxis();
                
                if(CheckCollisionWithTiles())
                {
                        player.RestoreX();
                }

                player.MoveYAxis();

                if(CheckCollisionWithTiles())
                {
                        player.RestoreY();
                }
                enemy.Update();
                for(auto& coin : coins) {
                        coin.Update();
                }
        }
}

void Game::Draw()
{
        if(isRunning)
        {
                tm.Draw();
                player.Draw();
                enemy.Draw();
                for(auto& coin : coins) {
                        coin.Draw();
                }
        }
}

void Game::SpawnCoin(Vector2 coinPos)
{
        coins.push_back(Coin(coinPos));
}


bool Game::CheckCollisionWithTiles()
{
        Rectangle playerRect = player.GetRect();
        std::vector<Rectangle> tileRects = tm.GetRect();
        boxCollision = { 0 };
        for(auto& tile : tileRects) {
                collided = CheckCollisionRecs(playerRect, tile);
                if(collided)
                {
                        boxCollision = GetCollisionRec(playerRect, tile);
                        return true;
                        //break;
                }
        }
        return false;
}
