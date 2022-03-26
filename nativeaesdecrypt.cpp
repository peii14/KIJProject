#include "nativeaesdecrypt.h"
#include "bitmap.h"
NativeAesDecrypt::NativeAesDecrypt()
{

}
void NativeAesDecrypt::SubRoundKey(unsigned char *state, unsigned char *roundKey){
    for (int i = 0; i < 16; i++) {
            state[i] ^= roundKey[i];
        }
}
void NativeAesDecrypt::InverseMixColumns(unsigned char *state){
    unsigned char tmp[16];
        tmp[0] = (unsigned char)mul14[state[0]] ^ mul11[state[1]] ^ mul13[state[2]] ^ mul9[state[3]];
        tmp[1] = (unsigned char)mul9[state[0]] ^ mul14[state[1]] ^ mul11[state[2]] ^ mul13[state[3]];
        tmp[2] = (unsigned char)mul13[state[0]] ^ mul9[state[1]] ^ mul14[state[2]] ^ mul11[state[3]];
        tmp[3] = (unsigned char)mul11[state[0]] ^ mul13[state[1]] ^ mul9[state[2]] ^ mul14[state[3]];

        tmp[4] = (unsigned char)mul14[state[4]] ^ mul11[state[5]] ^ mul13[state[6]] ^ mul9[state[7]];
        tmp[5] = (unsigned char)mul9[state[4]] ^ mul14[state[5]] ^ mul11[state[6]] ^ mul13[state[7]];
        tmp[6] = (unsigned char)mul13[state[4]] ^ mul9[state[5]] ^ mul14[state[6]] ^ mul11[state[7]];
        tmp[7] = (unsigned char)mul11[state[4]] ^ mul13[state[5]] ^ mul9[state[6]] ^ mul14[state[7]];

        tmp[8] = (unsigned char)mul14[state[8]] ^ mul11[state[9]] ^ mul13[state[10]] ^ mul9[state[11]];
        tmp[9] = (unsigned char)mul9[state[8]] ^ mul14[state[9]] ^ mul11[state[10]] ^ mul13[state[11]];
        tmp[10] = (unsigned char)mul13[state[8]] ^ mul9[state[9]] ^ mul14[state[10]] ^ mul11[state[11]];
        tmp[11] = (unsigned char)mul11[state[8]] ^ mul13[state[9]] ^ mul9[state[10]] ^ mul14[state[11]];

        tmp[12] = (unsigned char)mul14[state[12]] ^ mul11[state[13]] ^ mul13[state[14]] ^ mul9[state[15]];
        tmp[13] = (unsigned char)mul9[state[12]] ^ mul14[state[13]] ^ mul11[state[14]] ^ mul13[state[15]];
        tmp[14] = (unsigned char)mul13[state[12]] ^ mul9[state[13]] ^ mul14[state[14]] ^ mul11[state[15]];
        tmp[15] = (unsigned char)mul11[state[12]] ^ mul13[state[13]] ^ mul9[state[14]] ^ mul14[state[15]];

        for (int i = 0; i < 16; i++) {
            state[i] = tmp[i];
        }
}

void NativeAesDecrypt::ShiftRows(unsigned char * state){
    unsigned char tmp[16];
    /* Column 1 */
    tmp[0] = state[0];
    tmp[1] = state[13];
    tmp[2] = state[10];
    tmp[3] = state[7];

    /* Column 2 */
    tmp[4] = state[4];
    tmp[5] = state[1];
    tmp[6] = state[14];
    tmp[7] = state[11];

    /* Column 3 */
    tmp[8] = state[8];
    tmp[9] = state[5];
    tmp[10] = state[2];
    tmp[11] = state[15];

    /* Column 4 */
    tmp[12] = state[12];
    tmp[13] = state[9];
    tmp[14] = state[6];
    tmp[15] = state[3];

    for (int i = 0; i < 16; i++) {
        state[i] = tmp[i];
    }
}
void NativeAesDecrypt::SubBytes(unsigned char * state){
    for (int i = 0; i < 16; i++) { // Perform substitution to each of the 16 bytes
            state[i] = inv_s[state[i]];
        }
}

void NativeAesDecrypt::Round(unsigned char * state, unsigned char * key) {
    SubRoundKey(state, key);
    InverseMixColumns(state);
    ShiftRows(state);
    SubBytes(state);
}
void NativeAesDecrypt::InitialRound(unsigned char * state, unsigned char * key) {
    SubRoundKey(state, key);
    ShiftRows(state);
    SubBytes(state);
}

