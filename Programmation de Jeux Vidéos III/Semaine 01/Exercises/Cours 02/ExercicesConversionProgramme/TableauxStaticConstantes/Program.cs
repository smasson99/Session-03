using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TableauxStaticConstantes
{
  class Program
  {
    const int NB_ELEMENTS_TABLEAUX = 10;
    static void Main(string[] args)
    {
      int[] tab = new int[NB_ELEMENTS_TABLEAUX];
      InitialiserTableau(tab);

      string tabContent = "";
      for(int i=0;i<tab.Length;i++)
      {
        tabContent += tab[i] + " ";
      }

      Console.WriteLine("Le contenu du tableau est: " + tabContent);
    }

    static void InitialiserTableau(int[] tab)
    {
      Random rnd = new Random();
      for (int i = 0; i < tab.Length; i++)
      {
        tab[i] = rnd.Next(0, 10);
      }
    }
  }
}
