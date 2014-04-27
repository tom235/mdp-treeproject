#ifndef TPI_H
#define TPI_H

#include "OATree.h"
#include "TreeIterator.h"
#include <stack>
template <class T>
class Iterator : TreeIterator{
private:
	OATree<T> *current;
	std::stack<OATree<T>> rootStack();
public:
	Iterator(OATree<T>*);
	bool next();
	bool hasNext();
	OATree<T>* getCurrent();

};



template <class T>
Iterator<T>::Iterator(OATree<T>* collection)
{
	this->current = collection;
	if (current == 0) return;
	
}

template <class T>
bool Iterator<T>::next()
{
	if (current == 0)
		return false;
	if (!current->getElems()->isEmpty())
	{

	}
	return 0;
}

template <class T>
bool Iterator<T>::hasNext()
{

	return 0;
}

template <class T>
OATree<T>* Iterator<T>::getCurrent()
{
	return current;
}

#endif
