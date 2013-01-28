#pragma once

#include "token.h"

namespace YAYP {
namespace Tokens {

class StreamEnd : public Token {
public:
  StreamEnd() : Token(Type::StreamEnd) {};
private:
};

}
}