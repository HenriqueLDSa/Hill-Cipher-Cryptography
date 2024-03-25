
```
# Hill Cipher Encryption Tool

This repository contains a simple C program for encrypting text using the Hill cipher algorithm. The Hill cipher is a polygraphic substitution cipher based on linear algebra, particularly matrix multiplication. This tool reads a plaintext file and a key file to produce an encrypted ciphertext.

## Features

- **Key File Processing:** Reads the encryption key from a file specified by the user. The key file should start with an integer representing the size of the key matrix, followed by the matrix elements.
- **Plaintext File Processing:** Processes a plaintext file by removing non-alphabetic characters, converting uppercase letters to lowercase, and appending 'x' to the end of the text to match the key matrix size.
- **Encryption:** Uses the Hill cipher algorithm for encryption, converting the processed plaintext into a numerical format, multiplying it by the key matrix, and then converting the numerical result back into text to form the ciphertext.

## Requirements

- A C compiler (e.g., GCC, Clang) to compile the source code.
- Two input files:
  - A key file (`k2.txt`), which includes the size of the key matrix followed by the matrix elements.
  - A plaintext file (`p2.txt`) containing the text to be encrypted.

## Compilation and Execution

To compile and run the program, use the following commands:

```bash
gcc main.c -o hillcipher
./hillcipher
```

Ensure both `k2.txt` and `p2.txt` are present in the same directory as the executable, or adjust the file paths in the source code accordingly.

## Output

The program will display the processed plaintext and the resulting ciphertext in the console.

**Example Output:**

```
Plaintext:
hellox

Ciphertext:
aefgzl
```
