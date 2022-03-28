#ifndef LIBAES_H
#define LIBAES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <fstream>
#include <sstream>
#include "bitmap.h"
using namespace std;

class Libaes
{
private:
    int row,column;
    int keylength;
    vector<unsigned char> redString;
    vector <unsigned char> greenString;
    vector <unsigned char> blueString;

public:
    void executeEncryptLibAES(string fileName);

    Libaes();
};

#endif // LIBAES_H
