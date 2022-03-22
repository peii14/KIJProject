#ifndef NATIVEAESDECRYPT_H
#define NATIVEAESDECRYPT_H

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include "nativeaes.h"
//#include "structures.h"
class NativeAesDecrypt : protected NativeAesEncrypt
{
private:

public:
    NativeAesDecrypt();
    void SubRoundKey(unsigned char * state, unsigned char * roundKey);
    void InverseMixColumns(unsigned char * state);
    void ShiftRows(unsigned char * state);
    void SubBytes(unsigned char * state);
    void Round(unsigned char * state, unsigned char * key);
    void InitialRound(unsigned char * state, unsigned char * key);
    void AESDecrypt(unsigned char * encryptedMessage, unsigned char * expandedKey,
                    unsigned char * decryptedMessage);
    void executeDecrypt();

};

#endif // NATIVEAESDECRYPT_H
