# Determine endianess at compile time
Add <Endian.h> to your project and the endianess will be available in macro BYTE_ORDER. It will either be BIG_ENDIAN or LITTLE_ENDIAN

```c
#include <Arduino.h>
#include <endian.h>

void setup()
{
  Serial.begin(115200);
  Serial.println("booting..");

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
```

## Endianess
Chipset | Platform | Endianess 
--- | --- | ---
ATMega4809 | Nano Every | Little
ESP32 | Adafruit ESP32 Feather | Little
