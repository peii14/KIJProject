#include "aes.h"
#include <QDebug>
AES::AES(AESKeyLength keyLength) {
  this->Nb = 4;
  switch (keyLength) {
    case AESKeyLength::AES_128:
      this->Nk = 4;
      this->Nr = 10;
      break;
    case AESKeyLength::AES_192:
      this->Nk = 6;
      this->Nr = 12;
      break;
    case AESKeyLength::AES_256:
      this->Nk = 8;
      this->Nr = 14;
      break;
  }

  blockBytesLen = 4 * this->Nb * sizeof(unsigned char);
}

unsigned char *AES::EncryptECB(unsigned char in[], unsigned int inLen,
                               unsigned char key[]) {
  CheckLength(inLen);
  unsigned char *out = new unsigned char[inLen];
  unsigned char *roundKeys = new unsigned char[4 * Nb * (Nr + 1)];
  KeyExpansion(key, roundKeys);
  for (unsigned int i = 0; i < inLen; i += blockBytesLen) {
    EncryptBlock(in + i, out + i, roundKeys);
  }

  delete[] roundKeys;

  return out;
}

unsigned char *AES::DecryptECB(unsigned char in[], unsigned int inLen,
                               unsigned char key[]) {
  CheckLength(inLen);
  unsigned char *out = new unsigned char[inLen];
  unsigned char *roundKeys = new unsigned char[4 * Nb * (Nr + 1)];
  KeyExpansion(key, roundKeys);
  for (unsigned int i = 0; i < inLen; i += blockBytesLen) {
    DecryptBlock(in + i, out + i, roundKeys);
  }

  delete[] roundKeys;

  return out;
}

unsigned char *AES::EncryptCBC(unsigned char in[], unsigned int inLen,
                               unsigned char key[], unsigned char *iv) {
  CheckLength(inLen);
  unsigned char *out = new unsigned char[inLen];
  unsigned char *block = new unsigned char[blockBytesLen];
  unsigned char *roundKeys = new unsigned char[4 * Nb * (Nr + 1)];
  KeyExpansion(key, roundKeys);
  memcpy(block, iv, blockBytesLen);
  for (unsigned int i = 0; i < inLen; i += blockBytesLen) {
    XorBlocks(block, in + i, block, blockBytesLen);
    EncryptBlock(block, out + i, roundKeys);
    memcpy(block, out + i, blockBytesLen);
  }

  delete[] block;
  delete[] roundKeys;

  return out;
}

unsigned char *AES::DecryptCBC(unsigned char in[], unsigned int inLen,
                               unsigned char key[], unsigned char *iv) {
  CheckLength(inLen);
  unsigned char *out = new unsigned char[inLen];
  unsigned char *block = new unsigned char[blockBytesLen];
  unsigned char *roundKeys = new unsigned char[4 * Nb * (Nr + 1)];
  KeyExpansion(key, roundKeys);
  memcpy(block, iv, blockBytesLen);
  for (unsigned int i = 0; i < inLen; i += blockBytesLen) {
    DecryptBlock(in + i, out + i, roundKeys);
    XorBlocks(block, out + i, out + i, blockBytesLen);
    memcpy(block, in + i, blockBytesLen);
  }

  delete[] block;
  delete[] roundKeys;

  return out;
}

unsigned char *AES::EncryptCFB(unsigned char in[], unsigned int inLen,
                               unsigned char key[], unsigned char *iv) {
  CheckLength(inLen);
  unsigned char *out = new unsigned char[inLen];
  unsigned char *block = new unsigned char[blockBytesLen];
  unsigned char *encryptedBlock = new unsigned char[blockBytesLen];
  unsigned char *roundKeys = new unsigned char[4 * Nb * (Nr + 1)];
  KeyExpansion(key, roundKeys);
  memcpy(block, iv, blockBytesLen);
  for (unsigned int i = 0; i < inLen; i += blockBytesLen) {
    EncryptBlock(block, encryptedBlock, roundKeys);
    XorBlocks(in + i, encryptedBlock, out + i, blockBytesLen);
    memcpy(block, out + i, blockBytesLen);
  }

  delete[] block;
  delete[] encryptedBlock;
  delete[] roundKeys;

  return out;
}

