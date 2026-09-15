#include <cmath>
#include <raylib.h>
#include "Player.hpp"

Player::Player()
{
        spr_player = LoadTexture("assets/spr_player.png");
        moveSpeed = 200.0f;
        position = { 400, 225 };
        score = 0;
        gravity = 450;
        jumpForce = 200;
        isJumping = false;
        velocityY = 0.0f;
}

Player::~Player()
{
        UnloadTexture(spr_player);
}

void Player::Update()
{
        //Input vector
        input = { 0.0f, 0.0f };

        if(IsKeyDown(KEY_W)) { input.y -= 1.0f; }
        if(IsKeyDown(KEY_S)) { input.y += 1.0f; }
        if(IsKeyDown(KEY_A)) { input.x -= 1.0f; }
        if(IsKeyDown(KEY_D)) { input.x += 1.0f; }

        //Calculates length of vector
        float length = sqrtf(input.x * input.x + input.y * input.y);

        //Normalizes Vector
        if(length > 0.0f)
        {
                input.x /= length;
                input.y /= length;
        }
}

void Player::MoveXAxis()
{
        SaveX();
        float dt = GetFrameTime();
        position.x += input.x * moveSpeed * dt;
}

void Player::MoveYAxis()
{
        SaveY();
        float dt = GetFrameTime();
        //For jumping need velocityY
        if(IsKeyPressed(KEY_SPACE) && !isJumping)
        {
                isJumping = true;
                velocityY = -jumpForce;
        } 

        velocityY += gravity * dt;

        position.y += velocityY * dt;
}

void Player::SaveX()
{
        oldPosition.x = position.x;
}

void Player::RestoreX()
{
        position.x = oldPosition.x;
}

void Player::SaveY()
{
        oldPosition.y = position.y;
}

void Player::RestoreY()
{
        position.y = oldPosition.y;
}

void Player::Draw()
{
        DrawTextureV(spr_player, position, WHITE);
}

Vector2 Player::GetPosition()
{
        return position;
}

Rectangle Player::GetRect()
{
        return { position.x, position.y, static_cast<float>(spr_player.width), static_cast<float>(spr_player.height) };
}


int Player::GetScore()
{
        return score;
}
