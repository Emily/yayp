#include "file_reader.h"

using namespace YAYP;

FileReader::FileReader(std::string filename) {
  m_input = new std::ifstream();
  ((std::ifstream*) m_input)->open(filename.c_str(), std::ifstream::binary);
}

FileReader::~FileReader() {
  ((std::ifstream*) m_input)->close();
  delete ((std::ifstream*) m_input);
}