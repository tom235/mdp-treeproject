#ifndef FINDCOMPONENTDLG_H
#define FINDCOMPONENTDLG_H

#include <QDialog>
#include "QModelIndex"
#include "QStandardItemModel"
#include "container/MotherBoard.h"
#include "container/Ram.h"
#include "container/Cpu.h"
#include "container/VideoCard.h"

namespace Ui {
class FindComponentDlg;
}

class FindComponentDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FindComponentDlg(QWidget *parent = 0);
    ~FindComponentDlg();
    MotherBoard mb;
    VideoCard vc;
    Cpu cp;

    QString curItem;
    Ram rm;

private slots:
    void selectItem(QString);
    void selectProp(QModelIndex);
    void setVariables(QString);
    void addItem();
private:

    QString producer;
    QString name;
    QString chipset;
    QString type;
    QString ramType;
    float frequency = 0.0f;
    int ram = 0;
    int maxAmountMemory = 0;
    int coreAmount = 0;
    QStandardItemModel *listModel;
    void initComponents();
    Ui::FindComponentDlg *ui;
};

#endif // FINDCOMPONENTDLG_H
