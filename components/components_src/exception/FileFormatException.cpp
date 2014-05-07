#include "FileFormatException.h"



FileFormatException::FileFormatException(const QString& num, int type):
    _num(num),
    _type(type)
{

}



QString FileFormatException::getMsg() const
{
    switch (_type) {
    case 0:
        return "Ошибка во входном файле в строке " + _num;
    case 1:
        return "Ошибка во входном файле на позиции " + _num;
    default:
        return "Ошибка во входном файле";
    }
}
