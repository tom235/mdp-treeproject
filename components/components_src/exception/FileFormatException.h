#ifndef FILEFORMATEXCEPTION_H
#define FILEFORMATEXCEPTION_H

#include "Exception.h"

class FileFormatException : public Exception
{
private:
   QString _num;
   int _type;
public:
    FileFormatException(const QString& num, int type = 0);

    QString getMsg() const;

};

#endif // FILEFORMATEXCEPTION_H
