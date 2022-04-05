# AES-KIJ
AAF
## Software Description
In this project, both the openssl library AES Encryption and the manual implementation are using the CBC (Cipher Block Chaining) mode of operation combined with the RSA (Rivest–Shamir–Adleman) algorithm to perform secure data transmission. 
We choose the CBC mode of operation for this project because it is the easiest to implement without compromising too many security issues that we encounter if we use the ECB (Electronic Code Block) mode of operation. The CBC mode provides message dependence for generating ciphertext and makes the system non-deterministic. How the algorithm works are that the current plaintext block is added to the previous ciphertext block, and then the result is encrypted with the key. Decryption is thus the reverse process, which involves decrypting the current ciphertext and then adding the previous ciphertext block to the result.<br/>

## Walkthrough
### Create key pair
![alt text](https://github.com/peii14/KIJProject/blob/main/img/publicPrivate.png)
### Encrypt image without openssl
![alt text](https://github.com/peii14/KIJProject/blob/main/img/encryptNon.png)
### Encrypt image openssl
![alt text](https://github.com/peii14/KIJProject/blob/main/img/encryptOpenssl.png)


### Result


## Test Result

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
Copyright (C) 1996, 1999 International Business Machines Corporation and others. All Rights Reserved.
