#include "pch.h"
#include"C:\Users\wpcha\source\repos\Challenge1GTest\Chal1TestSuite\HEX_TO_BASE64_TEST.cpp"
#include"C:\Users\wpcha\source\repos\Challenge1GTest\Chal1TestSuite\hex_to_bits_1.cpp"
#include"C:\Users\wpcha\source\repos\Challenge1GTest\Chal1TestSuite\bit_to_base64_1.cpp"

//expected TRUE
static TEST(Small_Values, Test) {
  EXPECT_EQ("XQ==", Challenge_Problem_1_TESTS("5d"));
  EXPECT_TRUE(true);
}
static TEST(Large_Values, Test) {
	EXPECT_EQ("86Gyw9Tl9niQq83vEjRWeJCrze8SNFZ4kKvN75h2VDIQq83vmHZUMhCrze+YdlQyEKvN75h2VDIQq83vmHZUMg==", Challenge_Problem_1_TESTS("f3a1b2c3d4e5f67890abcdef1234567890abcdef1234567890abcdef9876543210abcdef9876543210abcdef9876543210abcdef9876543210abcdef98765432"));
	EXPECT_TRUE(true);
}
static TEST(Empty, Test) {
	EXPECT_EQ("", Challenge_Problem_1_TESTS(""));
	EXPECT_TRUE(true);
}

static TEST(One_Padding, Test) {
	EXPECT_EQ("TWE=", Challenge_Problem_1_TESTS("4D61"));
	EXPECT_TRUE(true);
}

static TEST(Non_Ascii, Test) {
	EXPECT_EQ("44K544GP44KN44GP44Gr44KM", Challenge_Problem_1_TESTS("e382b9e3818fe3828de3818fe381abe3828c"));
	EXPECT_TRUE(true);
}

static TEST(Invalid, Test) {
	EXPECT_EQ("Invalid hexadecimal string.", Challenge_Problem_1_TESTS("e3a"));
	EXPECT_TRUE(true);
}

