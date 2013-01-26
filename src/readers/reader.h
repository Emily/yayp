#pragma once

#include <iostream>
#include <deque>
#include <string>

namespace YAYP {

class Reader {
public:
  Reader();
  ~Reader();
  char operator[](int index);
  void pop(int count);

protected:
  std::istream* m_input;
  std::deque<char> m_buffer;
  void fillBuffer(int count);
};

}