unsigned char *AES::DecryptCFB(unsigned char in[], unsigned int inLen,
                               unsigned char key[], unsigned char *iv) {
  CheckLength(inLen);
  unsigned char *out = new unsigned char[inLen];
  unsigned char *block = new unsigned char[blockBytesLen];
  unsigned char *encryptedBlock = new unsigned char[blockBytesLen];
  unsigned char *roundKeys = new unsigned char[4 * Nb * (Nr + 1)];
  KeyExpansion(key, roundKeys);
  memcpy(block, iv, blockBytesLen);
  for (unsigned int i = 0; i < inLen; i += blockBytesLen) {
    EncryptBlock(block, encryptedBlock, roundKeys);
    XorBlocks(in + i, encryptedBlock, out + i, blockBytesLen);
    memcpy(block, in + i, blockBytesLen);
  }

  delete[] block;
  delete[] encryptedBlock;
  delete[] roundKeys;

  return out;
}

void AES::CheckLength(unsigned int len) {
  if (len % blockBytesLen != 0) {
    throw std::length_error("Plaintext length must be divisible by " +
                            blockBytesLen);
  }
}

void AES::EncryptBlock(unsigned char in[], unsigned char out[],
                       unsigned char *roundKeys) {
  unsigned char **state = new unsigned char *[4];
  state[0] = new unsigned char[4 * Nb];
  int i, j, round;
  for (i = 0; i < 4; i++) {
    state[i] = state[0] + Nb * i;
  }

  for (i = 0; i < 4; i++) {
    for (j = 0; j < Nb; j++) {
      state[i][j] = in[i + 4 * j];
    }
  }

  AddRoundKey(state, roundKeys);

  for (round = 1; round <= Nr - 1; round++) {
    SubBytes(state);
    ShiftRows(state);
    MixColumns(state);
    AddRoundKey(state, roundKeys + round * 4 * Nb);
  }

  SubBytes(state);
  ShiftRows(state);
  AddRoundKey(state, roundKeys + Nr * 4 * Nb);

  for (i = 0; i < 4; i++) {
    for (j = 0; j < Nb; j++) {
      out[i + 4 * j] = state[i][j];
    }
  }

  delete[] state[0];
  delete[] state;
}

void AES::DecryptBlock(unsigned char in[], unsigned char out[],
                       unsigned char *roundKeys) {
  unsigned char **state = new unsigned char *[4];
  state[0] = new unsigned char[4 * Nb];
  int i, j, round;
  for (i = 0; i < 4; i++) {
    state[i] = state[0] + Nb * i;
  }

  for (i = 0; i < 4; i++) {
    for (j = 0; j < Nb; j++) {
      state[i][j] = in[i + 4 * j];
    }
  }

  AddRoundKey(state, roundKeys + Nr * 4 * Nb);

  for (round = Nr - 1; round >= 1; round--) {
    InvSubBytes(state);
    InvShiftRows(state);
    AddRoundKey(state, roundKeys + round * 4 * Nb);
    InvMixColumns(state);
  }

  InvSubBytes(state);
  InvShiftRows(state);
  AddRoundKey(state, roundKeys);

  for (i = 0; i < 4; i++) {
    for (j = 0; j < Nb; j++) {
      out[i + 4 * j] = state[i][j];
    }
  }

  delete[] state[0];
  delete[] state;
}

void AES::SubBytes(unsigned char **state) {
  int i, j;
  unsigned char t;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < Nb; j++) {
      t = state[i][j];
      state[i][j] = sbox[t / 16][t % 16];
    }
  }
}

void AES::ShiftRow(unsigned char **state, int i,
                   int n)  // shift row i on n positions
{
  unsigned char *tmp = new unsigned char[Nb];
  for (int j = 0; j < Nb; j++) {
    tmp[j] = state[i][(j + n) % Nb];
  }
  memcpy(state[i], tmp, Nb * sizeof(unsigned char));

  delete[] tmp;
}

void AES::ShiftRows(unsigned char **state) {
  ShiftRow(state, 1, 1);
  ShiftRow(state, 2, 2);
  ShiftRow(state, 3, 3);
}

