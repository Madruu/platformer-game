#pragma once
#include<raylib.h>

class Coin {
        public:
                Coin() = default;
                Coin(Vector2 position);
                void Update();
                void Draw();
                Rectangle GetRect();
                int GetValue();

        private:
                int value;
                Texture2D spr_coin;
                Vector2 position;
};      
