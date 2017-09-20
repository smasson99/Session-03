//
//  Samuel Masson (1632010)
//
//  IntVector.cpp
//  tp1
//
//          StaticAssert(cond, "message");

#include <iostream>
#include "IntVector.h"

/// <summary>
/// Fonction dont le rôle est de retourner le nombre d'entiers
/// que contient le vecteur d'entiers
/// </summary>
/// <returns>IntVector.size_type.</returns>
IntVector::size_type IntVector::size() const
{
    //Retourner la taille du vecteur d'entiers (le nombre d'entiers qu'il contient)
    return nbElem;
}

/// <summary>
/// Fonction dont le rôle est de retourne le nombre d'entiers que
/// peut contenir le vecteur d'entiers.
/// </summary>
/// <returns>IntVector.size_type.</returns>
IntVector::size_type IntVector::capacity() const
{
    //Retourner la capacité du vecteur d'entiers
    return cap;
}

/// <summary>
/// Indiquer si le vecteur d'entiers est vide ou ne l'est pas.
/// </summary>
/// <returns>booléen indiquant si le vecteur d'entiers est vide (VRAI) ou ne l'est pas (FAUX).</returns>
bool IntVector::empty() const
{
    return (nbElem == 0);
}

int& IntVector::front()
{
    return tab[0];
}

int& IntVector::back()
{
    return tab[nbElem - 1];
}

void IntVector::clear()
{
    //Reseter les valeurs par défaut
    nbElem = 0;
    cap = 50;
    tab = new int[cap];
}

int& IntVector::at(size_type index)
{
    //Retourner l'élément en cette position, s'assurant de sa validité
    try
    {
        if (index > cap)
            throw index;
    }
    catch (int e)
    {
        std::cout << "Out Of Range Exception Occured in function at(size_type index)";
    }
    return tab[index];
}

int& IntVector::operator[](int index)
{
    return tab[index];
}

void IntVector::push_back(const int& value)
{
    if (nbElem < cap)
    {
        tab[nbElem] = value;
        ++nbElem;
    }
    else //Dans ce cas-ci, nous avons défonçé la capacité
    {
        //Doubler la taille, transférer dans le nouveau tab
        reserve(cap * 2);
        push_back(value);
    }
}

/// <summary>
/// Fonction dont le rôle est de retirer le dernier élément du vecteur d'entiers et d'ainsi réduire sa taille de -1.
/// </summary>
void IntVector::pop_back()
{
    tab[nbElem] = ~int();
    nbElem -= 1;
}

/// <summary>
/// Constructeur dont le rôle est d'initialiser la classe <see cref="IntVector"/>.
/// </summary>
IntVector::IntVector()
{
    //Le vecteur est vide:
    nbElem = 0;
    //Partons avec 50 de capacité
    cap = 50;
    //Nouveau tab:
    tab = new int[cap];
}

/// <sumary>
/// Destructeur de la classe IntVector.
/// </sumary>
IntVector::~IntVector()
{
    delete[] tab;
}

/// <summary>
/// Fonction dont le rôle est d'augmenter la capacité du tableau
/// </summary>
/// <param name="new_cap">The new cap.</param>
void IntVector::reserve(size_type new_cap)
{
    //Augmentons la capacité du tableau
    int* tabTemp = new int[new_cap];
    for (int i = 0; i < new_cap; ++i)
    {
        if (i < nbElem)
        {
            tabTemp[i] = tab[i];
        }
    }
    //Assignation des nouvelles valeurs
    cap = new_cap;
    *tab = *tabTemp;
    //Nettoyage...
    delete[] tabTemp;
}

/// <summary>
/// Fonction dont le rôle est de changer la size du vecteur d'entiers.
/// </summary>
/// <param name="new_size">The new size.</param>
void IntVector::resize(size_type new_size)
{
    //Changer la size
    if (new_size > cap)
    {
        reserve(cap * 2);
        resize(new_size);
    }
    else
    {
        nbElem = new_size;
    }
}

IntVector::IntVector(const IntVector& other)
{
    nbElem = 0;
    cap = 50;
    tab = new int[cap];
    operator=(other);
}

IntVector& IntVector::operator=(const IntVector &other)
{
    resize(other.size());
    for (int i = 0; i < other.size(); ++i)
    {
        push_back(other.tab[i]);
    }
    return *this;
}