#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "container/ComponentOutIn.h"
#include "adddialog.h"
#include "QRegExp"
#include "QString.h"
#include "QFileDialog"
#include "exception/FileFormatException.h"
#include "findcomponentdlg.h"
#include "QMessageBox"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   setMaximumSize(700,470);
   setMinimumSize(700,470);
   initCompList();
   setWindowIcon(QIcon(":/images/logo.png"));
   setWindowTitle("Комплектующие");
   QObject::connect(ui->listView, SIGNAL(clicked(QModelIndex)),this, SLOT(updateProp(QModelIndex)));
   QObject::connect(ui->listView_2, SIGNAL(clicked(QModelIndex)),this, SLOT(updateProp2(QModelIndex)));
   QObject::connect(ui->pushButton_3, SIGNAL(clicked()),this, SLOT(removeItem()));
   QObject::connect(ui->pushButton_4, SIGNAL(clicked()),this, SLOT(loadFromFile()));
   QObject::connect(ui->pushButton_5, SIGNAL(clicked()),this, SLOT(saveToFile()));
   QObject::connect(ui->pushButton, SIGNAL(clicked()),this, SLOT(showAddDlg()));
   QObject::connect(ui->pushButton_2, SIGNAL(clicked()),this, SLOT(showEditDlg()));
   QObject::connect(ui->lineEdit, SIGNAL(textChanged(QString)),this, SLOT(search(QString)));
   QObject::connect(ui->lineEdit_3, SIGNAL(selectionChanged()),this, SLOT(lineEditClicked()));
   ui->listView_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
   ui->listView_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
   ui->listView_4->setEditTriggers(QAbstractItemView::NoEditTriggers);
   ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initCompList()
{


     listModel_2 = new QStandardItemModel();
     ui->listView->setModel(listModel_2);
    std::cout << mb.size();
    listModel = new QStandardItemModel();
    listModel_4 = new QStandardItemModel();
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
     ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}
void MainWindow::updateProp2(QModelIndex id)
{
  QString itemStr = listModel_2->itemFromIndex(id)->text();

  listModel_4->clear();
    for(int i=0;i<mb.size();i++)
    {
       if(QString::fromStdString(mb.at(i).getName())==itemStr)
       {
           listModel_4->appendRow(new QStandardItem("Name: "+QString::fromStdString(mb.at(i).getName())));
           listModel_4->appendRow(new QStandardItem("Producer: "+QString::fromStdString(mb.at(i).getProducer())));
           listModel_4->appendRow(new QStandardItem("Ram type: "+QString::fromStdString(mb.at(i).getRamType())));
           listModel_4->appendRow(new QStandardItem("MaxAmountMemory: "+QString::number(mb.at(i).getMaxAmountMemory())));
       }
    }
    for(int i=0;i<cp.size();i++)
    {
       if(QString::fromStdString(cp.at(i).getName())==itemStr)
       {
           listModel_4->appendRow(new QStandardItem("Name: "+QString::fromStdString(cp.at(i).getName())));
           listModel_4->appendRow(new QStandardItem("Producer: "+QString::fromStdString(cp.at(i).getProducer())));
           listModel_4->appendRow(new QStandardItem("Frequency: "+QString::number(cp.at(i).getFrequnce())));
           listModel_4->appendRow(new QStandardItem("Core Amount: "+QString::number(cp.at(i).getCoreAmount())));
       }
    }
    for(int i=0;i<ram.size();i++)
    {
       if(QString::fromStdString(ram.at(i).getName())==itemStr)
       {
           listModel_4->appendRow(new QStandardItem("Name: "+QString::fromStdString(ram.at(i).getName())));
           listModel_4->appendRow(new QStandardItem("Producer: "+QString::fromStdString(ram.at(i).getProducer())));
           listModel_4->appendRow(new QStandardItem("Frequency: "+QString::number(ram.at(i).getFrequnce())));
           listModel_4->appendRow(new QStandardItem("Type: "+QString::fromStdString(ram.at(i).getType())));
       }
    }
    for(int i=0;i<vc.size();i++)
    {
       if(QString::fromStdString(vc.at(i).getName())==itemStr)
       {
           listModel_4->appendRow(new QStandardItem("Name: "+QString::fromStdString(vc.at(i).getName())));
           listModel_4->appendRow(new QStandardItem("Producer: "+QString::fromStdString(vc.at(i).getProducer())));
           listModel_4->appendRow(new QStandardItem("Ram: "+QString::number(vc.at(i).getRam())));
           listModel_4->appendRow(new QStandardItem("Chipset: "+QString::fromStdString(vc.at(i).getChipset())));
       }
    }
    ui->listView_4->setModel(listModel_4);
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
       int k=0;
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
           k++;
       }

       if(k==0)
            QMessageBox::warning(this,"Ошибка","Для удаления выберите хотя бы один компонент");


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
void MainWindow::lineEditClicked()
{
    FindComponentDlg *dlg = new FindComponentDlg(this);
    dlg->setWindowTitle("Поиск комплектующего");
    if(dlg->exec()==dlg->Accepted)
    {
        if(dlg->curItem=="Материнская плата")
        {
            // Поиск материнской платы
            MotherBoard *tempMb = new MotherBoard(dlg->mb.getName(),dlg->mb.getProducer(),dlg->mb.getRamType(),dlg->mb.getMaxAmountMemory());
            findComponent(*tempMb);
        }
        else if(dlg->curItem=="Видеокарта")
        {
            VideoCard *tempVC = new VideoCard(dlg->vc.getName(),dlg->vc.getProducer(),dlg->vc.getChipset(),dlg->vc.getRam());
            findComponent(*tempVC);
            // Поиск видеокарты;
        }
        else if(dlg->curItem=="Процессор")
        {
            Cpu *tempCPU = new Cpu(dlg->cp.getName(),dlg->cp.getProducer(),dlg->cp.getFrequnce(),dlg->cp.getCoreAmount());
            findComponent(*tempCPU);
            // Поиск процессора
        }
        else if(dlg->curItem=="Оперативная память")
        {
            Ram *tempRam = new Ram(dlg->rm.getName(),dlg->rm.getProducer(),dlg->rm.getType(),dlg->rm.getFrequnce());
            findComponent(*tempRam);
            // Поиск оперативной памяти
        }
    }

}

