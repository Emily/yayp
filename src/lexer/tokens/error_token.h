#pragma once

#include "token.h"

namespace YAYP {
namespace Tokens {

class ErrorToken : public Token {
public:
  ErrorToken() : Token(Type::ErrorToken) {};
private:
};

}
}