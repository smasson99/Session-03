#include "AnimationPlayer.h"

AnimationPlayer::AnimationPlayer()
{
    frameIndex = 2;
}

void AnimationPlayer::Play(Animation* animation)
{
    //if (animation == this->animation)
    this->animation = animation;

    //Calculer le rect selon la frame
    cadres = new IntRect[animation->GetFrameCount()];
    for (size_t i = 0; i < animation->GetFrameCount(); ++i)
    {
        cadres[i].left = animation->GetFrameWidth()*i;
        cadres[i].top = animation->GetFrameHeight()*i;
        cadres[i].width = animation->GetFrameWidth();
        cadres[i].height = animation->GetFrameHeight();
    }
    if (!animation->IsCircularAnimation())
        isGoingRight = true;
    frameDelay = seconds(animation->GetDuration());
    if (frameClock.getElapsedTime().asSeconds() >= frameDelay.asSeconds())
        frameClock.restart();
}

IntRect AnimationPlayer::GetRect()
{
    if (frameClock.getElapsedTime().asSeconds() >= frameDelay.asSeconds())
    {
        if (animation->IsCircularAnimation() == false || (animation->IsCircularAnimation() && isGoingRight))
        {
            ++frameIndex;
        }
        else if (animation->IsCircularAnimation() && !isGoingRight)
        {
            --frameIndex;
        }
        if (frameIndex < animation->GetFrameCount() - 1 && animation->IsCircularAnimation())
        {
            ++frameIndex;
        }
        else if (!animation->IsCircularAnimation())
        {
            if (frameIndex <= 0)
            {
                isGoingRight = true;
                frameIndex = 0;
            }
            else if (frameIndex > animation->GetFrameCount()-1)
            {
                isGoingRight = false;
                frameIndex = animation->GetFrameCount()-1;
            }
        }
    }
    return cadres[frameIndex];
}
