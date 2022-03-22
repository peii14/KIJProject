#include "nativeaes.h"
#include "bitmap.h"
#include <cstdio>
NativeAesEncrypt::NativeAesEncrypt()
{

}

void NativeAesEncrypt::KeyExpansion(unsigned char inputKey[16], unsigned char expandedKeys[176]){
// copy the original 16 bytes to the original key
    for (int i = 0; i < 16; i++) {
        expandedKeys[i] = inputKey[i];
    }
    int bytesGenerated = 16; // bytes generated so far
    int rconIteration = 1; // keeps track of rcon value
    unsigned char tmpCore[4]; // temp storage for core

    // main loop
    while (bytesGenerated < 176) {
        /* Read 4 bytes for the core
        * They are the previously generated 4 bytes
        * Initially, these will be the final 4 bytes of the original key
        */
        for (int i = 0; i < 4; i++) {
            tmpCore[i] = expandedKeys[i + bytesGenerated - 4];
        }

        // perform the core once for each 16 bytes loop / 1 key kreated
        if (bytesGenerated % 16 == 0) {
            KeyExpansionCore(tmpCore, rconIteration++);
        }

        // XOR the first 4 bytes with tempCore value then store that as the next 4 bytes
        for (unsigned char a = 0; a < 4; a++) {
            expandedKeys[bytesGenerated] = expandedKeys[bytesGenerated - 16] ^ tmpCore[a];
            bytesGenerated++;
        }

    }
}
void NativeAesEncrypt::AddRoundKey(unsigned char *state, unsigned char *roundKey){
for (int i = 0; i < 16; i++)
        state[i] ^= roundKey[i];
}

void NativeAesEncrypt::ShiftRows(unsigned char *state){
    unsigned char tmp[16];

        /* Column 1 */
        tmp[0] = state[0];
        tmp[1] = state[5];
        tmp[2] = state[10];
        tmp[3] = state[15];

        /* Column 2 */
        tmp[4] = state[4];
        tmp[5] = state[9];
        tmp[6] = state[14];
        tmp[7] = state[3];

        /* Column 3 */
        tmp[8] = state[8];
        tmp[9] = state[13];
        tmp[10] = state[2];
        tmp[11] = state[7];

        /* Column 4 */
        tmp[12] = state[12];
        tmp[13] = state[1];
        tmp[14] = state[6];
        tmp[15] = state[11];

        for (int i = 0; i < 16; i++) {
            state[i] = tmp[i];
        }
}
void NativeAesEncrypt::MixColumns(unsigned char *state){
    unsigned char tmp[16];

        tmp[0] = (unsigned char) mul2[state[0]] ^ mul3[state[1]] ^ state[2] ^ state[3];
        tmp[1] = (unsigned char) state[0] ^ mul2[state[1]] ^ mul3[state[2]] ^ state[3];
        tmp[2] = (unsigned char) state[0] ^ state[1] ^ mul2[state[2]] ^ mul3[state[3]];
        tmp[3] = (unsigned char) mul3[state[0]] ^ state[1] ^ state[2] ^ mul2[state[3]];

        tmp[4] = (unsigned char)mul2[state[4]] ^ mul3[state[5]] ^ state[6] ^ state[7];
        tmp[5] = (unsigned char)state[4] ^ mul2[state[5]] ^ mul3[state[6]] ^ state[7];
        tmp[6] = (unsigned char)state[4] ^ state[5] ^ mul2[state[6]] ^ mul3[state[7]];
        tmp[7] = (unsigned char)mul3[state[4]] ^ state[5] ^ state[6] ^ mul2[state[7]];

        tmp[8] = (unsigned char)mul2[state[8]] ^ mul3[state[9]] ^ state[10] ^ state[11];
        tmp[9] = (unsigned char)state[8] ^ mul2[state[9]] ^ mul3[state[10]] ^ state[11];
        tmp[10] = (unsigned char)state[8] ^ state[9] ^ mul2[state[10]] ^ mul3[state[11]];
        tmp[11] = (unsigned char)mul3[state[8]] ^ state[9] ^ state[10] ^ mul2[state[11]];

        tmp[12] = (unsigned char)mul2[state[12]] ^ mul3[state[13]] ^ state[14] ^ state[15];
        tmp[13] = (unsigned char)state[12] ^ mul2[state[13]] ^ mul3[state[14]] ^ state[15];
        tmp[14] = (unsigned char)state[12] ^ state[13] ^ mul2[state[14]] ^ mul3[state[15]];
        tmp[15] = (unsigned char)mul3[state[12]] ^ state[13] ^ state[14] ^ mul2[state[15]];

        for (int i = 0; i < 16; i++) {
            state[i] = tmp[i];
        }
}

void NativeAesEncrypt::SubBytes(unsigned char * state){
    for (int i = 0; i < 16; i++) {
        state[i] = s[state[i]];
    }
}

void NativeAesEncrypt::Round(unsigned char *state, unsigned char *key){
    SubBytes(state);
    ShiftRows(state);
    MixColumns(state);
    AddRoundKey(state, key);
}
void NativeAesEncrypt::FinalRound(unsigned char *state, unsigned char *key){
    SubBytes(state);
    ShiftRows(state);
    AddRoundKey(state, key);
}

void NativeAesEncrypt::AESEncrypt(unsigned char *message, unsigned char *expandedKey, unsigned char *encryptedMessage){
    unsigned char state[16]; // Stores the first 16 bytes of original message

    for (int i = 0; i < 16; i++) {
        state[i] = message[i];
    }

    int numberOfRounds = 9;

    AddRoundKey(state, expandedKey); // Initial round

    for (int i = 0; i < numberOfRounds; i++) {
        Round(state, expandedKey + (16 * (i+1)));
    }

    FinalRound(state, expandedKey + 160);

    // Copy encrypted state to buffer
    for (int i = 0; i < 16; i++) {
        encryptedMessage[i] = state[i];
    }
}

