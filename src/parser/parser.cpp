#include "parser.h"

using namespace YAYP;

Parser::Parser(std::string filename) {
  reader = new FileReader(filename);
}

Parser::~Parser() {
  delete reader;
}

Node Parser::parse() {
  return Node();
}