#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/aes.h>
#include <openssl/rand.h>
#include <vector>
#include <fstream>
#include <iostream>
#include "../bitmap.h"
#include "rsa.h"
#include <openssl/ssl.h>
#include <openssl/rsa.h>
#include <ctime>
#include <openssl/sha.h>
#include <sys/time.h>

using namespace std;

unsigned long getMicroseconds(){
    const unsigned int MICROSECONDS = 1000000;
    struct timeval tv;
    gettimeofday(&tv,NULL);
    return MICROSECONDS * tv.tv_sec + tv.tv_usec;
}


std::ifstream::pos_type filesize(const char *filename){
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}
void setPassword(){
    rsa rsa;
    RSA * public_key;
    char *encrypt = NULL;
    char *decrypt = NULL;
    // read public key
    public_key = rsa.readCert("public_key.pem",true);
    cout<<"Input password"<<endl;
    cin>>rsa.password;
    
    encrypt = (char*)malloc(RSA_size(public_key));

    int encrypt_length = rsa.public_encrypt(strlen(rsa.password) + 1, (unsigned char*)rsa.password, (unsigned char*)encrypt,public_key, RSA_PKCS1_OAEP_PADDING);
    if(encrypt_length == -1) {
        cout<<"error in public_encrypt()"<<endl;
    }
    rsa.create_encrypted_file(encrypt, public_key);
    cout<<"password has been encrypted"<<endl;
    free(encrypt);
    free(decrypt);
    free(public_key);
}
void decryptPassword(){
    rsa rsa;
    RSA * private_key;
    private_key = rsa.readCert("private_key.pem",false);
    // read pass
    std::ifstream t("private_key.bin",std::ios::binary);
    t.seekg(0, std::ios::end);
    size_t size = t.tellg();
    std::string encrypt(25, ' ');
    t.seekg(0);
    t.read(&encrypt[0], 25); 
    
    char *decrypt = NULL;
    decrypt = (char *)malloc(256);
    int decrypt_length = rsa.private_decrypt(256, (unsigned char*)encrypt.c_str(), (unsigned char*)decrypt, private_key, RSA_PKCS1_OAEP_PADDING);
    if(decrypt_length == -1) {
       cout<<endl;
    }

    strcpy(rsa.password,decrypt);
    free(private_key);
    free(decrypt);
}

