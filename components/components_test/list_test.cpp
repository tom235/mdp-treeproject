#include "list_test.h"

ListTest::ListTest(QObject *parent):QObject(parent)
{
}

void ListTest::elemInitTest()
{
    int initValue = 50;
    Elem<int> *elem = new Elem<int>(50, 0);
    QCOMPARE(initValue,elem->getValue());
}

void ListTest::setNextTest()
{
    int thirdValue = 3;

    Elem<int> *first = new Elem<int>(1, 0);
    Elem<int> *second = new Elem<int>(2, 0);
    Elem<int> *third = new Elem<int>(thirdValue, 0);
    first->setNext(second);
    second->setNext(third);

    Elem<int> *iter = first;

    QCOMPARE(iter->getNext()->getNext()->getValue(), thirdValue);
}

void ListTest::listAddElemTest()
{
    List<int> *list = new List<int>();

    int size = 3;

    for (int i = 0; i < 3; i++)
        list->addElem(i);
    QCOMPARE(3, list->size());
}
void ListTest::listGetNullTest()
{
    List<int> *list = new List<int>();
    list->addElem(3);

    QVERIFY(list->getElem(-50) == NULL);
}

void ListTest::listGetNoNullTest()
{
    List<int> *list = new List<int>();
    list->addElem(3);

    QVERIFY(list->getElem(0) != NULL);
}

