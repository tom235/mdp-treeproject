#pragma once
#include "Elem.h"


template <class T>
class List{
private:
	Elem<T> *head;
public:
	List(Elem<T>*);
	List();
	~List();
	Elem<T>* getHead();
	void setHead(Elem<T>*);
	void addElem(T);
	Elem<T>* getElem(int);
	bool isEmpty();
	int size();
};

template<class T>
List<T>::List(){
	head = 0;
}

template <class T>
List<T>::List(Elem<T>* e){
	this->head = e;
}
template <class T>
List<T>::~List(){
	delete(head);
	this->head = null;
}
template <class T>
Elem<T>* List<T>::getHead(){
	return head;
}
template <class T>
void List<T>::setHead(Elem<T>* head){
	this->head = head;
}
template <class T>
void List<T>::addElem(T value){
	Elem<T> *elem = new Elem<T>(value, 0);
	if (head == 0)
	{
		head = elem;
	}
	else
	{
		Elem<T> *iter = head;
		while (iter->getNext() != 0)
		{
			iter = iter->getNext();
		}
		iter->setNext(elem);
	}
	
	
}



template <class T>
Elem<T>* List<T>::getElem(int i){
	Elem<T>* iter = head;
	int k = 0;
	while (iter != 0)
	{
		if (k == i)
		{
			return iter;
		}
		iter = iter->getNext();
		k++;
	}
	return NULL;
}
template <class T>
bool List<T>::isEmpty(){
	return (head == null);
}
template <class T>
int List<T>::size(){
	Elem<T> *iter = head;
	int k = 0;
	while (iter != 0)
	{

		iter = iter->getNext();
		k++;
	}
	return k;
}
