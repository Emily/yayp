#pragma once

#include "token.h"

namespace YAYP {
namespace Tokens {

class DocumentStart : public Token {
public:
  DocumentStart() : Token(Type::DocumentStart) {};
private:
};

}
}