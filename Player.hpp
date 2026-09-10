#pragma once
#include "raylib.h"


class Player {
        public:
                Player();
                ~Player();
                void Update();
                void Draw();
                Vector2 GetPosition(); 
                Rectangle GetRect();
                int GetScore();
                void SaveX();
                void SaveY();
                void RestoreX();
                void RestoreY();
                void MoveXAxis();
                void MoveYAxis();

        private:
                Texture2D spr_player;
                Vector2 position;
                int score;
                float moveSpeed;
                float gravity = 10;
                Vector2 oldPosition;
                Vector2 input = { 0.0f, 0.0f };  
};
