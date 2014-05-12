#include "usermanualbrowser.h"


    #include <QtWidgets>
#include <QTextCodec>
    #include <QtGui>

// ----------------------------------------------------------------------
UserManualBrowser::UserManualBrowser(const QString& strPath,
                                     const QString& strFileName,
                                     QWidget *parent) :
    QWidget(parent)
{
    QPushButton  *backBtn    = new QPushButton("<<");
    QPushButton  *homeBtn    = new QPushButton("Домой");
    QPushButton  *forwardBtn = new QPushButton(">>");
    QTextBrowser *browser    = new QTextBrowser;

    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");

    connect(backBtn,    SIGNAL(clicked()), browser, SLOT(backward()));
    connect(homeBtn,    SIGNAL(clicked()), browser, SLOT(home()));
    connect(forwardBtn, SIGNAL(clicked()), browser, SLOT(forward()));

    connect(browser, SIGNAL(backwardAvailable(bool)), backBtn,    SLOT(setEnabled(bool)));
    connect(browser, SIGNAL(forwardAvailable(bool)),  forwardBtn, SLOT(setEnabled(bool)));

    browser->setSearchPaths(QStringList() << strPath);
    browser->setSource(QString(strFileName));

    QVBoxLayout *vBoxLayout = new QVBoxLayout;
    QHBoxLayout *hBoxLayout = new QHBoxLayout;

    hBoxLayout->addWidget(backBtn);
    hBoxLayout->addWidget(homeBtn);
    hBoxLayout->addWidget(forwardBtn);

    vBoxLayout->addLayout(hBoxLayout);
    vBoxLayout->addWidget(browser);

    setLayout(vBoxLayout);


    setWindowTitle("Пользовательская документация");
    setWindowIcon(QIcon(":/images/logo.png"));
}
