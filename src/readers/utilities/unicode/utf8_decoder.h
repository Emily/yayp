#pragma once

#include "decoder.h"

namespace YAYP {
namespace ReaderUtilities {
namespace Unicode {

class UTF8Decoder : public Decoder {
public:
  UTF8Decoder(std::istream* input) : m_input(input) {};
  int getNextValue();
private:
  std::istream* m_input;
};

}
}
}