#include "libaes.h"

Libaes::Libaes()
{
    keylength = 256;
}
void Libaes::executeEncryptLibAES(string filePath){

    Bitmap image;
     std::vector <std::vector <Pixel> > bmp;
     Pixel rgb;
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
//       image.fromPixelMatrix(bmp);
     }
     int originalLen =sizeof(std::vector<int>) + (sizeof(int) *redString.size());
    int paddedMessageLen = originalLen;
     if ((paddedMessageLen % 16) != 0) {

         paddedMessageLen = (paddedMessageLen / 16 + 1) * 16;
//         std::cout<<"padded: "<<paddedMessageLen<<endl;
     }
//     cout<<"original: "<<originalLen;


     /* init vector */
         unsigned char iv_enc[AES_BLOCK_SIZE], iv_dec[AES_BLOCK_SIZE];
//         RAND_bytes(iv_enc, AES_BLOCK_SIZE);
         memcpy(iv_dec, iv_enc, AES_BLOCK_SIZE);
//     encrypt
//     unsigned char aes_key[keylength/8];
//     memset(aes_key, 0, keylength/8);
//      vector<unsigned char*> redPaddedMessage(paddedMessageLen);
//      unsigned char* encryptedRED;
//    AES_KEY enc_key, dec_key;
//    AES_set_encrypt_key(aes_key, keylength, &enc_key);
//    AES_cbc_encrypt((unsigned char *)&redPaddedMessage, encryptedRED, paddedMessageLen, &enc_key, iv_enc, AES_ENCRYPT);

}

