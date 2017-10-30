#pragma once
#include <SFML\Graphics.hpp>

using namespace sf;

namespace platformer
{
    class Animation
    {
    public:
        Animation(Texture& textureSheet, float duration, bool isCircular);
        float GetDuration();
        float GetFrameHeight();
        float GetFrameWidth();
        int GetFrameCount();
        bool IsCircularAnimation();
    private:
        Texture textureSheet;
        float duration;
        bool isCircular;
    };
}