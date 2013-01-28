#pragma once

#include "token.h"

namespace YAYP {
namespace Tokens {

class Scalar : public Token {
public:
  Scalar() : Token(Type::Scalar) {};
private:
};

}
}