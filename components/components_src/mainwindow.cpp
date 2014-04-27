#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "container/ComponentOutIn.h"
#include <vector>
#include "qstandarditemmodel.h"
#include "QString.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initCompList();
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(message()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::message()
{
    ui->label->setText("asdsad");
}

void MainWindow::initCompList()
{
    std::vector<MotherBoard> mb;
    std::vector<VideoCard> vc;
    std::vector<Cpu> cp;
    std::vector<Ram> ram;
    ComponentOutIn::readComponents(ram,vc,mb,cp,"out.txt");
    std::cout << mb.size();
    QStandardItemModel *stdModel = new QStandardItemModel(ui->listView);

    for(int i=0;i<mb.size();i++)
    {
         std::cout << mb.at(i).getName() << std::endl;
         stdModel->appendRow(new QStandardItem(QString::fromStdString(mb.at(i).getName())));
    }
    //ui->listView->selectAll("MotherBoard");
}
