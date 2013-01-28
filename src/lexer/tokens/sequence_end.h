#pragma once

#include "token.h"

namespace YAYP {
namespace Tokens {

class SequenceEnd : public Token {
public:
  SequenceEnd() : Token(Type::SequenceEnd) {};
private:
};

}
}