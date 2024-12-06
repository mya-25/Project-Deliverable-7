// Detect AES in ECB mode

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>
#include <sstream>

using namespace std;

// Convert a hexadecimal string to a vector of bytes
vector<uint8_t> hex_to_bytes(const string &hex) {
    vector<uint8_t> bytes;
    for (size_t i = 0; i < hex.length(); i += 2) {
        string byteString = hex.substr(i, 2);
        uint8_t byte = (uint8_t) strtol(byteString.c_str(), nullptr, 16);
        bytes.push_back(byte);
    }
    return bytes;
}

// Check if there is any repeating 16-byte blocks in the ciphertext
bool has_repeating_blocks(const std::vector<uint8_t> &ciphertext, size_t block_size = 16) {
    unordered_set<string> blocks;
    for (size_t i = 0; i < ciphertext.size(); i += block_size) {
        string block(ciphertext.begin() + i, ciphertext.begin() + i + block_size);
        if (blocks.find(block) != blocks.end()) {
            return true; // Repeating block found
        }
        blocks.insert(block);
    }
    return false;
}

int main() {
    ifstream file("8.txt");
    if (!file.is_open()) {
        cerr << "Error opening file!" <<endl;
        return 1;
    }

    string line;
    int line_number = 0;
    while (getline(file, line)) {
        line_number++;
        vector<uint8_t> ciphertext = hex_to_bytes(line);
        
        // Check if the ciphertext has repeating 16-byte blocks
        if (has_repeating_blocks(ciphertext)) {
            cout << "ECB detected on line: " << line_number << endl;
        }
    }

    file.close();
    return 0;
}