#include "Projectile.h"

Projectile::Projectile(float x, float y, float angle, bool isRadian)
{
    bool initialised = Init("Sprites\\Projectiles\\Missile.png");
    if (initialised == false)
    {
        std::cout << "Attention, sprite de projectiles pas trouvée." << std::endl;
    }
    this->angle = angle;
    SetRotation(angle, isRadian);
    this->speed = 20.00f;
    Movable::SetPosition(x, y);
    dir = Movable::GenerateDirection(angle, isRadian);
}

void Projectile::Update()
{
    SetPosition(GetX()+(dir.x*speed), GetY()+(dir.y*speed));
}