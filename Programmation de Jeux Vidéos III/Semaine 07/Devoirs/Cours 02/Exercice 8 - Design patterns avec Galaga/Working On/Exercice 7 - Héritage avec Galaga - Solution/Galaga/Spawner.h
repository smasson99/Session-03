#pragma once

#include <SFML/Graphics.hpp>

namespace galaga
{
    class Spawner
    {
    public:
        Spawner();
        void SetPosition(float x, float y);
        void Draw(sf::RenderWindow& mainWin);
        float GetDisplacement();
        void AutoMoveX(bool right);
        float GetX();
        float GetY();
    private:
        sf::CircleShape myCircleShape;
        const float RAYON = 25;
        const float TICKNESS = 3;
        const float DISPLACEMENT = 3;
    };
}
