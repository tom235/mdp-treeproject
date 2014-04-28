#ifndef ADDDIALOG_H
#define ADDDIALOG_H
#include "QModelIndex"
#include "QStandardItemModel"
#include "container/MotherBoard.h"
#include "container/Ram.h"
#include "container/Cpu.h"
#include "container/VideoCard.h"
#include <QDialog>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = 0);
    ~AddDialog();
    MotherBoard mb;
    VideoCard vc;
    Cpu cp;
    QString curItem;
    Ram rm;
    void setEditOnly(int);
private slots:
    void selectItem(QString);
    void selectProp(QModelIndex);
    void setVariables(QString);
    void addItem();
private:
    Ui::AddDialog *ui;
    QString producer;
    QString name;
    QString chipset;
    QString type;
    QString ramType;
    float frequency;
    int ram;
    int maxAmountMemory;
    int coreAmount;
    QStandardItemModel *listModel;
    void initComponents();
};

#endif // ADDDIALOG_H
