#include "string_reader.h"

using namespace YAYP;

StringReader::StringReader(std::string input) {
  m_input = new std::istringstream(input, std::istringstream::binary);
}

StringReader::~StringReader() {
  delete ((std::istringstream*) m_input);
}