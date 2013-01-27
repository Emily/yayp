#pragma once

#include <string>
#include "../nodes/nodes.h"
#include "../readers/file_reader.h"

namespace YAYP {

class Parser {
public:
  Parser(std::string filename);
  ~Parser();
  Node parse();
private:
  FileReader* reader;
};

}