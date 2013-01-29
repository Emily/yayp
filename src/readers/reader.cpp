#include "reader.h"

using namespace YAYP;
using namespace YAYP::ReaderUtilities;

Reader::Reader() {
  m_decoder = 0;
  m_index = 0;
}

Reader::~Reader() {
  if (m_decoder) {
    delete m_decoder;
  }
}

int Reader::operator[](int index) {
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

  m_index += count;
}

void Reader::fillBuffer(int count) {
  for (int i = 0; i < count; i++) {
    m_buffer.push_back(m_decoder->getNextValue());
  }
}

void Reader::setupDecoder() {
  Unicode::Detector detector;
  Unicode::Encoding encoding = detector.getEncoding(*m_input);

  switch(encoding) {
    default:
      m_decoder = new Unicode::UTF8Decoder(m_input);
  }
}