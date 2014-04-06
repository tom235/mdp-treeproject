

template <typename T>
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