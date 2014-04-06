#include "Elem.h";





template <typename T>
Elem<T>::Elem(T value, Elem<T>* next){
	this->next = next;
	this->value = value;
}

template <typename T>
Elem<T>::~Elem(){

}
template <typename T>
T Elem<T>::getValue(){
	return value;
}
template <typename T>
Elem<T> * Elem<T>::getNext(){
	return next;
}
template <typename T>
void Elem<T>::setValue(T value){
	this->value = value;
}
template <typename T>
void Elem<T>::setNext(Elem<T>* next){
	this->next = next;
}
