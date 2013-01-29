#include "gtest/gtest.h"

#include "readers/string_reader.h"
#include "lexer/lexer.h"

// namespace LexerTest {

TEST(Lexer, StreamStart) {
  std::string test_string("abcdefghijklmnopqrstuvwxyz");
  YAYP::StringReader* reader = new YAYP::StringReader(test_string);
  YAYP::Lexer lexer(reader);

  YAYP::Tokens::Token* token = lexer.nextToken();
  EXPECT_EQ(YAYP::Tokens::Type::StreamStart, token->type());

  delete reader;
  delete token;
}

TEST(Lexer, StreamEnd) {
  std::string test_string(" ");
  YAYP::StringReader* reader = new YAYP::StringReader(test_string);
  YAYP::Lexer lexer(reader);

  YAYP::Tokens::Token* token = lexer.nextToken();
  EXPECT_EQ(YAYP::Tokens::Type::StreamStart, token->type());
  delete token;

  token = lexer.nextToken();
  EXPECT_EQ(YAYP::Tokens::Type::StreamEnd, token->type());

  delete reader;
  delete token;
}

TEST(Lexer, EatWhitespace) {
  std::string test_string("    abc");
  YAYP::StringReader* reader = new YAYP::StringReader(test_string);
  YAYP::Lexer lexer(reader);

  YAYP::Tokens::Token* token = lexer.nextToken();
  delete token;
  token = lexer.nextToken();
  EXPECT_GE(4, reader->index());

  delete reader;
  delete token;
}

TEST(Lexer, EatComments) {
  std::string test_string("#co\nabc");
  YAYP::StringReader* reader = new YAYP::StringReader(test_string);
  YAYP::Lexer lexer(reader);

  YAYP::Tokens::Token* token = lexer.nextToken();
  delete token;
  token = lexer.nextToken();
  EXPECT_GE(4, reader->index());

  delete reader;
  delete token;
}

// TODO: Handle directives properly
TEST(Lexer, EatDirectives) {
  std::string test_string("%YAML 1.2\nabc");
  YAYP::StringReader* reader = new YAYP::StringReader(test_string);
  YAYP::Lexer lexer(reader);

  YAYP::Tokens::Token* token = lexer.nextToken();
  delete token;
  token = lexer.nextToken();
  EXPECT_GE(10, reader->index());

  delete reader;
  delete token;
}

TEST(Lexer, Scalar) {
  std::string test_string("abcdefghijklmnopqrstuvwxyz");
  YAYP::StringReader* reader = new YAYP::StringReader(test_string);
  YAYP::Lexer lexer(reader);

  YAYP::Tokens::Token* token = lexer.nextToken();
  delete token;
  token = lexer.nextToken();
  EXPECT_EQ(YAYP::Tokens::Type::Scalar, token->type());

  delete reader;
  delete token;
}

// }