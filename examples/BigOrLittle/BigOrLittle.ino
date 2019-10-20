#include <Arduino.h>
#include "endian.h"

int aa(int v) {
  return v + 1;
}

#define bb(x) aa(x)

void setup()
{
  Serial.begin(115200);
  Serial.println("booting..");

  Serial.println(aa(5));
  Serial.println(bb(5));

#ifndef BYTE_ORDER
  Serial.println("BYTE_ORDER not defined");
#else
#if (BYTE_ORDER == LITTLE_ENDIAN)
  Serial.println("Little Endian");
#endif
#if (BYTE_ORDER == BIG_ENDIAN)
  Serial.println("Big Endian");
#endif
#endif

  conversionBuffer g;

  g.buffer[0] = 0x0A;
  g.buffer[1] = 0x0B;
  g.buffer[2] = 0x0C;  
  g.buffer[3] = 0x0D;
  Serial.println(g.value8 , HEX);
  Serial.println(g.value16, HEX);
  Serial.println(g.value32, HEX);
  Serial.println(htobe32(g.value32), HEX);

  // from https://en.wikipedia.org/wiki/Endianness
  uint32_t word = 0x0A0B0C0D; // An unsigned 32-bit integer.
  char *pointer = (char *) &word; // A pointer to the first octet of the word.

  for (int i = 0; i < 4; i++)
  {
    Serial.print("byte[");
    Serial.print(i);
    Serial.print("] = 0x");
    Serial.println((unsigned int) * (pointer + i), HEX);
  }
}

void loop()
{
}
