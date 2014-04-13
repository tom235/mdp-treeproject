#pragma once
#include "List.h"
template <class T>
class OATree{

private:
	bool or; // тип вершины (isOr -> ИЛИ)
	T value; // значение вершины
	List<OATree<T>> *elems; // список подвершин данной вершины
public:
	OATree();
	OATree(T, bool, List<OATree<T>>*);
	~OATree();
	// getters
	List<OATree<T>>* getElems();
	T getValue();
	bool isOr();

	//setters 
	void setElems(List<OATree<T>>*);
	void setIsOr(bool);
	void setValue(T);
};

template <class T>
OATree<T>::OATree()
{

}

template <class T>
OATree<T>::OATree(T value, bool or, List<OATree>* elems){
	this->value = value;
	this->or = or;
	this->elems = elems;
}

template <class T>
OATree<T>::~OATree(){

}
// getters
template <class T>
List<OATree<T>>* OATree<T>::getElems(){
	return elems;
}

template <class T>
T OATree<T>::getValue(){
	return value;
}

template <class T>
bool OATree<T>::isOr(){
	return or;
}

//setters 
template <class T>
void OATree<T>::setElems(List<OATree<T>>* elems){
	this->elems = elems;
}

template <class T>
void OATree<T>::setIsOr(bool or){
	this->or = or;
}

template <class T>
void OATree<T>::setValue(T value){
	this->value = value;
}
