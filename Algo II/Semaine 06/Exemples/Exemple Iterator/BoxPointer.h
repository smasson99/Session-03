//
//  BoxPointer.h
//  exo_iterator
//
//  Created by François Bélanger on 17-09-26.
//  Copyright © 2017 François Bélanger. All rights reserved.
//

#ifndef BoxPointer_h
#define BoxPointer_h

struct Boite
{
    int valeur;
    Boite *suivant;
    
    Boite(const int v, Boite *next = nullptr):valeur(v), suivant(next){}
};

class DataStructure
{
    Boite* box;
    
public:
    using size_type = unsigned long;
    class iterator;
    
    DataStructure():box(int ()){}
    
    ~DataStructure()
    {
        //TODO: a completer
        Boite* temp = box;
        bool hasDeleted = false;
        while (box != int())
        {
            
            box = box->suivant;
            delete temp;               
        }

    }
    
    void add(const int valeur)
    {
        box = new Boite(valeur, box);
    }
    
    iterator begin();
    iterator end();
    
};

class DataStructure::iterator
{
    //TODO: a completer

};

#endif /* BoxPointer_h */
