#ifndef USERMANUALBROWSER_H
#define USERMANUALBROWSER_H


    #include <QtWidgets>

    #include <QtGui>

class UserManualBrowser : public QWidget
{
    Q_OBJECT
public:
    explicit UserManualBrowser(const QString&, const QString&, QWidget *parent = 0);
    
};

#endif // USERMANUALBROWSER_H
