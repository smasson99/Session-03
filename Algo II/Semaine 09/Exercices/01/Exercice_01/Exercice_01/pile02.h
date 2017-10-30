#pragma once

using namespace std;

template<class TypeStock>
class IntTab
{
public:
    IntTab(int& cap);
    IntTab(IntTab& instance)
    ~IntTab();
    void AddValue(TypeStock& value);
    void AddReplace(int& indexPos, TypeStock& value);
    void Insert(int& indexPos, TypeStock& value);
    void RemoveFront();
    void RemoveBack();
    TypeStock Get(int index);
    TypeStock* GetRange(int from, int to);
private:
    TypeStock* tab;
};

template<class TypeStock>
IntTab<TypeStock>::IntTab(int& cap)
{

}

template<class TypeStock>
IntTab<TypeStock>::IntTab(IntTab& instance)
{

}

template<class TypeStock>
IntTab<TypeStock>::~IntTab()
{

}

template<class TypeStock>
void IntTab<TypeStock>::AddValue(TypeStock& value)
{

}

template<class TypeStock>
void IntTab<TypeStock>::AddReplace(int& indexPos, TypeStock& value)
{

}

template<class TypeStock>
void IntTab<TypeStock>::Insert(int& indexPos, TypeStock& value)
{

}

template<class TypeStock>
void IntTab<TypeStock>::RemoveFront()
{

}

template<class TypeStock>
void IntTab<TypeStock>::RemoveBack()
{

}

template<class TypeStock>
TypeStock IntTab<TypeStock>::Get()
{

}

template<class TypeStock>
TypeStock* IntTab<TypeStock>::GetRange()
{
    return tab;
}