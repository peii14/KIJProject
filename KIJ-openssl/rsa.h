

#ifndef RSA_ALGORITHM_H
#define RSA_ALGORITHM_H

#include <iostream>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <openssl/bio.h>
#include <fstream>
#include <vector>

using namespace std;

#define KEY_LENGTH       2048
#define PUBLIC_EXPONENT  59     //Public exponent should be a prime number.
#define PUBLIC_KEY_PEM   1
#define PRIVATE_KEY_PEM  0

#define LOG(x)               \
        cout << x << endl;   \

class rsa{
public:
char password[KEY_LENGTH / 8];
 RSA * readCert(string filename,bool isPublic);
 RSA * create_RSA(RSA *keypair, int pem_type, char *file_name);
 int public_encrypt(int flen, unsigned char* from, unsigned char *to, RSA* key, int padding);
 int private_decrypt(int flen, unsigned char* from, unsigned char *to, RSA* key, int padding);
 void create_encrypted_file(char* encrypted, RSA * key_pair);
};

#endif //RSA_ALGORITHM_H