#pragma once

#include "token.h"

namespace YAYP {
namespace Tokens {

class MappingStart : public Token {
public:
  MappingStart() : Token(Type::MappingStart) {};
private:
};

}
}