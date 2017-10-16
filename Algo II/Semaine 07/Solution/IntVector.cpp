//
//  Prénom Nom (MATRICULE) TODO: a modifier
//
//  IntVector.cpp
//  tp1
//

#include <cassert>
#include "IntVector.h"

IntVector::size_type IntVector::size() const
{
    return nbElem;
}

IntVector::size_type IntVector::capacity() const
{
    return cap;
}

bool IntVector::empty() const
{
    return nbElem == 0;
}

int& IntVector::front()
{
    return tab[0];
}

int& IntVector::back()
{
	return tab[nbElem-1];
}

void IntVector::clear()
{
	nbElem = 0;
	cap = 0;
	delete[] tab;
	tab = nullptr;
}

int& IntVector::at(size_type index)
{
	assert(index < nbElem);
    return tab[index];
}

void IntVector::push_back(const int& value)
{
	if (nbElem == cap)
		reserve(2 * cap + 1);

	tab[nbElem] = value;
	nbElem++;
}

void IntVector::pop_back()
{
	nbElem--;
	tab[nbElem] = int();
}

IntVector::IntVector()
	: tab(nullptr)
	, nbElem(0)
	, cap(0)
{
}

IntVector::~IntVector()
{
	clear();
}

void IntVector::reserve(size_type new_cap)
{
	if (cap < new_cap)
	{
		auto tmp = tab;
		tab = new int[new_cap];

		size_type i = 0;

		for (; i < nbElem; ++i)
			tab[i] = tmp[i];

		for (; i < new_cap; ++i)
			tab[i] = int();

		cap = new_cap;
	}
}


void IntVector::resize(size_type new_size)
{
	reserve(new_size);

	for (size_type i = new_size - 1; i < nbElem; ++i)
		tab[i] = int();

	nbElem = new_size;
}

IntVector::IntVector(const IntVector& other)
{
	*this = other;
}

IntVector& IntVector::operator=(const IntVector &other)
{
	resize(other.nbElem);

	for (size_type i = 0; i < other.nbElem; ++i)
		tab[i] = other.tab[i];

    return *this;
}