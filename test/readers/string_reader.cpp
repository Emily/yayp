#include "gtest/gtest.h"
#include "readers/string_reader.h"

namespace StringReaderTest {

std::string test_string("abcdefghijklmnopqrstuvwxyz");

TEST(StringReader, CharacterAfterEOS) {
  std::string str(" ");
  YAYP::StringReader reader(str);
  EXPECT_EQ(reader[1], -1);
}

TEST(StringReader, LoadsString) {
  YAYP::StringReader reader(test_string);
  EXPECT_EQ(reader[0], 'a');
}

TEST(StringReader, Access) {
  YAYP::StringReader reader(test_string);
  EXPECT_EQ(reader[0], 'a');
  EXPECT_EQ(reader[2], 'c');
  EXPECT_EQ(reader[1], 'b');
  reader.pop(2);
  EXPECT_EQ(reader[0], 'c');
}

TEST(StringReader, PopBeforeAccess) {
  YAYP::StringReader reader(test_string);
  reader.pop(2);
  EXPECT_EQ(reader[0], 'c');
}

}