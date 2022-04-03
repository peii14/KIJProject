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
#include <ctime>
#include <openssl/sha.h>
#include <sys/time.h>

using namespace std;

void hex_print(const void* pv, size_t len)
{
const unsigned char * p = (const unsigned char*)pv;
if (NULL == pv)
    printf("NULL");
else
{
    size_t i = 0;
    for (; i<len;++i)
        printf("%02X ", *p++);
}
printf("\n");
}
unsigned long getMicroseconds(){
const unsigned int MICROSECONDS = 1000000;
  struct timeval tv;
  gettimeofday(&tv,NULL);
  return MICROSECONDS * tv.tv_sec + tv.tv_usec;
}

std::ifstream::pos_type filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}
void executeEncrypt(){
    int row,column;
    unsigned int megabytesCount;
    
    vector<unsigned char> redString;
    vector <unsigned char> greenString;
    vector <unsigned char> blueString;
     Bitmap image;
     std::vector <std::vector <Pixel> > bmp;
     Pixel rgb;
     string filePath = "/Users/gayuhkautaman/Documents/code/cpp/KIJProject/dams.bmp";
     megabytesCount = filesize(filePath.c_str());
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

    AES_KEY enc_key, dec_key;
    string password = "password123";
    unsigned char key[keylength];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256,password.data(),password.size());
    SHA256_Final(key,&sha256);

    AES_set_encrypt_key(aes_key, keylength, &enc_key);
    unsigned long start = getMicroseconds();
    srand(std::time(nullptr));
    AES_cbc_encrypt((unsigned char*)redPaddedMsg ,REDenc_out, paddedMessageLen, &enc_key, iv_enc, AES_ENCRYPT);
    unsigned long delta = getMicroseconds() - start;
    AES_cbc_encrypt((unsigned char*)greenPaddedMsg ,GREENenc_out, paddedMessageLen, &enc_key, iv_enc, AES_ENCRYPT);
    AES_cbc_encrypt((unsigned char*)bluePaddedMsg ,BLUEenc_out, paddedMessageLen, &enc_key, iv_enc, AES_ENCRYPT);
    double speed = (double)megabytesCount / delta * 1000000;
    cout<<"Encryption performance with openssl : "<<speed<<" Mb/s"<<endl;
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
      image.save("/Users/gayuhkautaman/Documents/code/cpp/KIJProject/KIJ-openssl/opensslEncrypted.bmp");
}
void executeDecrypt(){
    int row,column;
    unsigned int megabytesCount;
    vector<unsigned char> redString;
    vector <unsigned char> greenString;
    vector <unsigned char> blueString;
     Bitmap image;
     std::vector <std::vector <Pixel> > bmp;
     Pixel rgb;
     string filePath = "/Users/gayuhkautaman/Documents/code/cpp/KIJProject/KIJ-openssl/opensslEncrypted.bmp";
    megabytesCount = filesize(filePath.c_str());
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

    AES_KEY enc_key, dec_key;
    AES_set_decrypt_key(aes_key, keylength, &dec_key);
    unsigned long start = getMicroseconds();
    srand(std::time(nullptr));
    AES_cbc_encrypt((unsigned char*)redPaddedMsg, red_out, encryptedsize ,&dec_key, iv_dec, AES_DECRYPT);
    unsigned long delta = getMicroseconds() - start;
    AES_cbc_encrypt((unsigned char*)greenPaddedMsg, red_out, encryptedsize ,&dec_key, iv_dec, AES_DECRYPT);
    AES_cbc_encrypt((unsigned char*)bluePaddedMsg, red_out, encryptedsize ,&dec_key, iv_dec, AES_DECRYPT);
     double speed = (double)megabytesCount / delta * 1000000;
    cout<<"Decryption performance with openssl : "<<speed<<" Mb/s"<<endl;
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
      image.save("/Users/gayuhkautaman/Documents/code/cpp/KIJProject/KIJ-openssl/decryptedOpenssl.bmp");
}

int main(int argc, char **argv){
   
    
    cout<<"1. Encrypt\n2. Decrypt"<<endl;
    int cmd;
    cout<<"Enter command"<<endl;
    cin>>cmd;
    if(cmd == 1){
        executeEncrypt();
    }else{
        executeDecrypt();
    }
    
    
   return 0;
}
