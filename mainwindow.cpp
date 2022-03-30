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

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::initConnection(){
    connect(ui->senderPushBtn, &QPushButton::clicked,this, &MainWindow::senderRoleClicked);
    connect(ui->recieverPushBtn,&QPushButton::clicked,this, &MainWindow::recieverRoleClicked);
    connect(ui->actionPushBtn,&QPushButton::clicked,this, &MainWindow::actionBtnClicked);
}

void MainWindow::senderRoleClicked(){
    filePath = "/Users/gayuhkautaman/Documents/code/cpp/KIJProject/dams.bmp";
    QPixmap pix1(filePath);
    ui->label_pic->setPixmap(pix1.scaled(QSize(300,300), Qt::KeepAspectRatio));

    ui->actionPushBtn->setText("Encrypt");
    ui->senderPushBtn->setDisabled(true);
    ui->recieverPushBtn->setDisabled(false);
    ui->leftLabel->setText("Original");
    ui->rightLabel->setText("Encrypted");

}
void MainWindow::recieverRoleClicked(){
    filePath = "/Users/gayuhkautaman/Documents/code/cpp/KIJProject/encrypted.bmp";
    QPixmap pix(filePath);
    ui->label_pic->setPixmap(pix.scaled(QSize(300,300), Qt::KeepAspectRatio));

    ui->actionPushBtn->setText("Decrypt");
    ui->senderPushBtn->setDisabled(false);
    ui->recieverPushBtn->setDisabled(true);
    ui->rightLabel->setText("Encrypted");
    ui->leftLabel->setText("Decrypted Original");
}
void MainWindow::actionBtnClicked(){
    if(ui->actionPushBtn->text() == "Encrypt"){
//        Encrypt

        AES aes;
        aes.executeAES(filePath.toStdString().c_str());

        QString filePathEncrypted = "/Users/gayuhkautaman/Documents/code/cpp/KIJProject/encrypted.bmp";
        QPixmap pix(filePathEncrypted);
        ui->encryptedPic->setPixmap(pix.scaled(QSize(300,300), Qt::KeepAspectRatio));
        ui->performanceNON->setText(QString::number(aes.speed).append(" Mb/s"));
    }else{
//        Decrypt
        AES aes;
        aes.executeDecryptAES("/Users/gayuhkautaman/Documents/code/cpp/KIJProject/encrypted.bmp");

        QString filePathDecrypted = "/Users/gayuhkautaman/Documents/code/cpp/KIJProject/decrypted.bmp";
        QPixmap pixDec(filePathDecrypted);
        ui->performanceNON->setText(QString::number(aes.speed).append(" Mb/s"));
        ui->encryptedPic->setPixmap(pixDec.scaled(QSize(300,300), Qt::KeepAspectRatio));
    }
}
