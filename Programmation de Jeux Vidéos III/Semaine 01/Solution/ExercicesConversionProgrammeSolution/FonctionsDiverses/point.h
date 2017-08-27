//#pragma once
// ou
#ifndef POINT_H_
#define POINT_H_
namespace FonctionsDiverses
{
  class Point
  {
    public:
      Point();
      Point(int newX, int newY);

      int GetX();
      int GetY();
      float GetDistanceToOrigin();

    private:
      int x;
      int y;
  };
}

#endif //POINT_H_