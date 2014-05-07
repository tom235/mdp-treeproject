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
    void updateProp2(QModelIndex);
    void removeItem();
    void showAddDlg();
    void lineEditClicked();
    void loadFromFile();
    void saveToFile();
    void showEditDlg();
    void search(QString);

private:
    void findComponent(MotherBoard m);
    void findComponent(VideoCard v);
    void findComponent(Cpu cpu);
    void findComponent(Ram rm);
    int celIndex;
    QString searchStr = "";
    std::vector<MotherBoard> mb;
    std::vector<VideoCard> vc;
    std::vector<Cpu> cp;
    std::vector<Ram> ram;
    QStandardItemModel *listModel;
    QStandardItemModel *listModel_3;
    QStandardItemModel *listModel_2;
    QStandardItemModel *listModel_4;
    Ui::MainWindow *ui;
    void initCompList();

};

#endif // MAINWINDOW_H
