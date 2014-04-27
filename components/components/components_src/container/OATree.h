#ifndef OATREE_H
#define OATREE_H
#include "List.h"

template <class T>
class OATree{

private:
    bool b_or;
	T value; // vertice value
    List<OATree<T> > *elems; // list of subelems
public:
	OATree();
    OATree(T, bool, List<OATree<T> >*);
	~OATree();
	// getters
    List<OATree<T> >* getElems();
	T getValue();
	bool isOr();

	//setters 
    void setElems(List<OATree<T> >*);
	void setIsOr(bool);
	void setValue(T);
	bool containsValue(T prop,T value);
};

template <class T>
OATree<T>::OATree()
{

}

template <class T>
OATree<T>::OATree(T value, bool b_or, List<OATree>* elems){
	this->value = value;
    this->b_or = b_or;
	this->elems = elems;
}

template <class T>
OATree<T>::~OATree(){
	delete elems;
	elems = 0;
}
// getters
template <class T>
List<OATree<T> >* OATree<T>::getElems(){
	return elems;
}

template <class T>
T OATree<T>::getValue(){
	return value;
}

template <class T>
bool OATree<T>::isOr(){
    return b_or;
}

//setters 
template <class T>
void OATree<T>::setElems(List<OATree<T> >* elems){
	this->elems = elems;
}

template <class T>
void OATree<T>::setIsOr(bool b_or){
    this->b_or = b_or;
}

template <class T>
void OATree<T>::setValue(T value){
	this->value = value;
}

template <class T>
bool OATree<T>::containsValue(T prop,T value)
{
	if (this->elems == 0) return false;
	if (prop == this->getValue())
	{
		
        Elem<OATree<std::string> >* iterator = this->elems->getHead();
		
		while (iterator != 0)
		{
			
			if (iterator->getValue().getValue() == value) return true;
			iterator = iterator->getNext();
		}
		return false;
		
	}
	else
	{
        Elem<OATree<std::string> >* iterator = this->elems->getHead();
		
		while (iterator != 0)
		{

			bool b = iterator->getValue().containsValue(prop, value);
			if (b) return true;
			iterator = iterator->getNext();
		}
		return false;
	}
	
}
#endif
