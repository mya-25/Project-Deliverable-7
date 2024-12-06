//
//  main.cpp
//  Implement repeating-key XOR
//
//  Created by mya smith on 11/8/24.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cassert>

using namespace std;

// Function to perform repeated-key XOR encryption
vector<unsigned char> repeated_key_xor(const vector<unsigned char>& plain_text, const vector<unsigned char>& key) {
    vector<unsigned char> encoded; //vector that stores encoded results
    size_t len_key = key.size(); //get length of the key
    
    //loops through each byte of plaintext
    for (size_t i = 0; i < plain_text.size(); ++i) {
        encoded.push_back(plain_text[i] ^ key[i % len_key]);
    }
    //returns XORed results
    return encoded;
}

// Function to convert byte array to hexadecimal string
string to_hex(const vector<unsigned char>& data) {
    ostringstream oss; //creates string stream for the hex string
    //loops through each byte of data in the vector
    for (auto byte : data) {
        //convert each byte to hex and append it to the stream
        //"hex" prints numbers in hexadecimal format, setw(2) so that each byte is represented by 2 numbers, setfill(0) for single digit bytes, and static_cast to convert byte to integer
        oss << hex << setw(2) << setfill('0') << static_cast<int>(byte);
    }
    return oss.str(); //returns hex string
}

// Function to convert hex string back to byte array (to support decryption)
vector<unsigned char> from_hex(const string& hex_str) {
    vector<unsigned char> data;
    for (size_t i = 0; i < hex_str.length(); i += 2) {
        string byte_str = hex_str.substr(i, 2);
        unsigned char byte = static_cast<unsigned char>(stoi(byte_str, nullptr, 16));
        data.push_back(byte);
    }
    return data;
}

//my test for an empty string
void test_empty_string() {
    vector<unsigned char> plain_text = {};
    vector<unsigned char> key = {'K', 'E', 'Y'};

    vector<unsigned char> encrypted = repeated_key_xor(plain_text, key);
    assert(encrypted.empty()); // The encrypted result should also be empty

    cout << "Empty string test passed!" << endl;
}

// Test: Decryption (encryption followed by decryption should return the original text)
void test_decryption() {
    vector<unsigned char> plain_text = {'H', 'e', 'l', 'l', 'o'};
    vector<unsigned char> key = {'K', 'E', 'Y'};

    vector<unsigned char> encrypted = repeated_key_xor(plain_text, key);
    string encrypted_hex = to_hex(encrypted); // Convert encrypted text to hex string
    vector<unsigned char> decrypted = repeated_key_xor(from_hex(encrypted_hex), key); // Decrypt using the same key

    // Check if decrypted data matches original plaintext
    for (size_t i = 0; i < plain_text.size(); ++i) {
        assert(decrypted[i] == plain_text[i]);
    }

    cout << "Decryption test passed!" << endl;
}
//main function
int main() {
    //string test from crypto challenge website
    string plain_text = "Burning 'em, if you ain't quick and nimble\nI go crazy when I hear a cymbal";
    //using ICE as the key
    string key = "ICE";
    
    // Convert plain_text and key to byte arrays
    vector<unsigned char> plain_text_bytes(plain_text.begin(), plain_text.end());
    vector<unsigned char> key_bytes(key.begin(), key.end());
    
    // Perform XOR encryption using repeated_key_xor function
    vector<unsigned char> encrypted = repeated_key_xor(plain_text_bytes, key_bytes);
    
    // Print results
    cout << "Plain text: " << plain_text << endl;
    cout << "Encrypted as: " << to_hex(encrypted) << endl;
    
    test_empty_string();
    test_decryption();
    return 0;
}

