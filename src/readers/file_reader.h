#pragma once

#include <fstream>
#include "reader.h"

namespace YAYP {

class FileReader : public Reader {
public:
  FileReader(std::string filename);
  ~FileReader();
private:
};

}