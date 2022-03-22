#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>
#include <QPixmap>
#include "nativeaes.h"
#include "nativeaesdecrypt.h"

namespace Ui {
class MainWindow;
}
using namespace std;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QString fileName;
    ~MainWindow();

public slots:
//    void encryptImage(QString);
private:


    Ui::MainWindow *ui;
    QLabel *imageLabel;
    QString filePath;
    void initConnection();
    void senderRoleClicked();
    void recieverRoleClicked();
    void actionBtnClicked();
};

#endif // MAINWINDOW_H
