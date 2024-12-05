#pragma once
#include "hex_to_bits_1.h"
#include <iostream>
#include <vector>
#include <string>
#include <bitset>


std::string bit_to_base64_1(std::vector<unsigned char> bits)
{
    int decimal = 0;

    const std::string BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    std::string base64_Result;
    
    for (long unsigned int i = 0; i < bits.size(); i = i + 6)
    {
        if ((i + 5) < bits.size())
            decimal = (bits[i + 5] - '0');

        if ((i + 4) < bits.size())
            decimal = decimal + ((bits[i + 4] - '0') * 2);

        if ((i + 3) < bits.size())
            decimal = decimal + ((bits[i + 3] - '0') * 4);

        if ((i + 2) < bits.size())
            decimal = decimal + ((bits[i + 2] - '0') * 8);

        if ((i + 1) < bits.size())
            decimal = decimal + ((bits[i + 1] - '0') * 16);

        if ((i) < bits.size())
            decimal = decimal + ((bits[i] - '0') * 32);

        base64_Result.push_back(BASE64[decimal]);
        decimal = 0;
    }


    return base64_Result;

}
std::string bit_to_base64_(std::vector<unsigned char> bits)
{
    int decimal = 0;
    const std::string BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string base64_Result;

    // Ensure that the number of bits is a multiple of 6
    int padding_needed = 0;
    if (bits.size() % 6 != 0)
    {
        padding_needed = (6 - bits.size() % 6) % 6;
        // Add padding bits (0s) to the end of the input if needed
        bits.insert(bits.end(), padding_needed, 0);
    }

    // Process the bits in chunks of 6
    for (size_t i = 0; i < bits.size(); i += 6)
    {
        decimal = 0;

        // Convert 6 bits to decimal
        for (int j = 0; j < 6; ++j)
        {
            if (i + j <= bits.size())
            {
                // Ensure each bit is 0 or 1
                if (bits[i + j] > 1)
                {
                    throw std::invalid_argument("Invalid bit value in input vector.");
                }
                decimal += (bits[i + j] << (5 - j)); // Shift the bits into the correct place
            }
        }

        // Check if decimal is within range
        if (decimal >= 0 && decimal < 64)
        {
            // Add the corresponding base64 character
            base64_Result.push_back(BASE64[decimal]);
        }
        else
        {
            throw std::out_of_range("Decimal value out of Base64 character range.");
        }
    }

    // Add padding if necessary
    if (padding_needed > 0)
    {
        base64_Result.append(padding_needed / 2, '='); // Add the correct number of '=' padding characters
    }

    return base64_Result;
}

//function to convert a vector<unsigned char> into a string of base64
std::string base64_encode(const std::vector<unsigned char>& bits) {
    // Base64 Alphabet
    std::string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

    // Convert bits to bytes
    std::vector<unsigned char> byte_data;
    for (size_t i = 0; i < bits.size(); i += 8) {
        unsigned char byte = 0;
        for (size_t j = 0; j < 8 && (i + j) < bits.size(); ++j) {
            byte |= (bits[i + j] - '0') << (7 - j); // Convert from char '0'/'1' to 0/1
        }
        byte_data.push_back(byte);
    }

    // Base64 encoding
    std::string base64_result = "";
    int val = 0, valb = -6;
    for (unsigned char c : byte_data) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            base64_result.push_back(base64_chars[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }

    // Add padding if needed
    if (valb > -6) {
        base64_result.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);
    }
    while (base64_result.size() % 4) {
        base64_result.push_back('=');
    }

    return base64_result;
}