#include "detector.h"

#include <cstdio>

using namespace YAYP::ReaderUtilities::Unicode;

// determine encoding based on
// http://www.yaml.org/spec/1.2/spec.html#id2771184
Encoding Detector::getEncoding(std::istream& input) {
  unsigned char* leadingBytes = new unsigned char[4];
  memset(leadingBytes, 0, 4);
  input.read((char*)leadingBytes, 4);

  Encoding encoding;

  encoding = checkForExplicitBOM(leadingBytes);

  if (encoding == UNKNOWN) {
    encoding = inferEncoding(leadingBytes);
  }

  delete[] leadingBytes;

  return encoding;
}

Encoding Detector::checkForExplicitBOM(unsigned char bytes[]) {
  Encoding encoding = UNKNOWN;

  if (!std::memcmp(bytes, "\x00\x00\xFE\xFF", 4)) {
    encoding = UTF32BE;
  } else if (!std::memcmp(bytes, "\xFF\xFE\x00\x00", 4)) {
    encoding = UTF32LE;
  } else if (!std::memcmp(bytes, "\xFE\xFF", 2)) {
    encoding = UTF16BE;
  } else if (!std::memcmp(bytes, "\xFF\xFE", 2)) {
    encoding = UTF16LE;
  } else if (!std::memcmp(bytes, "\xEF\xBB\xBF", 3)) {
    encoding = UTF8;
  }

  return encoding;
}

Encoding Detector::inferEncoding(unsigned char bytes[]) {
  Encoding encoding = UNKNOWN;

  if (!std::memcmp(bytes, "\x00\x00\x00", 3)) {
    encoding = UTF32BE;
  } else if (!std::memcmp(bytes + 1, "\x00\x00\x00", 3)) {
    encoding = UTF32LE;
  } else if (!std::memcmp(bytes, "\x00", 1)) {
    encoding = UTF16BE;
  } else if (!std::memcmp(bytes + 1, "\x00", 1)) {
    encoding = UTF16LE;
  } else {
    encoding = UTF8;
  }

  return encoding;
}