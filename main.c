// Documentation

/*
Name                    : s kushal kumar
student id              : 26012_094
batch id                : 26012B
start Date              : 18/09/2026
end date                : 28/09/2026

Documentation

Project Title : Image Steganography

Project Description:
This project implements image steganography, a technique used to hide
secret information inside an image without noticeably changing its
appearance.

Purpose:
The main.c file controls the overall execution of the project. It
determines whether the user wants to perform encoding or decoding based
on the command-line arguments.

Working:
1. The program receives command-line arguments through argc and argv.
2. The check_operation_type() function checks whether the user selected
   encoding (-e) or decoding (-d).
3. For encoding, the program validates the required arguments and calls
   do_encoding().
4. For decoding, the program validates the required arguments and calls
   do_decoding().
5. If an invalid operation is provided, an error message is displayed.

Steganography:
In this project, secret data is hidden inside a BMP image during
encoding. The hidden data is later extracted from the encoded image
during decoding.

The main.c file does not perform the actual LSB steganography operation.
It controls the encoding and decoding processes by calling the
corresponding functions.

Functions Used:
main()
Controls the complete execution of the program.

check_operation_type()
Checks whether the user selected encoding or decoding.

read_and_validate_encode_args()
Validates the arguments required for encoding.

do_encoding()
Performs the complete encoding process.

read_and_validate_decode_args()
Validates the arguments required for decoding.

do_decoding()
Performs the complete decoding process.

Command Line Format:

Encoding():
./a.out -e source.bmp secret.txt output.bmp

Decoding():
./a.out -d output.bmp decoded.txt
*/

#include <stdio.h>
#include "encode.h"
#include "types.h"
#include "decode.h"
#include <string.h>

OperationType check_operation_type(char *);


int main(int argc, char *argv[])
{ 
    if(argc < 1)
    {
        printf("Insufficient arguments\n");
        return e_failure;
    }
    if(check_operation_type(argv[1]) == e_encode)
    {
        if(argc < 4)
        {
           printf("Insufficient arguments for encoding\n");
           return e_failure;
        }
        printf("encoding is started\n");

        EncodeInfo encInfo;

        // Validate the command-line arguments required for encoding
        if(read_and_validate_encode_args(argv, &encInfo) == e_success)
        {
            printf("encoding is doing:");

            // Perform the complete encoding process
            if(do_encoding(&encInfo) == e_success)
            {
                printf("encoding is done sucessfully\n");
            }
            else
                printf("encoding is not sucessfully done\n");
        }
        else
            printf("encodinding is failure\n");
    }
    else if(check_operation_type(argv[1]) == e_decode)
    {
        if(argc < 3)
        {
           printf("Insufficient arguments for decoding\n");
           return e_failure;
        }
        printf("decoding is started\n");

        DecodeInfo decInfo;

        // Validate the command-line arguments required for decoding
        if(read_and_validate_decode_args(argv, &decInfo) == e_success)
        {
            printf("decoding is going on:");

            // Perform the complete decoding process
            if(do_decoding(&decInfo) == e_success)
            {
                printf("decoding is done sucessfully\n");
            }
            else
                printf("decoding is not sucessfully done\n");
        }
        else
            printf("decoding files are not correct\n");
    }
    else
        printf("given input of doing encoding and decoding is wrong\n");
    return 0;
}

OperationType check_operation_type(char *symbol)
{
    // Check whether the command-line option is for encoding
    if(strcmp(symbol, "-e") == 0)
        return e_encode;

    // Check whether the command-line option is for decoding
    else if(strcmp(symbol, "-d") == 0)
        return e_decode;

    // Return unsupported when an invalid option is given
    return e_unsupported;
}