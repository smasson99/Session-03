//
//  TableauWrapper.h
//  exo_iterator
//
//  Created by François Bélanger on 17-09-26.
//  Copyright © 2017 François Bélanger. All rights reserved.
//

#ifndef TableauWrapper_h
#define TableauWrapper_h

class Tableau
{
public:
    using size_type = unsigned long;
    class iterator;
    
    Tableau() : size(0)
    {
        tab = new int[1000];
    }
    
    ~Tableau()
    {
        delete[] tab;
        tab = nullptr;
        size = 0;
    }
    
    void add(const int valeur)
    {
        if(size < 1000)
        {
            tab[size] = valeur;
            size++;
        }
    }
    
    iterator begin();
    iterator end();
    
private:
    int *tab;
    size_type size;
};

class Tableau::iterator
{
    friend Tableau;
    
private:
    int *pos;
    
public:
    iterator(int *p=nullptr): pos(p){}
    
    int& operator*();
    
    iterator operator++()
    {
        return iterator(++pos);
    }
    
    bool operator==(const iterator& droite){return pos==droite.pos;}
    bool operator!=(const iterator& droite){return pos!=droite.pos;}
};

Tableau::iterator Tableau::begin(){
    return Tableau::iterator(tab);
}
Tableau::iterator Tableau::end(){
    return Tableau::iterator(tab+size);
}

int& Tableau::iterator::operator*(){
    return *pos;
}
#endif /* TableauWrapper_h */
