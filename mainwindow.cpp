#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filePath = "/Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/dams.bmp";
    QPixmap pix(filePath);
    ui->label_pic->setPixmap(pix.scaled(QSize(300,300), Qt::KeepAspectRatio));

    setWindowTitle(tr("AES"));
    resize(1000, 500);
    initConnection();

}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::initConnection(){
    connect(ui->senderPushBtn, &QPushButton::clicked,this, &MainWindow::senderRoleClicked);
    connect(ui->recieverPushBtn,&QPushButton::clicked,this, &MainWindow::recieverRoleClicked);
    connect(ui->actionPushBtn,&QPushButton::clicked,this, &MainWindow::actionBtnClicked);
}

void MainWindow::senderRoleClicked(){
    ui->actionPushBtn->setText("Encrypt");
    ui->senderPushBtn->setDisabled(true);
    ui->recieverPushBtn->setDisabled(false);
    ui->leftLabel->setText("Original");
    ui->rightLabel->setText("Encrypted");

}
void MainWindow::recieverRoleClicked(){
    ui->actionPushBtn->setText("Decrypt");
    ui->senderPushBtn->setDisabled(false);
    ui->recieverPushBtn->setDisabled(true);
    ui->rightLabel->setText("Original");
    ui->leftLabel->setText("Encrypted");
}
void MainWindow::actionBtnClicked(){
    if(ui->actionPushBtn->text() == "Encrypt"){
//        Encrypt
    NativeAesEncrypt NA;
    NA.ExecuteEncrypt(filePath.toStdString().c_str());
    }else{
//        Decrypt
     NativeAesDecrypt DA;
     DA.executeDecrypt();

    }
}
