
#include "List.h"
template <typename T>
class OATree{

private:
	bool or; // тип вершины (isOr -> ИЛИ)
	T value; // значение вершины
	List<OATree<T>> *elems; // список подвершин данной вершины
public:
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

