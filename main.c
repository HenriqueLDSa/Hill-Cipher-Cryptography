#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *key = fopen("k2.txt", "r");
    FILE *text = fopen("p2.txt", "r");

    int keySize = 0;
    fscanf(key, "%d", &keySize);
    int keyMatrix[keySize][keySize];

    for(int i = 0; i < keySize; i++)
    {
        for(int j = 0; j < keySize; j++)
            fscanf(key, "%d", &keyMatrix[i][j]);
    }

    char plainText[10000];

    for(int i = 0; !feof(text); i++)
    {
        plainText[i] = fgetc(text);
        
        if(plainText[i] >= 97 && plainText[i] <= 122)
            continue;
        else if(plainText[i] >= 65 && plainText[i] <= 90)
            plainText[i]+=32;
        else
            i--;
    }

    // int keySize = 3;
    // int keyMatrix[3][3] = {{1,2,3},
    //                        {4,5,6},
    //                        {7,8,9}
    //                       };

    // char plainText[] = "potato";
    
    printf("\n");
    printf("Plaintext:\n%s", plainText);
    printf("\n\n\n");

    int plainTextToInt[strlen(plainText)];
    int result[strlen(plainText)];
    
    for(int i = 0; i < strlen(plainText); i++)
        plainTextToInt[i] = plainText[i] - 97;

    int plainIntIndex = 0;
    int resultIndex = 0;
    while(resultIndex < strlen(plainText)){
        for(int j = 0; j < keySize; j++)
        {
            int sumOfProds = 0;
            for(int i = 0; i < keySize; i++)
            {
                sumOfProds += (plainTextToInt[plainIntIndex] * keyMatrix[i][j]);
                plainIntIndex++;
            }
            result[resultIndex] = sumOfProds;
            resultIndex++;
            plainIntIndex -= keySize;
        }
        plainIntIndex += keySize;
    }

   for(int i = 0; i < strlen(plainText); i++)
        result[i] %= 26;

    char cipherText[strlen(plainText)];

    for(int i = 0; i < strlen(plainText); i++)
        cipherText[i] = result[i] + 97;

    printf("Ciphertext:\n%s", cipherText);

    return 0;
}

// Read key matrix from file - DONE
// Read plain text from file - DONE
// Remove spaces, numbers, and lowercase any uppercase chars - DONE
// Convert plain text to int - DONE
// Multiply plain text by matrix in groups of 3
// Modulo 26 
// Convert back to letter


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main()
// {
//     FILE *key = fopen("k2.txt", "r");
//     FILE *text = fopen("p2.txt", "r");

//     int keySize = 0;
//     fscanf(key, "%d", &keySize);
//     int keyMatrix[keySize][keySize];

//     for(int i = 0; i < keySize; i++)
//     {
//         for(int j = 0; j < keySize; j++)
//             fscanf(key, "%d", &keyMatrix[i][j]);
//     }

//     char plainText[10000];

//     for(int i = 0; !feof(text); i++)
//     {
//         plainText[i] = fgetc(text);
        
//         if(plainText[i] >= 97 && plainText[i] <= 122)
//             continue;
//         else if(plainText[i] >= 65 && plainText[i] <= 90)
//             plainText[i]+=32;
//         else
//             i--;
//     }
    
//     printf("\n");
//     printf("Plaintext:\n%s", plainText);
//     printf("\n\n\n");

//     int plainTextToInt[strlen(plainText)];
//     int result[strlen(plainText)];
    
//     for(int i = 0; i < strlen(plainText); i++)
//         plainTextToInt[i] = plainText[i] - 97;

//     int plainIntIndex = 0;
//     int resultIndex = 0;
//     while(resultIndex < strlen(plainText)){
//         for(int j = 0; j < keySize; j++)
//         {
//             int sumOfProds = 0;
//             for(int i = 0; i < keySize; i++)
//             {
//                 sumOfProds += (plainTextToInt[plainIntIndex] * keyMatrix[i][j]);
//                 plainIntIndex++;
//             }
//             result[resultIndex] = sumOfProds;
//             resultIndex++;
//             plainIntIndex -= keySize;
//         }
//         plainIntIndex += keySize;
//     }

//    for(int i = 0; i < strlen(plainText); i++)
//         result[i] %= 26;

//     char cipherText[strlen(plainText)];

//     for(int i = 0; i < strlen(plainText); i++)
//         cipherText[i] = result[i];

//     printf("Ciphertext:\n%s", cipherText);

//     return 0;
// }