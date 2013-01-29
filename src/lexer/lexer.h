#pragma once

#include <queue>
#include <stack>

#include "tokens/tokens.h"
#include "../readers/reader.h"

namespace YAYP {

class Lexer {
public:
  Lexer(Reader* reader);
  ~Lexer();

  Tokens::Token* nextToken();
private:
  enum State {
    IN_STREAM,
    IN_DOCUMENT,
    IN_MAPPING,
    IN_SEQUENCE
  };

  Reader* m_reader;
  std::queue<Tokens::Token*> m_tokens;
  std::queue<State> m_states;

  int m_line;
  int m_column;
  int m_index;

  void getMoreTokens();
  void scanToNextToken();
  void eatWhitespace();
  void eatComment();
  void eatLineBreak();

  int checkForDirective();
  int checkForEndOfStream();
  int isLineBreakAt(int index);
};

}