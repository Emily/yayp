#pragma once

#include <queue>

#include "tokens/tokens.h"
#include "../readers/reader.h"

namespace YAYP {

class Lexer {
public:
  Lexer(Reader* reader);
  ~Lexer();

  Tokens::Token* nextToken();
private:
  Reader* m_reader;
  std::queue<Tokens::Token*> m_tokens;

  int m_line;
  int m_column;
  int m_index;

  void getMoreTokens();
  void scanToNextToken();
  void eatWhitespace();
  void eatComment();
  bool eatLineBreak();

  int isLineBreakAt(int index);
};

}