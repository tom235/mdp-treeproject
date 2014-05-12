#include "adddialog.h"
#include "ui_adddialog.h"
#include "QMessageBox"
#include <QtDebug>
AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{

    ui->setupUi(this);
    if(!isEdit)
    {
    frequency = 0;
    ram = 0;
    maxAmountMemory = 0;
    coreAmount = 0;
    }
    initComponents();

    QObject::connect(ui->comboBox, SIGNAL(activated(QString)),this, SLOT(selectItem(QString)));
    QObject::connect(ui->listView, SIGNAL(clicked(QModelIndex)),this, SLOT(selectProp(QModelIndex)));
    QObject::connect(ui->lineEdit, SIGNAL(textChanged(QString)),this, SLOT(setVariables(QString)));
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(addItem()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(reject()));

}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::initComponents()
{
    listModel = new QStandardItemModel();
    if(!isEdit)
    {
    curItem = "Материнская плата";

    listModel->appendRow(new QStandardItem("Название"));
    listModel->appendRow(new QStandardItem("Производитель"));
    listModel->appendRow(new QStandardItem("Объем памятиType"));
    listModel->appendRow(new QStandardItem("Максимальный объем памяти"));
    }
    ui->listView->setModel(listModel);
    ui->lineEdit->setEnabled(false);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void AddDialog::selectItem(QString str)
{
    curItem = str;
    listModel->clear();
    if(str=="Материнская плата")
    {
        listModel->appendRow(new QStandardItem("Название"));
        listModel->appendRow(new QStandardItem("Производитель"));
        listModel->appendRow(new QStandardItem("Тип памяти"));
        listModel->appendRow(new QStandardItem("Максимальный объем памяти"));
    }
    else if(str=="Видеокарта")
    {
        listModel->appendRow(new QStandardItem("Название"));
        listModel->appendRow(new QStandardItem("Производитель"));
        listModel->appendRow(new QStandardItem("Чипсет"));
        listModel->appendRow(new QStandardItem("Объем памяти"));
    }
    else if(str=="Оперативная память")
    {
        listModel->appendRow(new QStandardItem("Название"));
        listModel->appendRow(new QStandardItem("Производитель"));
        listModel->appendRow(new QStandardItem("Тип"));
        listModel->appendRow(new QStandardItem("Частота"));
    }
    else
    {
        listModel->appendRow(new QStandardItem("Название"));
        listModel->appendRow(new QStandardItem("Производитель"));
        listModel->appendRow(new QStandardItem("Частота"));
        listModel->appendRow(new QStandardItem("Количество ядер"));
    }
    ui->listView->setModel(listModel);
}
void AddDialog::selectProp(QModelIndex index)
{
    QString lineEditText = "";
    ui->lineEdit->setEnabled(true);
    if(listModel->item(index.row(),0)->text()=="Название")
    {
        lineEditText = name;
    }
    else if(listModel->item(index.row(),0)->text()=="Производитель")
    {
        lineEditText = producer;
    }
    else if(listModel->item(index.row(),0)->text()=="Тип")
    {
        lineEditText = type;
    }
    else if(listModel->item(index.row(),0)->text()=="Тип памяти")
    {
        lineEditText = ramType;
    }
    else if(listModel->item(index.row(),0)->text()=="Чипсет")
    {
        lineEditText = chipset;
    }
    else if(listModel->item(index.row(),0)->text()=="Количество ядер")
    {
        lineEditText = QString::number(coreAmount);
    }
    else if(listModel->item(index.row(),0)->text()=="Максимальный объем памяти")
    {
        lineEditText = QString::number(maxAmountMemory);
    }
    else if(listModel->item(index.row(),0)->text()=="Частота")
    {
        lineEditText = QString::number(frequency);
    }
    else if(listModel->item(index.row(),0)->text()=="Объем памяти")
    {
        lineEditText = QString::number(ram);
    }
    ui->lineEdit->setText(lineEditText);
}

void AddDialog::setVariables(QString str)
{
    QModelIndexList list =ui->listView->selectionModel()->selectedIndexes();

       foreach(const QModelIndex &index, list){
           QString varStr = index.data(Qt::DisplayRole ).toString();
           if(varStr=="Название")
           {

               name = str;
           }
           else if(varStr=="Производитель")
           {
               producer = str;
           }
           else if(varStr=="Частота")
           {
               if(QRegExp("[-+]?[0-9]*\.?[0-9]+").indexIn(str)==-1)
                   QMessageBox::warning(this,"Ошибка","Ожидается числовое значение");
               frequency = str.toFloat();
           }
           else if(varStr=="Количество ядер")
           {
               if(QRegExp("[-+]?\\d+").indexIn(str)==-1)
                   QMessageBox::warning(this,"Ошибка","Ожидается числовое значение");
               coreAmount = str.toInt();
           }
           else if(varStr=="Тип")
           {
               type = str;
           }
           else if(varStr=="Максимальный объем памяти")
           {
               if(QRegExp("[-+]?\\d+").indexIn(str)==-1)
                   QMessageBox::warning(this,"Ошибка","Ожидается числовое значение");
               maxAmountMemory = str.toInt();
           }
           else if(varStr=="Тип памяти")
           {
               ramType = str;
           }
           else if(varStr=="Объем памяти")
           {
               if(QRegExp("[-+]?\\d+").indexIn(str)==-1)
                   QMessageBox::warning(this,"Ошибка","Ожидается числовое значение");
               ram = str.toInt();
           }
           else if(varStr=="Чипсет")
           {
               chipset = str;
           }
       }


}

void AddDialog::addItem()
{
    if(name.size()==0)
    {
        QMessageBox::warning(this,"Ошибка","Поле name должно быть не пустое");

        return;
    }
    if(producer.size()==0)
    {
        QMessageBox::warning(this,"Ошибка","Поле producer должно быть не пустое");

        return;
    }
    if(curItem=="Материнская плата")
    {
        if(ramType.size()==0)
        {
            QMessageBox::warning(this,"Ошибка","Поле ramType должно быть не пустое");

            return;
        }

        mb = MotherBoard(name.toStdString(),producer.toStdString(),ramType.toStdString(),maxAmountMemory);
        accept();
    }
    else if(curItem=="Видеокарта")
    {
        if(chipset.size()==0)
        {
            QMessageBox::warning(this,"Ошибка","Поле chipset должно быть не пустое");

            return;
        }

        vc = VideoCard(name.toStdString(),producer.toStdString(),chipset.toStdString(),ram);
        accept();
    }
    else if(curItem=="Процессор")
    {

        cp = Cpu(name.toStdString(),producer.toStdString(),frequency,coreAmount);
        accept();
    }
    else if(curItem=="Оперативная память")
    {
        if(type.size()==0)
        {
            QMessageBox::warning(this,"Ошибка","Поле type должно быть не пустое");

            return;
        }
        rm = Ram(name.toStdString(),producer.toStdString(),type.toStdString(),frequency);
        accept();
    }

}

void AddDialog::setEditOnly(int i)
{
    isEdit = true;
    ui->comboBox->setEnabled(false);
    ui->pushButton->setText("Редактировать");
    if(i==0)
    {
        name = QString::fromStdString(mb.getName());
        producer = QString::fromStdString(mb.getProducer());
        ramType = QString::fromStdString(mb.getRamType());
        maxAmountMemory = mb.getMaxAmountMemory();
        selectItem("Материнская плата");
    }
    else if(i==1)
    {
        name = QString::fromStdString(cp.getName());
        producer = QString::fromStdString(cp.getProducer());
        coreAmount = cp.getCoreAmount();
        frequency = cp.getFrequnce();
        selectItem("Процессор");

    }
    else if(i==2)
    {
        name = QString::fromStdString(rm.getName());
        producer = QString::fromStdString(rm.getProducer());
        type = QString::fromStdString(rm.getType());
        frequency = rm.getFrequnce();
        selectItem("Оперативная память");
    }
    else if(i==3)
    {
        name = QString::fromStdString(vc.getName());
        producer = QString::fromStdString(vc.getProducer());
        chipset = QString::fromStdString(vc.getChipset());
        ram = vc.getRam();
        selectItem("Видеокарта");
    }
}
