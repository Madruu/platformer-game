#include <cstdlib>
#include <raylib.h>
#include "Coin.hpp"

Coin::Coin(Vector2 position)
{
        this->position = position;
        value = 3;
        spr_coin = LoadTexture("assets/spr_coin.png");
}

void Coin::Update()
{
}

void Coin::Draw()
{
        DrawTextureV(spr_coin, position, WHITE);
}
