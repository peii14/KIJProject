#include "rsa.h"
RSA::RSA(){

}

bool RSA::EncryptRSA(QByteArray publicKey,QString password){
    QRSAEncryption e(QRSAEncryption::Rsa::RSA_2048);

     auto encryptMessage = e.encode(password.toUtf8(), publicKey);
     FILE* encrypted_file = fopen("/Users/gayuhkautaman/Documents/code/cpp/KIJProject/encrypted_file.txt", "w");
        fwrite( encryptMessage , sizeof(*encryptMessage), sizeof (publicKey), encrypted_file);
        fclose(encrypted_file);
     if (encryptMessage == password)
             return false;
     return true;
}
QString RSA::DecryptRSA(QByteArray privateKey,QByteArray encPassword){
     QRSAEncryption e(QRSAEncryption::Rsa::RSA_2048);

     return e.decode(encPassword, privateKey);
}