unsigned char AES::xtime(unsigned char b)  // multiply on x
{
  return (b << 1) ^ (((b >> 7) & 1) * 0x1b);
}

void AES::MixColumns(unsigned char **state) {
  unsigned char temp_state[4][4];

  for (size_t i = 0; i < 4; ++i) {
    memset(temp_state[i], 0, 4);
  }

  for (size_t i = 0; i < 4; ++i) {
    for (size_t k = 0; k < 4; ++k) {
      for (size_t j = 0; j < 4; ++j) {
        if (CMDS[i][k] == 1)
          temp_state[i][j] ^= state[k][j];
        else
          temp_state[i][j] ^= GF_MUL_TABLE[CMDS[i][k]][state[k][j]];
      }
    }
  }

  for (size_t i = 0; i < 4; ++i) {
    memcpy(state[i], temp_state[i], 4);
  }
}

void AES::AddRoundKey(unsigned char **state, unsigned char *key) {
  int i, j;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < Nb; j++) {
      state[i][j] = state[i][j] ^ key[i + 4 * j];
    }
  }
}

void AES::SubWord(unsigned char *a) {
  int i;
  for (i = 0; i < 4; i++) {
    a[i] = sbox[a[i] / 16][a[i] % 16];
  }
}

void AES::RotWord(unsigned char *a) {
  unsigned char c = a[0];
  a[0] = a[1];
  a[1] = a[2];
  a[2] = a[3];
  a[3] = c;
}

void AES::XorWords(unsigned char *a, unsigned char *b, unsigned char *c) {
  int i;
  for (i = 0; i < 4; i++) {
    c[i] = a[i] ^ b[i];
  }
}

void AES::Rcon(unsigned char *a, int n) {
  int i;
  unsigned char c = 1;
  for (i = 0; i < n - 1; i++) {
    c = xtime(c);
  }

  a[0] = c;
  a[1] = a[2] = a[3] = 0;
}

void AES::KeyExpansion(unsigned char key[], unsigned char w[]) {
  unsigned char *temp = new unsigned char[4];
  unsigned char *rcon = new unsigned char[4];

  int i = 0;
  while (i < 4 * Nk) {
    w[i] = key[i];
    i++;
  }

  i = 4 * Nk;
  while (i < 4 * Nb * (Nr + 1)) {
    temp[0] = w[i - 4 + 0];
    temp[1] = w[i - 4 + 1];
    temp[2] = w[i - 4 + 2];
    temp[3] = w[i - 4 + 3];

    if (i / 4 % Nk == 0) {
      RotWord(temp);
      SubWord(temp);
      Rcon(rcon, i / (Nk * 4));
      XorWords(temp, rcon, temp);
    } else if (Nk > 6 && i / 4 % Nk == 4) {
      SubWord(temp);
    }

    w[i + 0] = w[i - 4 * Nk] ^ temp[0];
    w[i + 1] = w[i + 1 - 4 * Nk] ^ temp[1];
    w[i + 2] = w[i + 2 - 4 * Nk] ^ temp[2];
    w[i + 3] = w[i + 3 - 4 * Nk] ^ temp[3];
    i += 4;
  }

  delete[] rcon;
  delete[] temp;
}

void AES::InvSubBytes(unsigned char **state) {
  int i, j;
  unsigned char t;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < Nb; j++) {
      t = state[i][j];
      state[i][j] = inv_sbox[t / 16][t % 16];
    }
  }
}

void AES::InvMixColumns(unsigned char **state) {
  unsigned char temp_state[4][4];

  for (size_t i = 0; i < 4; ++i) {
    memset(temp_state[i], 0, 4);
  }

  for (size_t i = 0; i < 4; ++i) {
    for (size_t k = 0; k < 4; ++k) {
      for (size_t j = 0; j < 4; ++j) {
        temp_state[i][j] ^= GF_MUL_TABLE[INV_CMDS[i][k]][state[k][j]];
      }
    }
  }

  for (size_t i = 0; i < 4; ++i) {
    memcpy(state[i], temp_state[i], 4);
  }
}

