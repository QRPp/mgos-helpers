#pragma once

#include <stdint.h>
/* ESP32's endian.h fails without stdint.h prior. */
#include <endian.h>

#if BYTE_ORDER != BIG_ENDIAN && BYTE_ORDER != LITTLE_ENDIAN
#error Only big and little endian architectures are supported.
#endif
