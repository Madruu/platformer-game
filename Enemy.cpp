#include <raylib.h>
#include "Enemy.hpp"
Enemy::Enemy()
{
        position = { 300.0f, 300.0f };
        speed = 100.0f;
        spr_enemy = LoadTexture("assets/spr_enemy.png");
}

Enemy::~Enemy()
{
        UnloadTexture(spr_enemy);
}

void Enemy::Draw()
{
        DrawTextureV(spr_enemy, position, WHITE);
}

void Enemy::Update()
{
        float dt = GetFrameTime();

        if(isGoingRight)
        {
                position.x += 1.0f * speed * dt;
                if(position.x >= 400.0f)
                {
                        isGoingRight = false;
                }
        } else {
                position.x -= 1.0f * speed * dt;
                if(position.x <= 0.0f)
                {
                        isGoingRight = true;
                }
        }
}

