#pragma once


/// <summary>
/// 
/// </summary>
class CollisionSphere
{
  public:
  CollisionSphere();

  bool CheckCollisionWith(CollisionSphere& other) const;
  
  float GetRadius() const;
  float GetPosX() const;
  float GetPosY() const;

private:
  void Randomize();
  float radius;
  float posX;
  float posY;

};