void AES::InvShiftRows(unsigned char **state) {
  ShiftRow(state, 1, Nb - 1);
  ShiftRow(state, 2, Nb - 2);
  ShiftRow(state, 3, Nb - 3);
}

void AES::XorBlocks(unsigned char *a, unsigned char *b, unsigned char *c,
                    unsigned int len) {
  for (unsigned int i = 0; i < len; i++) {
    c[i] = a[i] ^ b[i];
  }
}

void AES::printHexArray(unsigned char a[], unsigned int n) {
  for (unsigned int i = 0; i < n; i++) {
    printf("%02x ", a[i]);
  }
}

void AES::printHexVector(std::vector<unsigned char> a) {
  for (unsigned int i = 0; i < a.size(); i++) {
    printf("%02x ", a[i]);
  }
}

std::vector<unsigned char> AES::ArrayToVector(unsigned char *a,
                                              unsigned int len) {
  std::vector<unsigned char> v(a, a + len * sizeof(unsigned char));
  return v;
}

unsigned char *AES::VectorToArray(std::vector<unsigned char> a) {
  return a.data();
}


std::vector<unsigned char> AES::EncryptCBC(std::vector<unsigned char> in,
                                           std::vector<unsigned char> key,
                                           std::vector<unsigned char> iv) {
  unsigned char *out = EncryptCBC(VectorToArray(in), (unsigned int)in.size(),
                                  VectorToArray(key), VectorToArray(iv));
  std::vector<unsigned char> v = ArrayToVector(out, in.size());
  delete[] out;
  return v;
}

std::vector<unsigned char> AES::DecryptCBC(std::vector<unsigned char> in,
                                           std::vector<unsigned char> key,
                                           std::vector<unsigned char> iv) {
  unsigned char *out = DecryptCBC(VectorToArray(in), (unsigned int)in.size(),
                                  VectorToArray(key), VectorToArray(iv));
  std::vector<unsigned char> v = ArrayToVector(out, (unsigned int)in.size());
  delete[] out;
  return v;
}


void AES::write(vector<unsigned char> v,string fileName){
    ofstream file;
    file.open(fileName);
    for(int i=0;i<v.size();++i){
        file<<(int)v[i]<<endl;
    }
    file.close();
}
void AES::executeAES(std::string filePath,string password){
    const unsigned int BLOCK_BYTES_LENGTH = 16 * sizeof(unsigned char);
    megabytesCount = filesize(filePath.c_str());
    Bitmap image;
     std::vector <std::vector <Pixel> > bmp;
     Pixel rgb;
     image.open(filePath);
     bool validBmp = image.isImage();

     if( validBmp == true ){
       bmp = image.toPixelMatrix();
       row = bmp.size();
       column = bmp[0].size();
       std::cout << "Rows in the 2d vector: " <<row <<
        std::endl << "Collumns in the 1st row: " <<column<< std::endl;

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

       image.fromPixelMatrix(bmp);
     }
//     padding
     int originalLen =sizeof(std::vector<int>) + (sizeof(int) *redString.size());
    int paddedMessageLen = originalLen;
//    write(redString,"/Users/gayuhkautaman/Documents/code/cpp/KIJProject/redstring.txt");

    if ((paddedMessageLen % 16) != 0) {

        paddedMessageLen = (paddedMessageLen / 16 + 1) * 16;
        cout<<"padded: "<<paddedMessageLen<<endl;
    }
    cout<<"original: "<<originalLen;

    vector<unsigned char> redPaddedMessage(paddedMessageLen);
    vector<unsigned char> greenPaddedMessage(paddedMessageLen);
    vector<unsigned char> bluePaddedMessage(paddedMessageLen);
    qDebug()<<"spliting RGB";
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

    //    encrypt
        std::vector<unsigned char> iv = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                                          0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                                          0xff, 0xff, 0xff, 0xff};
