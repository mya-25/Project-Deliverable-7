// Theo T Rodrigues
#include <gtest/gtest.h>
#include "ecb_detector.h"  
#include <vector>
#include <string>

// Test hex_to_bytes function
TEST(HexToBytesTest, ValidHexInput) {
    std::string hex = "4a6f686e";
    std::vector<uint8_t> expected = {0x4a, 0x6f, 0x68, 0x6e};
    EXPECT_EQ(hex_to_bytes(hex), expected);
}

TEST(HexToBytesTest, EmptyHexInput) {
    std::string hex = "";
    std::vector<uint8_t> expected = {};
    EXPECT_EQ(hex_to_bytes(hex), expected);
}

TEST(HexToBytesTest, InvalidHexInput) {
    std::string hex = "4G";
    EXPECT_THROW(hex_to_bytes(hex), std::invalid_argument);
}

// Test has_repeating_blocks function
TEST(HasRepeatingBlocksTest, RepeatingBlocksDetected) {
    std::vector<uint8_t> ciphertext = {0x00, 0x01, 0x02, 0x03, 0x00, 0x01, 0x02, 0x03};
    EXPECT_TRUE(has_repeating_blocks(ciphertext, 4));
}

TEST(HasRepeatingBlocksTest, NoRepeatingBlocks) {
    std::vector<uint8_t> ciphertext = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07};
    EXPECT_FALSE(has_repeating_blocks(ciphertext, 4));
}

TEST(HasRepeatingBlocksTest, EmptyCiphertext) {
    std::vector<uint8_t> ciphertext = {};
    EXPECT_FALSE(has_repeating_blocks(ciphertext, 16));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}