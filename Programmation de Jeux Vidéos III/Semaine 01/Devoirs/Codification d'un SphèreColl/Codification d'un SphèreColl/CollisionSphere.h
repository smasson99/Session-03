//#pragma once

#ifndef CollSphere
#define CollSphere
namespace FormesGeo
{
    class CollisionSphere
    {
    private:
        float x;
        float y;
        float rayon;

    public:
        CollisionSphere();
        CollisionSphere(float x, float y, float rayon);
        void SetPosition(float x, float y);
        float GetRayon();
        float GetX();
        float GetY();
    };
}
#endif // !CollSphere