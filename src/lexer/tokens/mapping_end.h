#pragma once

#include "token.h"

namespace YAYP {
namespace Tokens {

class MappingEnd : public Token {
public:
  MappingEnd() : Token(Type::MappingEnd) {};
private:
};

}
}