void executeEncrypt(){
    int row,column;
    unsigned int megabytesCount;
    rsa rsa;
    vector<unsigned char> redString;
    vector <unsigned char> greenString;
    vector <unsigned char> blueString;
    Bitmap image;
    std::vector <std::vector <Pixel> > bmp;
    Pixel rgb;
    string filePath = "../dams.bmp";
    megabytesCount = 4;
    image.open(filePath);
    bool validBmp = image.isImage();
    if( validBmp == true ){
    bmp = image.toPixelMatrix();
    row = bmp.size();
    column = bmp[0].size();

    for(int i =1 ; i<= row-1;i++){
        for(int j=1 ; j<=column-1;j++){
            rgb = bmp[i][j];
            int redpix = (int)rgb.red;
            int greenpix = (int)rgb.green;
            int bluepix = (int)rgb.blue;
            redString.push_back((unsigned char)redpix);
            greenString.push_back((unsigned char)greenpix);
            blueString.push_back((unsigned char)bluepix);
        }
    }
     }
     
    size_t originalLen =sizeof(std::vector<int>) + (sizeof(int) *redString.size());
    size_t paddedMessageLen = originalLen;
    if ((paddedMessageLen % 16) != 0) {
        paddedMessageLen = (paddedMessageLen / 16 + 1) * 16;
    }
    
    vector<unsigned char> redPaddedMessage(paddedMessageLen);
    vector<unsigned char> greenPaddedMessage(paddedMessageLen);
    vector<unsigned char> bluePaddedMessage(paddedMessageLen);

    for (int i = 0; i < paddedMessageLen; i++) {
        if (i >= originalLen) {
            redPaddedMessage[i] = 0;
            greenPaddedMessage[i] = 0;
            bluePaddedMessage[i]= 0;
        }
        else {
            redPaddedMessage[i] = redString[i];
            greenPaddedMessage[i] = greenString[i];
            bluePaddedMessage[i]= blueString[i];
        }
    }

/* init vector */
    unsigned char iv_enc[AES_BLOCK_SIZE], iv_dec[AES_BLOCK_SIZE];
    RAND_bytes(iv_enc, AES_BLOCK_SIZE);
    memcpy(iv_dec, iv_enc, AES_BLOCK_SIZE);
//     encrypt
    int keylength = 256;
    unsigned char aes_key[keylength/8];
    memset(aes_key, 0, keylength/8);
    
    const size_t encryptedsize = ((paddedMessageLen + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    unsigned char REDenc_out[encryptedsize];
    memset(REDenc_out, 0, sizeof(REDenc_out));
    unsigned char GREENenc_out[encryptedsize];
    memset(GREENenc_out, 0, sizeof(GREENenc_out));
    unsigned char BLUEenc_out[encryptedsize];
    memset(BLUEenc_out, 0, sizeof(BLUEenc_out));
    
    char* redPaddedMsg = reinterpret_cast<char*>(redPaddedMessage.data());
    char* greenPaddedMsg = reinterpret_cast<char*>(greenPaddedMessage.data());
    char* bluePaddedMsg = reinterpret_cast<char*>(bluePaddedMessage.data());

    cout<<"Generate key: "<<endl;
    // set password
    setPassword();
    AES_KEY enc_key;
    strcpy((char *)aes_key, rsa.password);
    AES_set_encrypt_key(aes_key, keylength, &enc_key);

    unsigned long start = getMicroseconds();
    srand(std::time(nullptr));
    AES_cbc_encrypt((unsigned char*)redPaddedMsg ,REDenc_out, paddedMessageLen, &enc_key, iv_enc, AES_ENCRYPT);
    unsigned long delta = getMicroseconds() - start;
    AES_cbc_encrypt((unsigned char*)greenPaddedMsg ,GREENenc_out, paddedMessageLen, &enc_key, iv_enc, AES_ENCRYPT);
    AES_cbc_encrypt((unsigned char*)bluePaddedMsg ,BLUEenc_out, paddedMessageLen, &enc_key, iv_enc, AES_ENCRYPT);
    double speed = (double)megabytesCount / delta * 1000000;
    cout<< std::fixed<<std::setprecision(2)<<"Encryption performance with openssl : "<<speed<<" Mb/s"<<endl;
     int tmp = 0;
     for(int i =1 ; i<= row-1;i++){
         for(int j=1 ; j<=column-1;j++){
             rgb = bmp[i][j];
             rgb.red = (int)REDenc_out[tmp];
             rgb.green = (int)GREENenc_out[tmp];
             rgb.blue = (int)BLUEenc_out[tmp];
             bmp[i][j] = rgb;
             tmp++;
         }
     }
      image.fromPixelMatrix(bmp);
      image.save("./opensslEncrypted.bmp");
}
void executeDecrypt(){
    // generate_key();
    rsa rsa;
    int row,column;
    unsigned int megabytesCount;
    vector<unsigned char> redString;
    vector <unsigned char> greenString;
    vector <unsigned char> blueString;
     Bitmap image;
     std::vector <std::vector <Pixel> > bmp;
     Pixel rgb;
     string filePath = "./opensslEncrypted.bmp";
    megabytesCount = 4;

    // decrypt password
    decryptPassword();

    image.open(filePath);
    bool validBmp = image.isImage();
    if( validBmp == true ){
    bmp = image.toPixelMatrix();
    row = bmp.size();
    column = bmp[0].size();

    for(int i =1 ; i<= row-1;i++){
        for(int j=1 ; j<=column-1;j++){
            rgb = bmp[i][j];
            int redpix = (int)rgb.red;
            int greenpix = (int)rgb.green;
            int bluepix = (int)rgb.blue;
            redString.push_back((unsigned char)redpix);
            greenString.push_back((unsigned char)greenpix);
            blueString.push_back((unsigned char)bluepix);
        }
    }
    }
     
    size_t originalLen =sizeof(std::vector<int>) + (sizeof(int) *redString.size());
    size_t paddedMessageLen = originalLen;
    if ((paddedMessageLen % 16) != 0) {
        paddedMessageLen = (paddedMessageLen / 16 + 1) * 16;
    }
    
    vector<unsigned char> redPaddedMessage(paddedMessageLen);
    vector<unsigned char> greenPaddedMessage(paddedMessageLen);
    vector<unsigned char> bluePaddedMessage(paddedMessageLen);

    for (int i = 0; i < paddedMessageLen; i++) {
        if (i >= originalLen) {
            redPaddedMessage[i] = 0;
            greenPaddedMessage[i] = 0;
            bluePaddedMessage[i]= 0;
        }
        else {
            redPaddedMessage[i] = redString[i];
            greenPaddedMessage[i] = greenString[i];
            bluePaddedMessage[i]= blueString[i];
        }
    }
    unsigned char iv_enc[AES_BLOCK_SIZE], iv_dec[AES_BLOCK_SIZE];
    RAND_bytes(iv_enc, AES_BLOCK_SIZE);
    memcpy(iv_dec, iv_enc, AES_BLOCK_SIZE);
    // decrypt
    int keylength = 256;
    unsigned char aes_key[keylength/8];
    memset(aes_key, 0, keylength/8);
    
    const size_t encryptedsize = ((paddedMessageLen + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
    unsigned char red_out[encryptedsize];
    memset(red_out, 0, sizeof(red_out));
    unsigned char green_out[encryptedsize];
    memset(green_out, 0, sizeof(green_out));
    unsigned char blue_out[encryptedsize];
    memset(blue_out, 0, sizeof(blue_out));
    
    char* redPaddedMsg = reinterpret_cast<char*>(redPaddedMessage.data());
    char* greenPaddedMsg = reinterpret_cast<char*>(greenPaddedMessage.data());
    char* bluePaddedMsg = reinterpret_cast<char*>(bluePaddedMessage.data());

    AES_KEY dec_key;
    strcpy((char *)aes_key, rsa.password);
    AES_set_decrypt_key(aes_key, keylength, &dec_key);
    unsigned long start = getMicroseconds();
    srand(std::time(nullptr));
    AES_cbc_encrypt((unsigned char*)redPaddedMsg, red_out, encryptedsize ,&dec_key, iv_dec, AES_DECRYPT);
    unsigned long delta = getMicroseconds() - start;
    AES_cbc_encrypt((unsigned char*)greenPaddedMsg, green_out, encryptedsize ,&dec_key, iv_dec, AES_DECRYPT);
    AES_cbc_encrypt((unsigned char*)bluePaddedMsg, blue_out, encryptedsize ,&dec_key, iv_dec, AES_DECRYPT);
     double speed = (double)megabytesCount / delta * 1000000;
    cout<< std::fixed <<std::setprecision(2)<<"Decryption performance with openssl : "<<speed<<" Mb/s"<<endl;
    int tmp = 0;
     for(int i =1 ; i<= row-1;i++){
         for(int j=1 ; j<=column-1;j++){
             rgb = bmp[i][j];
             rgb.red = (int)red_out[tmp];
             rgb.green = (int)green_out[tmp];
             rgb.blue = (int)blue_out[tmp];
             bmp[i][j] = rgb;
             tmp++;
         }
     }
      image.fromPixelMatrix(bmp);
      image.save("./decryptedOpenssl.bmp");
}

void createRSA(){
    rsa rsa;
    RSA *private_key;
    RSA *public_key;

    RSA *keypair = NULL;
    BIGNUM *bne = NULL;
    int ret = 0;
    cout<<"rsa key lenght: "<<KEY_LENGTH;

    bne = BN_new();
    ret = BN_set_word(bne, PUBLIC_EXPONENT);
    if (ret != 1) {
        // goto free_stuff;
        cout<<"error on set word"<<endl;
    }
    keypair = RSA_new();
    ret = RSA_generate_key_ex(keypair, KEY_LENGTH, bne, NULL);
    if (ret != 1) {
        // goto free_stuff;
        LOG("An error occurred in RSA_generate_key_ex() method");
    }
    cout<<"Genereate key"<<endl;

    private_key = rsa.create_RSA(keypair, PRIVATE_KEY_PEM, "private_key.pem");
    cout<<"created private key pem file"<<endl;

    public_key  = rsa.create_RSA(keypair, PUBLIC_KEY_PEM, "public_key.pem");
    cout<<"created public key pem file"<<endl;
    
    RSA_free(keypair);
    free(private_key);
    free(public_key);
 
    BN_free(bne);
}

int main(int argc, char **argv){
   
    cout<<"1. Encrypt\n2. Decrypt\n3. Create RSA Key pair"<<endl;
    int cmd;
    cout<<"Enter command"<<endl;
    cin>>cmd;
    if(cmd == 1){
        executeEncrypt();
    }else if(cmd==2){
        executeDecrypt();
    }else createRSA();
    
    
   return 0;
}
