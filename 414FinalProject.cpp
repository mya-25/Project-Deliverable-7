#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <cctype>
#include <iomanip>
#include <cstdlib>

std::vector<std::string> readFileLines(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open()) {
		throw std::runtime_error("Could not open file.");
	}

	std::vector<std::string> lines;
	std::string line;
	while (std::getline(file, line)) {
		lines.push_back(line);
	}
	return lines;
}

std::vector<unsigned char> hexDecode(const std::string& hexStr) {
	std::vector<unsigned char> result;
	for (size_t i = 0; i < hexStr.length(); i += 2) {
		std::string byteString = hexStr.substr(i, 2);
		unsigned char byte = static_cast<unsigned char>(strtol(byteString.c_str(), nullptr, 16));
		result.push_back(byte);
	}
	return result;
}

std::vector<unsigned char> singleByteXOR(const std::vector<unsigned char>& cipher, unsigned char key) {
	std::vector<unsigned char> result;
	result.reserve(cipher.size());

	for (unsigned char c : cipher) {
		result.push_back(c ^ key);
	}
	return result;
}

double calculateScore(const std::vector<unsigned char>& decrypted) {
	double score = 0.0;
	for (unsigned char c : decrypted) {
		if (std::isalpha(c))
			score += 2;
		else if (c == ' ')
			score += 5;
		else if (std::ispunct(c) || std::isdigit(c))
			score += 0.5;
		else if (c >= 128)
			score -= 5;
	}
	return score;
}

std::string findSingleCharacterXOR(const std::vector<std::string>& lines) {
	double bestScore = 0.0;
	std::string bestDecryptedMessage;
	unsigned char bestKey = 0;
	std::string bestHexString;

	for (const std::string& line : lines) {
		std::vector<unsigned char> decoded = hexDecode(line);
		for (int k = 0; k < 256; ++k) {
			unsigned char key = static_cast<unsigned char>(k);
			std::vector<unsigned char> decrypted = singleByteXOR(decoded, key);

			double score = calculateScore(decrypted);

			if (score > bestScore) {
				bestScore = score;
				bestKey = key;
				bestDecryptedMessage = std::string(decrypted.begin(), decrypted.end());
				bestHexString = line;
			}
		}
	}

	std::cout << "Decrypted message: " << bestDecryptedMessage << std::endl;
	std::cout << "Original hex string: " << bestHexString << std::endl << std::endl;
	std::cout << "XOR key: " << static_cast<int>(bestKey) << std::endl;

	return bestDecryptedMessage;
}

int main() {
	try {
		std::string filename = "4.txt";
		std::vector<std::string> lines = readFileLines(filename);
		findSingleCharacterXOR(lines);
	}
	catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}