void NativeAesDecrypt::AESDecrypt(unsigned char * encryptedMessage, unsigned char * expandedKey, unsigned char * decryptedMessage)
{
    unsigned char state[16]; // Stores the first 16 bytes of encrypted message

    for (int i = 0; i < 16; i++) {
        state[i] = encryptedMessage[i];
    }

    InitialRound(state, expandedKey+160);

    int numberOfRounds = 9;

    for (int i = 8; i >= 0; i--) {
        Round(state, expandedKey + (16 * (i + 1)));
    }

    SubRoundKey(state, expandedKey); // Final round

    // Copy decrypted state to buffer
    for (int i = 0; i < 16; i++) {
        decryptedMessage[i] = state[i];
    }
}
vector<string> explode(const string& str, const char& ch) {
    string next;
    vector<string> result;

    // For each character in the string
    for (string::const_iterator it = str.begin(); it != str.end(); it++) {
        // If we've hit the terminal character
        if (*it == ch) {
            // If we have some characters accumulated
            if (!next.empty()) {
                // Add them to the result vector
                result.push_back(next);
                next.clear();
            }
        } else {
            // Accumulate the next character into the sequence
            next += *it;
        }
    }
    if (!next.empty())
         result.push_back(next);
    return result;
}


void NativeAesDecrypt::executeDecrypt(){


    // Read in the message from message.aes
        string redmgstr,greenmgstr,bluemsgstr;
        ifstream redfile,greenfile,bluefile;
        redfile.open("D:\\coding\\QT_Projects\\KIJProject\\encrypted_RED_file.txt", ios::in | ios::binary);
        greenfile.open("D:\\coding\\QT_Projects\\KIJProject\\encrypted_GREEN_file.txt", ios::in | ios::binary);
        bluefile.open("D:\\coding\\QT_Projects\\KIJProject\\encrypted_BLUE_file.txt", ios::in | ios::binary);

        if (redfile.is_open()){
            getline(redfile, redmgstr); // The first line of file is the message
            cout << "Read in encrypted message from red" << endl;
            redfile.close();
        }
        if (greenfile.is_open()){
            getline(greenfile, greenmgstr); // The first line of file is the message
            cout << "Read in encrypted message from green" << endl;
            greenfile.close();
        }
        if (bluefile.is_open()){
            getline(bluefile, bluemsgstr); // The first line of file is the message
            cout << "Read in encrypted message from blue" << endl;
            bluefile.close();
        }

        else cout << "Unable to open file";

        char * redmsg = new char[redmgstr.size()+1];
        char * greenmsg = new char[greenmgstr.size()+1];
        char * bluemsg = new char[bluemsgstr.size()+1];


        std::strcpy(redmsg, redmgstr.c_str());
        std::strcpy(greenmsg, greenmgstr.c_str());
        std::strcpy(bluemsg, bluemsgstr.c_str());

        int n = strlen((const char*)redmsg);

        unsigned char * redencryptedMessage = new unsigned char[n];
        unsigned char * greenencryptedMessage = new unsigned char[n];
        unsigned char * blueencryptedMessage = new unsigned char[n];

        for (int i = 0; i < n; i++) {
            redencryptedMessage[i] = (unsigned char)redmsg[i];
            greenencryptedMessage[i] = (unsigned char)greenmsg[i];
            blueencryptedMessage[i] = (unsigned char)bluemsg[i];
        }

        // Free memory
        delete[] redmsg;
        delete[] greenmsg;
        delete[] bluemsg;

        // assign the key
        unsigned char key[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};

        unsigned char expandedKey[176];

        KeyExpansion(key, expandedKey);

        int messageLen = strlen((const char *)redencryptedMessage);

        unsigned char * reddecryptedMessage = new unsigned char[messageLen];
        unsigned char * greendecryptedMessage = new unsigned char[messageLen];
        unsigned char * bluedecryptedMessage = new unsigned char[messageLen];

        for (int i = 0; i < messageLen; i += 16) {
            AESDecrypt(redencryptedMessage + i, expandedKey, reddecryptedMessage + i);
            AESDecrypt(greenencryptedMessage + i, expandedKey, greendecryptedMessage + i);
            AESDecrypt(blueencryptedMessage + i, expandedKey, bluedecryptedMessage + i);
        }
        cout<<"DECRYPTED"<<endl;

        Bitmap decImage;
        vector <vector <Pixel>> decBMP;
        Pixel rgbResult;
        decImage.open("D:\\coding\\QT_Projects\\KIJProject\\stroberi.bmp");
        decBMP = decImage.toPixelMatrix();
        vector<string> red = explode(reinterpret_cast<char*>(reddecryptedMessage), ',');
        vector<string> green = explode(reinterpret_cast<char*>(greendecryptedMessage), ',');
        vector<string> blue = explode(reinterpret_cast<char*>(bluedecryptedMessage), ',');
        int dats = 0;
        cout<<reddecryptedMessage<<endl;
         cout<<green.size()<<endl;
          cout<<blue.size()<<endl;
        for(int i =0 ; i<= 31;i++){
            for(int j=0 ; j<=31;j++){
                rgbResult = decBMP[i][j];
//                rgbResult.green = 0;
                rgbResult.red = atoi( red[dats].c_str() );
                rgbResult.blue = atoi( green[dats].c_str() );
                rgbResult.green = atoi( blue[dats].c_str() );
               decBMP[i][j] = rgbResult;
               dats++;
            }
        }
        decImage.fromPixelMatrix(decBMP);
        decImage.save("D:\\coding\\QT_Projects\\KIJProject\\result.bmp");

}




