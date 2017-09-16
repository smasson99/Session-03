//
//  Samuel Masson (1632010)
//
//  IntVector.cpp
//  tp1
//

#ifndef _INTVECTOR_H_
#define _INTVECTOR_H_

class IntVector
{
public:
    //Ici je me définis un type non signé pour les indices et grandeurs.
    using size_type = unsigned long;
    
    //Constructeur & destructeur
    IntVector();
    IntVector(const IntVector& other);
    ~IntVector();
    
    
    IntVector& operator=(const IntVector& );
    
    //Accesseur
    int& at(size_type);
    int& operator[](int index);
    int& front();
    int& back();
    
    //Capacité
    bool empty() const;
    size_type size() const;
    void reserve(size_type);
    size_type capacity() const;
    
    //Modificateur
    void clear();
    void push_back(const int& );
    void pop_back();
    void resize(size_type);
    
    void afficher();
    
private:
    //TODO: Après avoir complété la première partie, changer la représentation
    //      pour quelque chose de dynamique.
    int* tab = new int[50];
    size_type nbElem = 10;
    size_type cap = 50;
    
    //TODO: variable à enlever. Ne sert qu'a vous donner un front() et back()
    //      de départ qui retourne une valeur quelquonque.
    int first = -42, last = 42;
    
}; //class IntVector_fbr


#endif /* IntVector_h */
