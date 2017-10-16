//
//  Prénom Nom (MATRICULE) TODO: a modifier
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
    int *tab;
    size_type nbElem;
    size_type cap;
}; //class IntVector_fbr


#endif /* IntVector_h */
