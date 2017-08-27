#pragma once
//Les includes:
#include <math.h>
//Les includes standards (vide):

class Point
{

private:
    //Variables:
    int x;
    int y;
    //Méthodes (vide):

public:
    //Variables: (vide)

    //Méthodes:
    int GetX();
    int GetY();
    Point();
    Point(int newX, int newY);
    float GetDistanceToOrigin();

};