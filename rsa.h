#ifndef RSA_H
#define RSA_H


#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <qrsaencryption.h>
class RSA{
public:
    RSA();
    bool EncryptRSA(QByteArray publicKey,QString password);
    QString DecryptRSA(QByteArray privateKey,QByteArray encPassword);
};

#endif // RSA_H
