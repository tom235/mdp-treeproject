#include "adddialog.h"
#include "ui_adddialog.h"
#include "QMessageBox"
AddDialog::AddDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddDialog)
{

    ui->setupUi(this);
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
    curItem = "Материнская плата";
    listModel = new QStandardItemModel();
    listModel->appendRow(new QStandardItem("Name"));
    listModel->appendRow(new QStandardItem("Producer"));
    listModel->appendRow(new QStandardItem("RamType"));
    listModel->appendRow(new QStandardItem("maxAmountMemory"));
    ui->listView->setModel(listModel);
    ui->lineEdit->setEnabled(false);

}

void AddDialog::selectItem(QString str)
{
    curItem = str;
    listModel->clear();
    if(str=="Материнская плата")
    {
        listModel->appendRow(new QStandardItem("Name"));
        listModel->appendRow(new QStandardItem("Producer"));
        listModel->appendRow(new QStandardItem("RamType"));
        listModel->appendRow(new QStandardItem("maxAmountMemory"));
    }
    else if(str=="Видеокарта")
    {
        listModel->appendRow(new QStandardItem("Name"));
        listModel->appendRow(new QStandardItem("Producer"));
        listModel->appendRow(new QStandardItem("Chipset"));
        listModel->appendRow(new QStandardItem("Ram"));
    }
    else if(str=="Оперативная память")
    {
        listModel->appendRow(new QStandardItem("Name"));
        listModel->appendRow(new QStandardItem("Producer"));
        listModel->appendRow(new QStandardItem("Type"));
        listModel->appendRow(new QStandardItem("Frequency"));
    }
    else
    {
        listModel->appendRow(new QStandardItem("Name"));
        listModel->appendRow(new QStandardItem("Producer"));
        listModel->appendRow(new QStandardItem("Frequency"));
        listModel->appendRow(new QStandardItem("CoreAmount"));
    }
    ui->listView->setModel(listModel);
}
void AddDialog::selectProp(QModelIndex index)
{
    QString lineEditText = "";
    ui->lineEdit->setEnabled(true);
    if(listModel->item(index.row(),0)->text()=="Name")
    {
        lineEditText = name;
    }
    else if(listModel->item(index.row(),0)->text()=="Producer")
    {
        lineEditText = producer;
    }
    else if(listModel->item(index.row(),0)->text()=="Type")
    {
        lineEditText = type;
    }
    else if(listModel->item(index.row(),0)->text()=="RamType")
    {
        lineEditText = ramType;
    }
    else if(listModel->item(index.row(),0)->text()=="Chipset")
    {
        lineEditText = chipset;
    }
    else if(listModel->item(index.row(),0)->text()=="CoreAmount")
    {
        lineEditText = QString::number(coreAmount);
    }
    else if(listModel->item(index.row(),0)->text()=="maxAmountMemory")
    {
        lineEditText = QString::number(maxAmountMemory);
    }
    else if(listModel->item(index.row(),0)->text()=="Frequency")
    {
        lineEditText = QString::number(frequency);
    }
    else if(listModel->item(index.row(),0)->text()=="Ram")
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
           if(varStr=="Name")
           {
               name = str;
           }
           else if(varStr=="Producer")
           {
               producer = str;
           }
           else if(varStr=="Frequency")
           {
               frequency = str.toFloat();
           }
           else if(varStr=="CoreAmount")
           {
               coreAmount = str.toInt();
           }
           else if(varStr=="Type")
           {
               type = str;
           }
           else if(varStr=="maxAmountMemory")
           {
               maxAmountMemory = str.toInt();
           }
           else if(varStr=="RamType")
           {
               ramType = str;
           }
           else if(varStr=="Ram")
           {
               ram = str.toInt();
           }
           else if(varStr=="Chipset")
           {
               chipset = str;
           }
       }


}

void AddDialog::addItem()
{
    if(curItem=="Материнская плата")
    {
        mb = MotherBoard(name.toStdString(),producer.toStdString(),ramType.toStdString(),maxAmountMemory);
        accept();
    }
    else if(curItem=="Видеокарта")
    {
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
        rm = Ram(name.toStdString(),producer.toStdString(),type.toStdString(),frequency);
        accept();
    }

}

void AddDialog::setEditOnly(int i)
{
    ui->comboBox->setEnabled(false);
    ui->pushButton->setText("Редактировать");
    if(i==0)
    {
        name = QString::fromStdString(mb.getName());
        producer = QString::fromStdString(mb.getProducer());
        ramType = QString::fromStdString(mb.getRamType());
        maxAmountMemory = mb.getMaxAmountMemory();
    }
    else if(i==1)
    {
        name = QString::fromStdString(cp.getName());
        producer = QString::fromStdString(cp.getProducer());
        coreAmount = cp.getCoreAmount();
        frequency = cp.getFrequnce();

    }
    else if(i==2)
    {
        name = QString::fromStdString(rm.getName());
        producer = QString::fromStdString(rm.getProducer());
        type = QString::fromStdString(rm.getType());
        frequency = rm.getFrequnce();
    }
    else if(i==3)
    {
        name = QString::fromStdString(vc.getName());
        producer = QString::fromStdString(vc.getProducer());
        chipset = QString::fromStdString(vc.getChipset());
        ram = vc.getRam();
    }
}
