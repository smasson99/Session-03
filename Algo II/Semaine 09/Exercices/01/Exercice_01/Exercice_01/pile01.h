#pragma once
#include <vector>

using namespace std;

template<class TypeAMettre> class PileGenerique
{
public:
    PileGenerique();
    PileGenerique(PileGenerique& pile);
    ~PileGenerique();
    TypeAMettre Devant();
    void Depiler();
    void Empiler(const TypeAMettre& valeur);
    bool EstVide();
    size_t Dimension();
    PileGenerique<TypeAMettre>& OperatorEqual(const PileGenerique& maPile);

private:
    vector<TypeAMettre> vecteurStockage;
};

template<class TypeStockage>
PileGenerique<TypeStockage>::PileGenerique()
{

}

template<class TypeStockage>
PileGenerique<TypeStockage>::PileGenerique(PileGenerique& pile)
{
    OperatorEqual(pile);
}

template<class TypeStockage>
PileGenerique<TypeStockage>::~PileGenerique()
{
}

template<class TypeStockage>
void PileGenerique<TypeStockage>::Depiler()
{
    vecteurStockage.pop_back();
}

template<class TypeStockage>
void PileGenerique<TypeStockage>::Empiler(const TypeStockage& valeur)
{
    vecteurStockage.push_back(valeur);
}

template<class TypeStockage>
bool PileGenerique<TypeStockage>::EstVide()
{
    return vecteurStockage.size() == 0;
}

template<class TypeStockage>
size_t PileGenerique<TypeStockage>::Dimension()
{
    return vecteurStockage.capacity();
}

template<class TypeStockage>
PileGenerique<TypeStockage>& PileGenerique<TypeStockage>::OperatorEqual(const PileGenerique<TypeStockage>& maPile)
{
    vecteurStockage.operator=(maPile);
}