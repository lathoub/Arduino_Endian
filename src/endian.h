#ifndef BYTE_ORDER

#ifndef BIG_ENDIAN
#define BIG_ENDIAN 4321
#endif
#ifndef LITTLE_ENDIAN
#define LITTLE_ENDIAN 1234
#endif

#define TEST_LITTLE_ENDIAN (((union { unsigned x; unsigned char c; }){1}).c)

#ifdef TEST_LITTLE_ENDIAN
#define BYTE_ORDER LITTLE_ENDIAN
#else
#define BYTE_ORDER BIG_ENDIAN
#endif

#undef TEST_LITTLE_ENDIAN
#endif