#pragma once

template <class T>
class Elem{
private:
	T value;
	Elem<T> *next;
public:
	Elem(T value, Elem<T>* next);
	~Elem();
	T getValue();
	Elem<T> *getNext();
	void setValue(T);
	void setNext(Elem<T>*);
	
};


template <class T>
Elem<T>::Elem(T value, Elem<T>* next){
	this->next = next;
	this->value = value;
}

template <class T>
Elem<T>::~Elem(){
	delete[] next;
}
template <class T>
T Elem<T>::getValue(){
	return value;
}
template <class T>
Elem<T> * Elem<T>::getNext(){
	return next;
}
template <class T>
void Elem<T>::setValue(T value){
	this->value = value;
}
template <class T>
void Elem<T>::setNext(Elem<T>* next){
	this->next = next;
}