#pragma once

#include <iostream>

namespace YAYP {
namespace ReaderUtilities {
namespace Unicode {

class Decoder {
public:
  Decoder(std::istream* input) : m_input(input) {};
  virtual int getNextValue();
private:
  std::istream* m_input;
};

}
}
}