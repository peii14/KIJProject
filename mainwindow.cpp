#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aes.h"
#include "rsa.h"

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
    QFile file("/Users/gayuhkautaman/Documents/code/cpp/KIJProject/KIJ-openssl/public_key.pem");
    if(!file.open(QIODevice::ReadOnly)) {
       qDebug()<<"public key not found";
       ui->CertStatus->setText("Public Key does not exist");
       return;
    }
    ui->CertStatus->setText("Public Key is available");

    QTextStream in(&file);
   QString line;
   int limit = 0;
   QStringList fields;
    while(!in.atEnd()) {
        line = in.readLine();
        fields = line.split(",");
        pubKey.append(line.toUtf8());
        limit++;
    }
    file.close();
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
    ui->CertStatus->setText("Public Key is available");
    QString certPrivate = "/Users/gayuhkautaman/Documents/code/cpp/KIJProject/KIJ-openssl/private_key.pem";
    QFile file(certPrivate);
    if(!QFileInfo::exists(certPrivate)) {
        ui->CertStatus->setText("Private Key does not exist");
       qDebug()<<"private key not found";
       return;
    }
   QTextStream in(&file);
   QString line;
   int limit = 0;
    while(!in.atEnd()) {
        line = in.readLine();
        privateKey.append(line.toUtf8());
        limit++;
    }

    QFile ENCfile("/Users/gayuhkautaman/Documents/code/cpp/KIJProject/encrypted_file.txt");
    if(!ENCfile.open(QIODevice::ReadOnly)) {
       qDebug()<<"encrypted value not found";
       ui->CertStatus->setText("encrypted value does not exist");
       return;
    }
    QTextStream in2(&ENCfile);
    QString line2;
    int limit2 = 0;
    QStringList fields2;
     while(!in.atEnd()) {
         line2 = in2.readLine();
         fields2 = line2.split(",");
         encPassword.append(line2.toUtf8());
         limit2++;
     }
    ui->actionPushBtn->setText("Decrypt");
    ui->senderPushBtn->setDisabled(false);
    ui->recieverPushBtn->setDisabled(true);
    ui->rightLabel->setText("Decrypted");
    ui->leftLabel->setText("Encrypted Photo");
}
void MainWindow::actionBtnClicked(){
    RSA rsa;
    if(ui->actionPushBtn->text() == "Encrypt"){
//        Encrypt
        QString password = ui->passwordInput->text();
        if (password.isEmpty()){
            qDebug()<<"please input password to encrypt";
            return;
        }
        rsa.EncryptRSA(pubKey,password.toUtf8());
        AES aes;
        aes.executeAES(filePath.toStdString().c_str(),password.toStdString().c_str());
        QString filePathEncrypted = "/Users/gayuhkautaman/Documents/code/cpp/KIJProject/encrypted.bmp";
        QPixmap pix(filePathEncrypted);
        ui->encryptedPic->setPixmap(pix.scaled(QSize(300,300), Qt::KeepAspectRatio));
        ui->performanceNON->setText(QString::number(aes.speed,'g',2).append(" Mb/s"));
    }else{
//        Decrypt
//        QString  password = rsa.DecryptRSA(privateKey,encPassword);
        QString password ="password";
        AES aes;
        aes.executeDecryptAES("/Users/gayuhkautaman/Documents/code/cpp/KIJProject/encrypted.bmp",password.toStdString().c_str());

        QString filePathDecrypted = "/Users/gayuhkautaman/Documents/code/cpp/KIJProject/decrypted.bmp";
        QPixmap pixDec(filePathDecrypted);
        ui->performanceNON->setText(QString::number(aes.speed,'g',2).append(" Mb/s"));
        ui->encryptedPic->setPixmap(pixDec.scaled(QSize(300,300), Qt::KeepAspectRatio));
    }
}
