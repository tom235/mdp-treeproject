
#include "Elem.h"




template <typename T>
class List{
private:
	Elem<T> *head;
public:
	List(Elem<T>*);
	~List();
	Elem<T>* getHead();
	void setHead(Elem<T>*);
	void addElem(T);
	Elem<T>* getElem(int);
	bool isEmpty();
	int size();
	




};