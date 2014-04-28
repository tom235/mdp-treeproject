#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "container/ComponentOutIn.h"
#include "adddialog.h"
#include "QRegExp"
#include "QString.h"
#include "QFileDialog"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   initCompList();
   setWindowTitle("Комплектующие");
   QObject::connect(ui->listView, SIGNAL(clicked(QModelIndex)),this, SLOT(updateProp(QModelIndex)));
   QObject::connect(ui->pushButton_3, SIGNAL(clicked()),this, SLOT(removeItem()));
   QObject::connect(ui->pushButton_4, SIGNAL(clicked()),this, SLOT(loadFromFile()));
   QObject::connect(ui->pushButton_5, SIGNAL(clicked()),this, SLOT(saveToFile()));
   QObject::connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(showAddDlg()));
   QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(showEditDlg()));
   QObject::connect(ui->lineEdit, SIGNAL(textChanged(QString)),this, SLOT(search(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initCompList()
{



    std::cout << mb.size();
    listModel = new QStandardItemModel();
    listModel_3 = new QStandardItemModel();

    for(int i=0;i<mb.size();i++)
    {
         if(QString::fromStdString(mb.at(i).getName()).contains(searchStr))
            listModel->appendRow(new QStandardItem(QString::fromStdString(mb.at(i).getName())));
    }
    for(int i=0;i<cp.size();i++)
    {
         if(QString::fromStdString(cp.at(i).getName()).contains(searchStr))
            listModel->appendRow(new QStandardItem(QString::fromStdString(cp.at(i).getName())));
    }
    for(int i=0;i<vc.size();i++)
    {
        if(QString::fromStdString(vc.at(i).getName()).contains(searchStr))
            listModel->appendRow(new QStandardItem(QString::fromStdString(vc.at(i).getName())));
    }
    for(int i=0;i<ram.size();i++)
    {
        if(QString::fromStdString(ram.at(i).getName()).contains(searchStr))
             listModel->appendRow(new QStandardItem(QString::fromStdString(ram.at(i).getName())));
    }
     ui->listView->setModel(listModel);
    //ui->listView->selectAll("MotherBoard");
}

void MainWindow::updateProp(QModelIndex id)
{
  QString itemStr = listModel->itemFromIndex(id)->text();
  listModel_3->clear();
    for(int i=0;i<mb.size();i++)
    {
       if(QString::fromStdString(mb.at(i).getName())==itemStr)
       {
           listModel_3->appendRow(new QStandardItem("Name: "+QString::fromStdString(mb.at(i).getName())));
           listModel_3->appendRow(new QStandardItem("Producer: "+QString::fromStdString(mb.at(i).getProducer())));
           listModel_3->appendRow(new QStandardItem("Ram type: "+QString::fromStdString(mb.at(i).getRamType())));
           listModel_3->appendRow(new QStandardItem("MaxAmountMemory: "+QString::number(mb.at(i).getMaxAmountMemory())));
       }
    }
    for(int i=0;i<cp.size();i++)
    {
       if(QString::fromStdString(cp.at(i).getName())==itemStr)
       {
           listModel_3->appendRow(new QStandardItem("Name: "+QString::fromStdString(cp.at(i).getName())));
           listModel_3->appendRow(new QStandardItem("Producer: "+QString::fromStdString(cp.at(i).getProducer())));
           listModel_3->appendRow(new QStandardItem("Frequency: "+QString::number(cp.at(i).getFrequnce())));
           listModel_3->appendRow(new QStandardItem("Core Amount: "+QString::number(cp.at(i).getCoreAmount())));
       }
    }
    for(int i=0;i<ram.size();i++)
    {
       if(QString::fromStdString(ram.at(i).getName())==itemStr)
       {
           listModel_3->appendRow(new QStandardItem("Name: "+QString::fromStdString(ram.at(i).getName())));
           listModel_3->appendRow(new QStandardItem("Producer: "+QString::fromStdString(ram.at(i).getProducer())));
           listModel_3->appendRow(new QStandardItem("Frequency: "+QString::number(ram.at(i).getFrequnce())));
           listModel_3->appendRow(new QStandardItem("Type: "+QString::fromStdString(ram.at(i).getType())));
       }
    }
    for(int i=0;i<vc.size();i++)
    {
       if(QString::fromStdString(vc.at(i).getName())==itemStr)
       {
           listModel_3->appendRow(new QStandardItem("Name: "+QString::fromStdString(vc.at(i).getName())));
           listModel_3->appendRow(new QStandardItem("Producer: "+QString::fromStdString(vc.at(i).getProducer())));
           listModel_3->appendRow(new QStandardItem("Ram: "+QString::number(vc.at(i).getRam())));
           listModel_3->appendRow(new QStandardItem("Chipset: "+QString::fromStdString(vc.at(i).getChipset())));
       }
    }
    ui->listView_3->setModel(listModel_3);
}

void MainWindow::removeItem()
{
    QModelIndexList list =ui->listView->selectionModel()->selectedIndexes();

       QStringList slist;
       foreach(const QModelIndex &index, list){
           for(int i=0;i<mb.size();i++)
           {
              if(QString::fromStdString(mb.at(i).getName())==index.data(Qt::DisplayRole ).toString())
              {
                    mb.erase(mb.begin()+i);
                    i--;
              }
           }
           for(int i=0;i<cp.size();i++)
           {
              if(QString::fromStdString(cp.at(i).getName())==index.data(Qt::DisplayRole ).toString())
              {
                  cp.erase(cp.begin()+i);
                  i--;
              }
           }
           for(int i=0;i<ram.size();i++)
           {
              if(QString::fromStdString(ram.at(i).getName())==index.data(Qt::DisplayRole ).toString())
              {
                  ram.erase(ram.begin()+i);
                  i--;
              }
           }
           for(int i=0;i<vc.size();i++)
           {
              if(QString::fromStdString(vc.at(i).getName())==index.data(Qt::DisplayRole ).toString())
              {
                  vc.erase(vc.begin()+i);
                  i--;
              }
           }
           listModel->removeRow(index.row());
           listModel_3->clear();
       }


}
void MainWindow::showAddDlg()
{
    AddDialog *dlg = new AddDialog(this);
    dlg->setWindowTitle("Добавление комплектующего");
    if(dlg->exec()==dlg->Accepted)
    {
        if(dlg->curItem=="Материнская плата")
        {
            mb.push_back(dlg->mb);
        }
        else if(dlg->curItem=="Видеокарта")
        {

            vc.push_back(dlg->vc);
        }
        else if(dlg->curItem=="Процессор")
        {
            cp.push_back(dlg->cp);
        }
        else if(dlg->curItem=="Оперативная память")
        {
             ram.push_back(dlg->rm);
        }
    }
    initCompList();
}


void MainWindow::showEditDlg()
{
    QModelIndexList list =ui->listView->selectionModel()->selectedIndexes();
     AddDialog *dlg = new AddDialog(this);

      dlg->setWindowTitle("Редактирование комплектующего");
       foreach(const QModelIndex &index, list){
           for(int i=0;i<mb.size();i++)
           {
              if(QString::fromStdString(mb.at(i).getName())==index.data(Qt::DisplayRole ).toString())
              {
                    dlg->mb = mb.at(i);
                     dlg->setEditOnly(0);
                    if(dlg->exec()==dlg->Accepted)
                    {
                        mb.at(i) = dlg->mb;
                    }
                    initCompList();
                    return;
              }
           }
           for(int i=0;i<cp.size();i++)
           {
              if(QString::fromStdString(cp.at(i).getName())==index.data(Qt::DisplayRole ).toString())
              {
                   dlg->cp = cp.at(i);
                   dlg->setEditOnly(1);
                   if(dlg->exec()==dlg->Accepted)
                   {
                       cp.at(i) = dlg->cp;
                   }
                   initCompList();
                   return;
              }
           }
           for(int i=0;i<ram.size();i++)
           {
              if(QString::fromStdString(ram.at(i).getName())==index.data(Qt::DisplayRole ).toString())
              {
                  dlg->setEditOnly(2);
                   dlg->rm = ram.at(i);
                   if(dlg->exec()==dlg->Accepted)
                   {
                       ram.at(i) = dlg->rm;
                   }
                   initCompList();
                   return;
              }
           }
           for(int i=0;i<vc.size();i++)
           {
              if(QString::fromStdString(vc.at(i).getName())==index.data(Qt::DisplayRole ).toString())
              {
                  dlg->setEditOnly(3);
                  dlg->vc = vc.at(i);
                  if(dlg->exec()==dlg->Accepted)
                  {
                      vc.at(i) = dlg->vc;
                  }
                  initCompList();
                  return;
              }
           }

       }

}

void MainWindow::loadFromFile()
{
    mb.clear();
    vc.clear();
    cp.clear();
    ram.clear();
    QString str = QFileDialog::getOpenFileName(this,"Choose file");
    ComponentOutIn::readComponents(ram,vc,mb,cp,str.toStdString().c_str());
    initCompList();
}
void MainWindow::saveToFile()
{
    QString str = QFileDialog::getOpenFileName(this,"Choose file");
    ComponentOutIn::writeComponents(ram,vc,mb,cp,str.toStdString().c_str());

}
void MainWindow::search(QString str)
{
    searchStr = str;
    initCompList();
}
