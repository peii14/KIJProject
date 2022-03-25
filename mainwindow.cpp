#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aes.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


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
        filePath = "/Users/gayuhkautaman/Documents/code/cpp/KIJProject/dams.bmp";
        QPixmap pix1(filePath);
        ui->label_pic->setPixmap(pix1.scaled(QSize(300,300), Qt::KeepAspectRatio));

        AES aes;
        aes.executeAES(filePath.toStdString().c_str());

        QString filePathEncrypted = "/Users/gayuhkautaman/Documents/code/cpp/KIJProject/example.bmp";
        QPixmap pix(filePathEncrypted);
        ui->encryptedPic->setPixmap(pix.scaled(QSize(300,300), Qt::KeepAspectRatio));
    }else{
//        Decrypt
        filePath = "/Users/gayuhkautaman/Documents/code/cpp/KIJProject/example.bmp";
        QPixmap pix(filePath);
        ui->label_pic->setPixmap(pix.scaled(QSize(300,300), Qt::KeepAspectRatio));

        AES aes;
        aes.executeDecryptAES(filePath.toStdString().c_str());

        QString filePathDecrypted = "/Users/gayuhkautaman/Documents/code/cpp/KIJProject/decrypted.bmp";
        QPixmap pixDec(filePathDecrypted);
        ui->encryptedPic->setPixmap(pixDec.scaled(QSize(300,300), Qt::KeepAspectRatio));
    }
}
