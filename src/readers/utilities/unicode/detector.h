#pragma once

#include <iostream>
#include <cstring>

namespace YAYP {
namespace ReaderUtilities {
namespace Unicode {

enum Encoding {
  UNKNOWN,
  UTF8,
  UTF16LE,
  UTF16BE,
  UTF32LE,
  UTF32BE
};

class Detector {
public:
  Encoding getEncoding(std::istream& input);
private:
  Encoding checkForExplicitBOM(unsigned char bytes[]);
  Encoding inferEncoding(unsigned char bytes[]);
};

}
}
}