
#include "List.h"
template <typename T>
class OATree{

private:
	bool or; // ��� ������� (isOr -> ���)
	T value; // �������� �������
	List<OATree<T>> *elems; // ������ ��������� ������ �������
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

