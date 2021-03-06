#pragma once

#include <iostream>
#include <deque>
#include <string>

#include "utilities/unicode/unicode.h"

namespace YAYP {

class Reader {
public:
  Reader();
  ~Reader();
  int operator[](int index);
  void pop(int count);
  int index() { return m_index; };
protected:
  std::istream* m_input;
  std::deque<int> m_buffer;
  int m_index;

  void fillBuffer(int count);
  void setupDecoder();
  YAYP::ReaderUtilities::Unicode::Decoder* m_decoder;
};

}