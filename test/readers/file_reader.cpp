#include "gtest/gtest.h"
#include "readers/file_reader.h"

TEST(FileReader, CharacterAfterEOF) {
  YAYP::FileReader reader("test/data/reader_test_file2");
  EXPECT_EQ(reader[1], -1);
}

TEST(FileReader, LoadsFile) {
  YAYP::FileReader reader("test/data/reader_test_file1");
  EXPECT_EQ(reader[0], 'a');
}

TEST(FileReader, Access) {
  YAYP::FileReader reader("test/data/reader_test_file1");
  EXPECT_EQ(reader[0], 'a');
  EXPECT_EQ(reader[2], 'c');
  EXPECT_EQ(reader[1], 'b');
  reader.pop(2);
  EXPECT_EQ(reader[0], 'c');
}

TEST(FileReader, PopBeforeAccess) {
  YAYP::FileReader reader("test/data/reader_test_file1");
  reader.pop(2);
  EXPECT_EQ(reader[0], 'c');
}