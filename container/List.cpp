#include "List.h";


template <typename T>
List<T>::List(Elem<T>* e){
	this->head = e;
}
template <typename T>
List<T>::~List(){
	delete(head);
	this->head = null;
}
template <typename T>
Elem<T>* List<T>::getHead(){
	return head;
}
template <typename T>
void List<T>::setHead(Elem<T>* head){
	this->head = head;
}
template <typename T>
void List<T>::addElem(T value){
	Elem<T> elem = new Elem(value, head);
	head = elem;
}
template <typename T>
Elem<T>* List<T>::getElem(int i){
	Elem<T> iter = head;
	int k = 0;
	while (iter!= 0)
	{
		if (k == i)
		{
			return iter;
		}
		iter = iter->getNext();
		k++;
	}
	return null;
}
template <typename T>
bool List<T>::isEmpty(){
	return (head == null);
}
template <typename T>
int List<T>::size(){
	Elem<T> iter = head;
	int k = 0;
	while (iter != 0)
	{
		
		iter = iter->getNext();
		k++;
	}
	return k;
}








