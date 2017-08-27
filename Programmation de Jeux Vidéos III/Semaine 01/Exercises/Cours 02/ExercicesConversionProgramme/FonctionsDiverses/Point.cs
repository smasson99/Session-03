using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FonctionsDiverses
{
  class Point
  {
    private int x=0;
    private int y=0;

    public int GetY()
    {
      return y;
    }

    public int GetX()
    {
      return x;
    }

    public Point()
    {
      x = 0;
      y = 0;
    }

    public Point(int newX, int newY)
    {
      x = newX;
      y = newY;
    }

    public float GetDistanceToOrigin()
    {
      return (float)Math.Sqrt(x * x + y * y);
    }

  }
}
