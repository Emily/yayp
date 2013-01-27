#include "utf8_decoder.h"

using namespace YAYP::ReaderUtilities::Unicode;

int UTF8Decoder::getNextValue() {
  if (m_input->good()) {
    unsigned char b1 = m_input->get();

    char width = (b1 & 0x80) == 0x00 ? 1 :
                 (b1 & 0xE0) == 0xC0 ? 2 :
                 (b1 & 0xF0) == 0xE0 ? 3 :
                 (b1 & 0xF8) == 0xF0 ? 4 : 0;

    unsigned int value = width == 1 ? b1 & 0x7F :
                         width == 2 ? b1 & 0x1F :
                         width == 3 ? b1 & 0x0F :
                         width == 4 ? b1 & 0x07 : 0;

    if (width) {
      for (int i = 1; i < width; i++) {
        if (m_input->good()) {
          unsigned char b = m_input->get();

          if ((b & 0xC0 )== 0x80) {
            value = (value << 6) + (b & 0x3F);
          } else {
            return -1;
          }
        } else {
          return -1;
        }
      }

      return value;
    }
  }

  return -1;
}