//        set password
        vector <unsigned char> key(password.begin(),password.end());
        std::vector<unsigned char> key2 = {
                     0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a,
                     0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0x10, 0x11, 0x12, 0x13, 0x14, 0x15,
                     0x16, 0x17, 0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f};

        if (key.size()<32){
            int remain = 32 - key.size();
            for (int i=0;i<remain;i++){
                key.push_back(i);
            }
        }
        qDebug()<<"Ekey"<<key;
        AES aes(AESKeyLength::AES_256);
        qDebug()<<"Start Timer";
        unsigned long start = getMicroseconds();
        srand(std::time(nullptr));
        vector<unsigned char> encryptedRed = aes.EncryptCBC(redPaddedMessage,key,iv);
        unsigned long delta = getMicroseconds() - start;
        vector<unsigned char> encryptedGreen = aes.EncryptCBC(greenPaddedMessage,key,iv);
        vector<unsigned char> encryptedBlue = aes.EncryptCBC(bluePaddedMessage,key,iv);
        speed = (double)megabytesCount / delta * MICROSECONDS;
        speed = round(speed*100)/100;
        qDebug()<<"encrypted";
        qDebug()<<"Constructing to BMP";
        int tmp = 0;
        for(int i =1 ; i<= row-1;i++){
            for(int j=1 ; j<=column-1;j++){
                rgb = bmp[i][j];
                rgb.red = (int)encryptedRed[tmp];
                rgb.green = (int)encryptedGreen[tmp];
                rgb.blue = (int)encryptedBlue[tmp];
                bmp[i][j] = rgb;
                tmp++;
            }
        }
         image.fromPixelMatrix(bmp);
         image.save("/Users/gayuhkautaman/Documents/code/cpp/KIJProject/encrypted.bmp");
}
unsigned long AES::getMicroseconds(){
  struct timeval tv;
  gettimeofday(&tv,NULL);
  return MICROSECONDS * tv.tv_sec + tv.tv_usec;
}
std::ifstream::pos_type AES::filesize(const char* filename)
{
    std::ifstream in(filename, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}


void AES::executeDecryptAES(string filePath,string password){
     megabytesCount = filesize(filePath.c_str());
     Bitmap image;
     std::vector <std::vector <Pixel> > bmp;
     Pixel rgb;
     image.open(filePath);
     bool validBmp = image.isImage();

     if( validBmp == true ){
       bmp = image.toPixelMatrix();
       row = bmp.size();
       column = bmp[0].size();
       std::cout << "Rows in the 2d vector: " <<row <<
        std::endl << "Collumns in the 1st row: " <<column<< std::endl;

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
         cout<<"padded: "<<paddedMessageLen<<endl;
     }
     cout<<"original: "<<originalLen;

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


//     decrypt
     std::vector<unsigned char> iv = {0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                                       0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
                                       0xff, 0xff, 0xff, 0xff};
     std::vector<unsigned char> key(password.begin(),password.end());
     if (key.size()<32){
         int remain = 32 - key.size();
         for (int i=0;i<remain;i++){
             key.push_back(i);
         }
     }
     AES aes(AESKeyLength::AES_256);
     qDebug()<<"Start Decrypt Timer";
     unsigned long start = getMicroseconds();
     srand(std::time(nullptr));
     vector<unsigned char> encryptedRed = aes.DecryptCBC(redPaddedMessage,key,iv);
     unsigned long delta = getMicroseconds() - start;
     vector<unsigned char> encryptedGreen = aes.DecryptCBC(greenPaddedMessage,key,iv);
     vector<unsigned char> encryptedBlue = aes.DecryptCBC(bluePaddedMessage,key,iv);
     int tmp = 0;
     speed = (double)megabytesCount / delta * MICROSECONDS;
     speed = ceil(speed*100)/100;
     qDebug()<<"Constructing to BMP";
     for(int i =1 ; i<= row-1;i++){
         for(int j=1 ; j<=column-1;j++){
             rgb = bmp[i][j];
             rgb.red = (int)encryptedRed[tmp];
             rgb.green = (int)encryptedGreen[tmp];
             rgb.blue = (int)encryptedBlue[tmp];
             bmp[i][j] = rgb;
             tmp++;
         }
     }
      image.fromPixelMatrix(bmp);
      image.save("/Users/gayuhkautaman/Documents/code/cpp/KIJProject/decrypted.bmp");

}


