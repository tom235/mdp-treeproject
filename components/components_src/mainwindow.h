#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "QModelIndex"
#include <QMainWindow>
#include "qstandarditemmodel.h"
#include "container/MotherBoard.h"
#include "container/Ram.h"
#include "container/Cpu.h"
#include "container/VideoCard.h"
#include <vector>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void updateProp(QModelIndex);
    void removeItem();
    void showAddDlg();
    void loadFromFile();
    void saveToFile();
    void showEditDlg();
    void search(QString);

private:
    int celIndex;
    QString searchStr = "";
    std::vector<MotherBoard> mb;
    std::vector<VideoCard> vc;
    std::vector<Cpu> cp;
    std::vector<Ram> ram;
    QStandardItemModel *listModel;
    QStandardItemModel *listModel_3;
    Ui::MainWindow *ui;
    void initCompList();

};

#endif // MAINWINDOW_H
