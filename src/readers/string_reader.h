#pragma once

#include <sstream>
#include "reader.h"

namespace YAYP {

class StringReader : public Reader {
public:
  StringReader(std::string input);
  ~StringReader();
private:
};

}