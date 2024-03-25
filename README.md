# Hill Cipher Cryptography Project

Welcome to the Hill Cipher Cryptography Project repository! This project implements the Hill cipher, a classic cryptography algorithm, using C programming language. It's designed as an educational tool to demonstrate the encryption and decryption process in the field of symmetric key cryptography.

## Project Structure

This repository contains several key components:

- `main.c`: The core C program that implements the Hill cipher algorithm.
- `k0.txt` to `k5.txt`: Key files used by the algorithm for encryption and decryption.
- `p0.txt` to `p5.txt`: Plaintext files that are encrypted using the keys.
- `base1.txt` to `base5.txt`: Base files (possibly for base cases or examples).
- `stu1Output.txt` to `stu5Output.txt`: Output files that contain the results of the encryption process.

## Getting Started

To get started with this project:

1. Clone the repository to your local machine.
2. Ensure you have a C compiler installed (e.g., GCC or Clang).
3. Compile the program using the C compiler:
    ```
    gcc main.c -o hillcipher
    ```
4. Run the program. You may need to adjust the file paths in `main.c` to match the location of the key and plaintext files on your system.

## Usage

The `main.c` program reads a plaintext file and a key file to produce an encrypted ciphertext. Modify the source code to specify the paths to your input files or use the provided examples for testing.
