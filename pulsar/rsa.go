package main

 import (
	"hash"
	 "crypto/sha1"
	 "crypto/rand"
	 "crypto/rsa"
	 "crypto/x509"
	 "fmt"
	 "io/ioutil"
)
 
 func RSACreateKey() {
	 
	 bits := 2048
	 privateKey, _ := rsa.GenerateKey(rand.Reader, bits)

	 bytePrivateKey := x509.MarshalPKCS1PrivateKey(privateKey)
	 ioutil.WriteFile("private.key", bytePrivateKey, 0)
	 bytePublicKey := x509.MarshalPKCS1PublicKey(&privateKey.PublicKey)
	 ioutil.WriteFile("public.key", bytePublicKey, 0)
 }

 // Decode
 func RSALoadPrivateKey(key_file *string) *rsa.PrivateKey{
	read, err :=ioutil.ReadFile(*key_file)
	if err != nil{
		println ("private.key doesn't exists")
		return nil
	}
	privateKey,err := x509.ParsePKCS1PrivateKey(read)
	if err != nil{
		println ("fail parse to private key")
		return nil
	}
	return privateKey
 }

 // Encode
 func RSALoadPublicKey(key_file *string) *rsa.PublicKey{
	read, err := ioutil.ReadFile(*key_file)
	if err != nil{
		println ("public.key doesn't exists")
		return nil
	}
	publicKey, err:= x509.ParsePKCS1PublicKey(read)
	if err != nil{
		println ("fail parse to public key")
		return nil
	}
	return publicKey
 }


 func RSAencrypt(publicKey *rsa.PublicKey, messageBytes []byte)( []byte){
	// messageBytes := bytes.NewBufferString(message)
	sh := sha1.New()

	encrypted, err := rsa.EncryptOAEP(sh, rand.Reader, publicKey, messageBytes, nil)
	if err != nil {
		fmt.Printf("EncryptOAEP: %s\n", err)
		return nil
	}

	return encrypted

 }

 func RSADecrypt(privateKey *rsa.PrivateKey, sh hash.Hash, encrypted []byte) []byte{
	decrypted, err := rsa.DecryptOAEP( sh, rand.Reader, privateKey, encrypted, nil)
	if err != nil {
		fmt.Printf("decrypt: %s\n", err)
		return nil
	}

	return decrypted

 }