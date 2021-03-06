#pragma once
#include "Animation.h"


using namespace platformer;
using namespace sf;

namespace platformer
{
    class AnimationPlayer
    {
    public:
        AnimationPlayer();
        void Play(Animation* animation);
        IntRect GetRect();
    private:
        Animation* animation;
        Clock frameClock;
        Time frameDelay;
        int frameIndex;
        IntRect* cadres; /*Trouver moyen de d�truire  correctement*/
        bool isGoingRight;
    };
}