#include "lexer.h"

using namespace YAYP;

Lexer::Lexer(Reader* reader) {
  m_reader = reader;
  m_tokens.push(new Tokens::StreamStart());
}

Lexer::~Lexer() {

}

Tokens::Token* Lexer::nextToken() {
  Tokens::Token* token;

  if (m_tokens.size() == 0) {
    getMoreTokens();
  }

  if (m_tokens.size() > 0) {
    token = m_tokens.front();
    m_tokens.pop();
  } else {
    token = new Tokens::ErrorToken();
  }

  return token;
}

void Lexer::getMoreTokens() {
  eatWhiteSpace();
}

//we're counting comments as whitespace
void Lexer::eatWhiteSpace() {
  int count = 0;

  while(true) {
    //whitespace
    while ((*m_reader)[0] == ' ') {
      m_column += 1;
      m_index += 1;
      m_reader->pop(1);
    }

    //comment
    if ((*m_reader)[0] == '#') {
      while (!isLineBreakAt(0)) {
        m_column += 1;
        m_index += 1;
        m_reader->pop(1);
      }
    }

    if (isLineBreakAt(0)) {
      if ((*m_reader)[0] == '\r' || (*m_reader)[1] == '\n') {
        m_reader->pop(2);
      } else {
        m_reader->pop(1);
      }

      m_line += 1;
      m_column = 0;
      m_index += 1;
    } else {
      break;
    }
  }
}

int Lexer::isLineBreakAt(int index) {
  if ((*m_reader)[0] == '\n' || (*m_reader)[0] == '\r') {
    return true;
  }

  return false;
}