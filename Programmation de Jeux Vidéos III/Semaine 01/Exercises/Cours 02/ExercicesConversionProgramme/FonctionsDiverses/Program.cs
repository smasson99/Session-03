using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FonctionsDiverses
{
  class Program
  {
    static void Main(string[] args)
    {
      Point p1 = new Point();
      Random rnd = new Random();
      int p2X = rnd.Next(0,65535);
      int p2Y = rnd.Next(0, 65535);
      Point p2 = new Point(p2X, p2Y);

      Console.WriteLine("La distance entre le point 1 et l'origine est: " +  p1.GetDistanceToOrigin());
      Console.WriteLine("La distance entre le point 2 et l'origine est: " + p2.GetDistanceToOrigin());

    }
  }
}
