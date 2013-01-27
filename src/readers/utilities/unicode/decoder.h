#pragma once

#include <iostream>

namespace YAYP {
namespace ReaderUtilities {
namespace Unicode {

class Decoder {
public:
  Decoder() {};
  virtual int getNextValue() { return -1; };
};

}
}
}