void MainWindow::showEditDlg()
{
    QModelIndexList list =ui->listView->selectionModel()->selectedIndexes();
     AddDialog *dlg = new AddDialog(this);

      dlg->setWindowTitle("Редактирование комплектующего");
      int k=0;
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
           k++;

       }
       if(k==0)
            QMessageBox::warning(this,"Ошибка","Для редактирования выберите компонент");

}

void MainWindow::loadFromFile()
{

    mb.clear();
    vc.clear();
    cp.clear();
    ram.clear();
    try{
    QString str = QFileDialog::getOpenFileName(this,"Choose file");
    ComponentOutIn::readComponents(ram,vc,mb,cp,str.toStdString().c_str());
    initCompList();
    }
    catch(const Exception &e)
    {

                QMessageBox::warning(this,"FileFormatException",e.getMsg());

    }

}
void MainWindow::findComponent(MotherBoard m)
{
    listModel_2->clear();
    for(int i=0;i<mb.size();i++)
    {
       if(m.getName().size()!=0)
       {
             if(mb.at(i).getName()!=m.getName())
               continue;
       }
       if(m.getMaxAmountMemory()!=0)
       {
           if(mb.at(i).getMaxAmountMemory()!=m.getMaxAmountMemory())
               continue;
       }
       if(m.getProducer().size()!=0)
       {
           if(mb.at(i).getProducer()!=m.getProducer())
             continue;
       }

       if(m.getRamType().size()!=0)
       {
           if(mb.at(i).getRamType()!=m.getRamType())
               continue;
       }
       listModel_2->appendRow(new QStandardItem(QString::fromStdString(mb.at(i).getName())));
    }
    ui->listView_2->setModel(listModel_2);
}

void MainWindow::findComponent(VideoCard v)
{
    listModel_2->clear();
    for(int i=0;i<vc.size();i++)
    {
       if(v.getName().size()!=0)
       {
             if(vc.at(i).getName()!=v.getName())
               continue;
       }
       if(v.getChipset().size()!=0)
       {
           if(vc.at(i).getChipset()!=v.getChipset())
               continue;
       }
       if(v.getProducer().size()!=0)
       {
           if(vc.at(i).getProducer()!=v.getProducer())
             continue;
       }

       if(v.getRam()!=0)
       {
           if(vc.at(i).getRam()!=v.getRam())
               continue;
       }
       listModel_2->appendRow(new QStandardItem(QString::fromStdString(vc.at(i).getName())));
    }
    ui->listView_2->setModel(listModel_2);
}
void MainWindow::findComponent(Cpu cpu)
{
    listModel_2->clear();
    for(int i=0;i<cp.size();i++)
    {
       if(cpu.getName().size()!=0)
       {
             if(cp.at(i).getName()!=cpu.getName())
               continue;
       }
       if(cpu.getFrequnce()<0.00001)
       {
           if(abs(cp.at(i).getFrequnce()!=cpu.getFrequnce())>0.001)
               continue;
       }
       if(cpu.getProducer().size()!=0)
       {
           if(cp.at(i).getProducer()!=cpu.getProducer())
             continue;
       }

       if(cpu.getCoreAmount()!=0)
       {
           if(cp.at(i).getCoreAmount()!=cpu.getCoreAmount())
               continue;
       }
       listModel_2->appendRow(new QStandardItem(QString::fromStdString(cp.at(i).getName())));
    }
    ui->listView_2->setModel(listModel_2);
}
void MainWindow::findComponent(Ram rm)
{
    listModel_2->clear();
    for(int i=0;i<ram.size();i++)
    {
       if(rm.getName().size()!=0)
       {
             if(ram.at(i).getName()!=rm.getName())
               continue;
       }
       if(rm.getFrequnce()<0.00001)
       {
           if(abs(ram.at(i).getFrequnce()!=rm.getFrequnce())>0.001)
               continue;
       }
       if(rm.getProducer().size()!=0)
       {
           if(ram.at(i).getProducer()!=rm.getProducer())
             continue;
       }

       if(rm.getType().size()!=0)
       {
           if(ram.at(i).getType()!=rm.getType())
               continue;
       }
       listModel_2->appendRow(new QStandardItem(QString::fromStdString(ram.at(i).getName())));
    }
    ui->listView_2->setModel(listModel_2);
}
void MainWindow::saveToFile()
{
    QString str = QFileDialog::getSaveFileName(this,"Choose file");
    ComponentOutIn::writeComponents(ram,vc,mb,cp,str.toStdString().c_str());

}
void MainWindow::search(QString str)
{
    listModel_3->clear();
    searchStr = str;
    initCompList();
}
