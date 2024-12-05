# Project-Deliverable-7
Repeating Key XOR Decryption Utility
Introduction
This utility is a C++ program designed to decrypt data encrypted with a Repeating Key XOR cipher. It uses statistical analysis and English character frequency scoring to recover the most probable decryption key and plaintext.

Features
Base64 Decoding: Processes Base64-encoded input to binary data.
Hamming Distance Calculation: Helps determine potential key sizes by comparing data chunks.
Single-Character XOR Brute Force: Identifies the best single-byte XOR key using English text scoring.
Repeating Key XOR Decryption: Decrypts ciphertext encrypted with a repeating XOR key.
File Reading: Reads Base64-encoded ciphertext from a file.
Repository
This project is hosted on GitHub. You can find it here:

CSC414-Project Repository

Prerequisites
Before running the program, ensure you have:

A C++ compiler such as g++ or clang++.
The encrypted Base64-encoded data file (6.txt) in the program's directory.
Installation and Usage
Step 1: Clone the Repository
bash
Copy code
git clone https://github.com/mya-25/CSC414-Project.git
cd CSC414-Project
Step 2: Compile the Program
Use the following command to compile the program:

bash
Copy code
g++ -o xor_decryptor xor_decryptor.cpp
Step 3: Execute the Program
Run the program and pass the required input file:

bash
Copy code
./xor_decryptor
The program reads the data from 6.txt, processes it, and outputs the decryption key and plaintext.

How It Works
Input File: The program reads a Base64-encoded file containing XOR-encrypted data.
Decode: Converts Base64 data into binary format.
Key Size Identification:
Uses Hamming Distance to estimate probable key sizes.
Normalizes the results to identify the best candidates.
Key Recovery:
Breaks the data into blocks for each key size.
Uses brute force and scoring to determine the best single-byte XOR key for each block.
Decryption:
Combines the recovered key to decrypt the ciphertext.
Scores and selects the best plaintext based on English letter frequencies.
Output: Displays the encryption key and the decrypted message.
Example Output
If the input file is valid, the output will look something like this:

plaintext
Copy code
Key = some_key
Decrypted Text = This is the decrypted message!
Error Handling
File Errors: Reports inability to open or read the file.
Invalid Input: Detects and handles invalid Base64 or mismatched data lengths.
Contributing
Contributions are welcome! To contribute:

Fork the repository.
Make your changes in a separate branch.
Submit a pull request.
License
This project is licensed under the MIT License. See the LICENSE file for details.
