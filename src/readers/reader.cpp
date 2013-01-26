#include "reader.h"

using namespace YAYP;

Reader::Reader() {
}

Reader::~Reader() {
}

char Reader::operator[](int index) {
  if ((index + 1) > m_buffer.size()) {
    fillBuffer((index + 1) - m_buffer.size());
  }

  return m_buffer[index];
}

void Reader::pop(int count) {
  if (count > m_buffer.size()) {
    m_input->ignore(count - m_buffer.size());
    count = m_buffer.size();
  }

  for (int i = 0; i < count ; i++) {
    m_buffer.pop_front();
  }
}

void Reader::fillBuffer(int count) {
  for (int i = 0; i < count; i++) {
    if (m_input->good()) {
      m_buffer.push_back(m_input->get());
    }
  }
}