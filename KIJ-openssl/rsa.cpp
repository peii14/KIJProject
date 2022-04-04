
#include "rsa.h"

using namespace std;

RSA *rsa::create_RSA(RSA * keypair, int pem_type, char *file_name) {

    RSA   *rsa = NULL;
    FILE  *fp  = NULL;

    if(pem_type == PUBLIC_KEY_PEM) {

        fp = fopen(file_name, "w");
        PEM_write_RSAPublicKey(fp, keypair);
        fclose(fp);

        fp = fopen(file_name, "rb");
        PEM_read_RSAPublicKey(fp, &rsa, NULL, NULL);
        fclose(fp);

    }
    else if(pem_type == PRIVATE_KEY_PEM) {

        fp = fopen(file_name, "w");
        PEM_write_RSAPrivateKey(fp, keypair, NULL, NULL, NULL, NULL, NULL);
        fclose(fp);

        fp = fopen(file_name, "rb");
        PEM_read_RSAPrivateKey(fp, &rsa, NULL, NULL);
        fclose(fp);

    }

    return rsa;
}

int rsa::public_encrypt(int flen, unsigned char* from, unsigned char* to, RSA* key, int padding) {
    
    int result = RSA_public_encrypt(flen, from, to, key, padding);
    return result;
}

int rsa::private_decrypt(int flen, unsigned char* from, unsigned char* to, RSA* key, int padding) {

    int result = RSA_private_decrypt(flen, from, to, key, padding);
    return result;
}

void rsa::create_encrypted_file(char* encrypted, RSA* key_pair) {

    FILE* encrypted_file = fopen("encrypted_file.bin", "w");
    fwrite(encrypted, sizeof(*encrypted), RSA_size(key_pair), encrypted_file);
    fclose(encrypted_file);
}

RSA *rsa::readCert(string fileName,bool isPublic){
    std::ifstream t(fileName);
    t.seekg(0, std::ios::end);
    size_t size = t.tellg();
    std::string buffer(size, ' ');
    t.seekg(0);
    t.read(&buffer[0], size); 
    if(isPublic){
        RSA * public_key_ = NULL;
        BIO* bo = BIO_new_mem_buf(buffer.c_str(),-1);
        if (bo==NULL){
            throw std::runtime_error("no bio");
        }
        public_key_ = PEM_read_bio_RSAPublicKey(bo, &public_key_, NULL, NULL );
        if(!public_key_)   
        {
            throw std::runtime_error("Failed to create RSA");
        }
        return public_key_;
    }else{
        RSA * private_key_ = NULL;
        BIO* bo = BIO_new_mem_buf(buffer.c_str(),-1);
        if (bo==NULL){
            throw std::runtime_error("no bio");
        }
        private_key_ = PEM_read_bio_RSAPrivateKey(bo, &private_key_, NULL, NULL );
        if(!private_key_)   
        {
            throw std::runtime_error("Failed to create RSA");
        }
        return private_key_;
    }
}

