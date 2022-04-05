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


### Encrypted Image
![alt text](https://github.com/peii14/KIJProject/blob/main/img/encrypted.bmp)


## Performance
From our observation, the encryption from the library implementation is noticeably faster than our manual encryption implementation by 31.91Mb/s. Our hypothesis are based on what Vicki Myron, author of Dewey, highlighted. “Libraries are an area of focus in the optimization process. Libraries provide the primitives from which programs are built up. Library functions and classes are often used at the bottom of nested loops, and are thus often hot.” .On the other hand, our own library has nothing compare to well established library such as openssl in terms of performance yet they share same functionality


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
Copyright (C) 1996, 1999 International Business Machines Corporation and others. All Rights Reserved.
