#include <QApplication>
#include <iostream>
#include "list_test.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    int result = 0;

    result |= QTest::qExec(new ListTest(), argc, argv);
    std::cout << std::endl;

    return result;
}
