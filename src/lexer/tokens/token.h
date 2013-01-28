#pragma once

#include <string>

namespace YAYP {
namespace Tokens {

namespace Type {
  enum Type {
    ErrorToken,
    StreamStart,
    StreamEnd,
    DocumentStart,
    DocumentEnd,
    MappingStart,
    MappingEnd,
    SequenceStart,
    SequenceEnd,
    Scalar,
    Alias
  };
}

class Token {
public:
  Type::Type type() { return m_type; };

  std::string anchor() { return m_anchor; };
  void setAnchor(std::string anchor) { m_anchor = anchor; };
protected:
  Token(Type::Type type) : m_type(type) {};
  Type::Type m_type;

  std::string m_anchor;
};

}
}