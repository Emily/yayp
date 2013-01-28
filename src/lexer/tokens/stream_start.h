#pragma once

#include "token.h"

namespace YAYP {
namespace Tokens {

class StreamStart : public Token {
public:
  StreamStart() : Token(Type::StreamStart) {};
private:
};

}
}