#pragma once

#include "token.h"

namespace YAYP {
namespace Tokens {

class DocumentEnd : public Token {
public:
  DocumentEnd() : Token(Type::DocumentEnd) {};
private:
};

}
}