#include <string>
#include <iostream>
#include <sstream>

#include "gtest/gtest.h"
#include "readers/utilities/unicode/detector.h"

using namespace YAYP::ReaderUtilities::Unicode;

Encoding encodingHelper(std::string bytes) {
  std::istringstream data(bytes);
  Detector detector;
  return detector.getEncoding(data);
}

TEST(Detector, getEncodingUTF32) {
  Encoding encoding;

  encoding = encodingHelper(std::string("\x00\x00\xFE\xFF", 4));
  EXPECT_EQ(UTF32BE, encoding);

  encoding = encodingHelper(std::string("\x00\x00\x00\x50", 4));
  EXPECT_EQ(UTF32BE, encoding);

  encoding = encodingHelper("\xFF\xFE\x00\x00");
  EXPECT_EQ(UTF32LE, encoding);

  encoding = encodingHelper("\x50\x00\x00\x00");
  EXPECT_EQ(UTF32LE, encoding);
}

TEST(Detector, getEncodingUTF16) {
  Encoding encoding;

  encoding = encodingHelper("\xFE\xFF\x50");
  EXPECT_EQ(UTF16BE, encoding);

  encoding = encodingHelper(std::string("\x00\x50", 2));
  EXPECT_EQ(UTF16BE, encoding);

  encoding = encodingHelper("\xFF\xFE\x50");
  EXPECT_EQ(UTF16LE, encoding);

  encoding = encodingHelper(std::string("\x50\x00\x50", 3));
  EXPECT_EQ(UTF16LE, encoding);
}

TEST(Detector, getEncodingUTF8) {
  Encoding encoding;

  encoding = encodingHelper("\xEF\xBB\xBF");
  EXPECT_EQ(UTF8, encoding);

  encoding = encodingHelper("test");
  EXPECT_EQ(UTF8, encoding);
}