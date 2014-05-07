#ifndef EXCEPTION_H
#define EXCEPTION_H

#include<QString>

class Exception
{
public:
    virtual QString getMsg() const = 0;
};

#endif // EXCEPTION_H
