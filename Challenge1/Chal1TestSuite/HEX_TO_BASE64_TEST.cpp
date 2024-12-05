#pragma once
#include "hex_to_bits_1.h"
#include "bit_to_base64_1.h"
#include<string>
#include<vector>
#include <cctype>
#include <stdexcept>
using namespace std;

// Function to check if a string is a valid hexadecimal number and its length is even
bool is_valid_hex(const std::string& hex) {
	// Check if the string length is even
	if (hex.size() % 2 != 0) {
		return false;  // Length is odd, so not a valid hex string
	}

	// Check if each character is a valid hex digit
	for (char c : hex) {
		if (!std::isxdigit(c)) {
			return false;  // Invalid character for hex
		}
	}

	return true;  // String is a valid hex string
}


std::string Challenge_Problem_1_TESTS(const std::string& hex) {
	
	// Validate the hex string and throw an exception if it's invalid
	if (!is_valid_hex(hex)) {
		return "Invalid hexadecimal string.";
	}

	// Convert hex string to a vector of unsigned chars
	std::vector<unsigned char> hex_bytes;
	hex_bytes.reserve(hex.size());

	for (char c : hex) {
		hex_bytes.push_back(c);
	}

	// Convert hex_bytes to its bit representation
	std::vector<unsigned char> bits = hex_to_bits_1(hex_bytes);

	// Convert bits to base64
	std::string base64_check = base64_encode(bits);

	return base64_check;
}