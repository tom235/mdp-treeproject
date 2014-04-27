#ifndef LIST_TEST_H
#define LIST_TEST_H

#include <QString>
#include <QtTest>
#include "../components_src/container/List.h"

class ListTest: public QObject
{
    Q_OBJECT
public:
    explicit ListTest(QObject *parent = 0);

private Q_SLOTS:
    void elemInitTest();
    void setNextTest();
    void listAddElemTest();
    void listGetNullTest();
    void listGetNoNullTest();
};

#endif // LIST_TEST_H
