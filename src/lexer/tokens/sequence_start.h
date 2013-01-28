#pragma once

#include "token.h"

namespace YAYP {
namespace Tokens {

class SequenceStart : public Token {
public:
  SequenceStart() : Token(Type::SequenceStart) {};
private:
};

}
}