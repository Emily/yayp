#pragma once

#include "token.h"

namespace YAYP {
namespace Tokens {

class Alias : public Token {
public:
  Alias() : Token(Type::Alias) {};
private:
};

}
}