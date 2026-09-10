#pragma once
#include <raylib.h>
class Enemy {
        public:
                Enemy();
                ~Enemy();
                void Update(); 
                void Draw();
                Rectangle GetRect();
        
        private:
                Vector2 position;
                Texture2D spr_enemy;
                int speed;
                bool isGoingRight = true;
};
