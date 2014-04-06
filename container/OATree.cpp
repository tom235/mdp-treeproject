#include "OATree.h"


template <typename T>
OATree<T>::OATree(T value, bool or, List<OATree>* elems){
	this->value = value;
	this->or = or;
	this->elems = elems;
}

template <typename T>
OATree<T>::~OATree(){

}
// getters
template <typename T>
List<OATree<T>>* OATree<T>::getElems(){

}

template <typename T>
T OATree<T>::getValue(){
	return value;
}

template <typename T>
bool OATree<T>::isOr(){
	return or;
}

//setters 
template <typename T>
void OATree<T>::setElems(List<OATree<T>>* elems){
	this->elems = elems;
}

template <typename T>
void OATree<T>::setIsOr(bool or){
	this->or = or;
}

template <typename T>
void OATree<T>::setValue(T value){
	this->value = value;
}
