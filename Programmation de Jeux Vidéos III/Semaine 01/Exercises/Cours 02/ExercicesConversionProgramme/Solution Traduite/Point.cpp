//Les includes:
#include <Math>
//Les includes standards:
#include "point.h";

//Contenu:
class Point
{

private:
    //Variables:
    int x = 0;
    int y = 0;
    //Méthodes: (vide)

public:
    //Variables: (vide)
    int GetX()
    {
        return x;
    }

    int GetY()
    {
        return y;
    }

    Point()
    {
        x = 0;
        y = 0;
    }

    float GetDistanceToOrigin()
    {
        //return (float)
    }
};