#include "CollisionSphere.h"

namespace FormesGeo
{
    float x;
    float y;
    float rayon;

    CollisionSphere::CollisionSphere()
    {
        x = 0;
        y = 0;
        rayon = 1;
    }

    CollisionSphere::CollisionSphere(float x, float y, float rayon)
    {
        this->x = x;
        this->y = y;
        this->rayon = rayon;
    }

    void CollisionSphere::SetPosition(float x, float y)
    {
        this->x = x;
        this->y = y;
    }

    float CollisionSphere::GetRayon()
    {
        return rayon;
    }

    float CollisionSphere::GetX()
    {
        return x;
    }

    float CollisionSphere::GetY()
    {
        return y;
    }
}