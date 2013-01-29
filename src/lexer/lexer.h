#pragma once

#include <queue>
#include <stack>

#include "tokens/tokens.h"
#include "../readers/reader.h"
#include "position.h"
#include "simple_key.h"

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
  std::stack<SimpleKey> m_potential_simple_keys;
  std::stack<Position> m_positions;

  Position m_position;

  void getMoreTokens();
  void scanToNextToken();
  void eatWhitespace();
  void eatComment();
  void eatLineBreak();

  int checkForDirective();
  int checkForEndOfStream();
  int checkForPlainScalar();
  int isLineBreakAt(int index);
};

}