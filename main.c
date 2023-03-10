#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    //opens the files needed
    FILE *key = fopen("k2.txt", "r");
    FILE *text = fopen("p2.txt", "r");

    //scans the key file and allocates key matrix based on its size
    int keySize = 0;
    fscanf(key, "%d", &keySize);
    int keyMatrix[keySize][keySize];

    //assigns the values of key file into key matrix
    for(int i = 0; i < keySize; i++)
    {
        for(int j = 0; j < keySize; j++)
            fscanf(key, "%d", &keyMatrix[i][j]);
    }

    //defaults max plaintext length to 10000
    char plainText[10000];

    /*
    reads the plaintext from the file
    only characters are added to the string
    uppercase are converted to lowercase
    */
    for(int i = 0; !feof(text); i++)
    {
        plainText[i] = fgetc(text);

        if(plainText[i] == EOF)
            plainText[i] = '\0';
        else if(plainText[i] >= 97 && plainText[i] <= 122)
            continue;
        else if(plainText[i] >= 65 && plainText[i] <= 90)
            plainText[i]+=32;
        else
            i--;        
    }

    //inserts 'x' characters at the end of the string until it's perfectly divisible my key size
    for(int i = strlen(plainText); strlen(plainText) % keySize != 0; i++)
        plainText[i] = 'x';
    
    printf("\n");
    printf("Plaintext:\n%s", plainText);
    printf("\n\n\n");

    //allocates array to convert the string to integer
    //allocates array for multiplication result
    int plainTextToInt[strlen(plainText)];
    int result[strlen(plainText)];
    
    //converts plaintext to integer values
    for(int i = 0; i < strlen(plainText); i++)
        plainTextToInt[i] = plainText[i] - 97;

    //performs the multiplication of plainTextToInt with key matrix
    int plainIntIndex = 0;
    int resultIndex = 0;
    while(resultIndex < strlen(plainText)){
        for(int i = 0; i < keySize; i++)
        {
            int sumOfProds = 0;
            for(int j = 0; j < keySize; j++)
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

    //mods 26 for each result value
    for(int i = 0; i < strlen(plainText); i++)
        result[i] %= 26;

    //allocates ciphertext
    char cipherText[strlen(plainText)];

    //converts the result values to lowercase letters
    for(int i = 0; i < strlen(plainText); i++)
        cipherText[i] = result[i] + 97;

    printf("Ciphertext:\n%s", cipherText);
    printf("\n\n");

    fclose(key);
    fclose(text);

    return 0;
    
}