void NativeAesEncrypt::readImage(string imagePath){
    std::ifstream image;
    image.open(imagePath);
    if ( ! image ) {
        std::cout << "There is no input file.\n";
//        exit(1);
    }else{
        while(image){//inputing the plain from a file
            std::string line; getline(image, line);
            imagestring+=line+'\n'; //it's a binary file not a text file
        }
        imagestring = imagestring.substr(0, imagestring.size()-2); //there are 2 extra newlines(\n)
    }
    image.close();


   originalLen= imagestring.size();//file size
    int i; //index

    //check if this is a BMP image
    if(!(imagestring[0] == 'B' && imagestring[1] == 'M')){
        std::cout<<"This file is not of the format BMP"<<std::endl;
//        exit(1);
    }

    i = (0xff & static_cast<char>(imagestring[10])) +             // i is set to
     (0xff & static_cast<char>(imagestring[11]))* 256 +           // the value at
      (0xff & static_cast<char>(imagestring[12]))* 256* 256 +     // which the
       (0xff & static_cast<char>(imagestring[13]))* 256* 256* 256;// pixels start
    //
    for(int j= 0; j < i; j++){
       imageheader+= imagestring[j];
   }

   //read pixels
   for(i; i < originalLen; i++){
       plaintext+= imagestring[i];
   }// in the file

}


void NativeAesEncrypt::ExecuteEncrypt(string filePath){

//    readImage(filePath);

    Bitmap image;
     vector <vector <Pixel> > bmp;
     Pixel rgb;

     //read a file example.bmp and convert it to a pixel matrix
     image.open(filePath);

     //verify that the file opened was a valid image
     bool validBmp = image.isImage();
     if( validBmp == true ){
       bmp = image.toPixelMatrix();
       int row = bmp.size();
       int column = bmp[0].size();
       std::cout << "Rows in the 2d vector: " <<row <<
           std::endl << "Collumns in the 1st row: " <<column<< std::endl;


       for(int i =1 ; i<= row-1;i++){
           for(int j=1 ; j<=column-1;j++){
               rgb = bmp[i][j];
               redString.append(to_string(rgb.red));
               redString.append(",");
               greenString.append(to_string(rgb.green));
               greenString.append(",");
               blueString.append(to_string(rgb.blue));
               blueString.append(",");
              bmp[i][j] = rgb;
           }
       }
       //put changed image back into matrix, update the bitmap and save it

       image.fromPixelMatrix(bmp);
//       image.save("/Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/example.bmp");
     }

// pad message to 16 bytes - so that it can take more than 16 bytes of message
    int redLen = redString.size();
    int paddedMessageLen = redLen;
    // round the message to 16 byte boundary
    if ((paddedMessageLen % 16) != 0) {
        paddedMessageLen = (paddedMessageLen / 16 + 1) * 16;
    }

    // add 0 to the end of the message
    unsigned char * redPaddedMessage = new unsigned char[paddedMessageLen];
    unsigned char * greenPaddedMessage = new unsigned char[paddedMessageLen];
    unsigned char * bluePaddedMessage = new unsigned char[paddedMessageLen];
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

    unsigned char * redEncryptedMessage = new unsigned char[paddedMessageLen];
    unsigned char * greenEncryptedMessage = new unsigned char[paddedMessageLen];
    unsigned char * blueEncryptedMessage = new unsigned char[paddedMessageLen];

    // assign the key
    unsigned char key[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    unsigned char expandedKey[176];
    KeyExpansion(key, expandedKey);

    cout<<redPaddedMessage<<endl;
    ofstream redfile("/Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/paddedMSG_RED_file.txt");
    ofstream greenfile("/Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/paddedMSG_GREEN_file.txt");
    ofstream bluefile("/Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/paddedMSG_BLUE_file.txt");
    for (int i = 0; i < paddedMessageLen; i++) {
       redfile << redEncryptedMessage;
       greenfile << greenEncryptedMessage;
       bluefile << blueEncryptedMessage;
    }
    redfile.close();
    greenfile.close();
    bluefile.close();

    // start encrypting padded message
    for (int i = 0; i < paddedMessageLen; i += 16) {
        AESEncrypt(redPaddedMessage+i, expandedKey, redEncryptedMessage+i);
        AESEncrypt(greenPaddedMessage+i, expandedKey, greenEncryptedMessage+i);
        AESEncrypt(bluePaddedMessage+i, expandedKey, blueEncryptedMessage+i);
    }

    cout << "Encrypted" << endl;
//    for (int i = 0; i < paddedMessageLen; i++) {
//        cout << hex << (int) redEncryptedMessage[i];
//        cout << " ";
//    }

    cout << endl;
    ofstream redfile("/Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/encrypted_RED_file.txt");
    ofstream greenfile("/Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/encrypted_GREEN_file.txt");
    ofstream bluefile("/Users/gayuhkautaman/Documents/code/cpp/AES-KIJ/encrypted_BLUE_file.txt");
    for (int i = 0; i < paddedMessageLen; i++) {
       redfile << redEncryptedMessage;
       greenfile << greenEncryptedMessage;
       bluefile << blueEncryptedMessage;
    }
    redfile.close();
    greenfile.close();
    bluefile.close();
    cout << "Wrote encrypted message to encrypted_file" << endl;

    // Free memory
    delete[] redPaddedMessage;
    delete[] redEncryptedMessage;
    delete[] greenPaddedMessage;
    delete[] greenEncryptedMessage;
    delete[] bluePaddedMessage;
    delete[] blueEncryptedMessage;
}





