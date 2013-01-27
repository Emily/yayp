#include <string>
#include <iostream>
#include <sstream>

#include "gtest/gtest.h"
#include "readers/utilities/unicode/utf8_decoder.h"

using namespace YAYP::ReaderUtilities::Unicode;

TEST(UTF8Decoder, getNextValue1b) {
  std::istringstream stream(std::string("abc"));
  UTF8Decoder decoder(&stream);
  EXPECT_EQ('a', decoder.getNextValue());
  EXPECT_EQ('b', decoder.getNextValue());
  EXPECT_EQ('c', decoder.getNextValue());
}

TEST(UTF8Decoder, getNextValue2b) {
  std::istringstream stream(std::string("\xC2\xA5"));
  UTF8Decoder decoder(&stream);
  EXPECT_EQ(165, decoder.getNextValue());
}

TEST(UTF8Decoder, getNextValue3b) {
  std::istringstream stream(std::string("\xE1\xA0\x81"));
  UTF8Decoder decoder(&stream);
  EXPECT_EQ(6145, decoder.getNextValue());
}

TEST(UTF8Decoder, getNextValue4b) {
  std::istringstream stream(std::string("\xf0\x9f\x80\x80"));
  UTF8Decoder decoder(&stream);
  EXPECT_EQ(126976, decoder.getNextValue());
}