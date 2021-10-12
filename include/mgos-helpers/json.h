#pragma once

#include <limits.h>
#include <stdbool.h>

#include <mgos-helpers/log.h>

#define BOOL_INVAL (sizeof(bool) > sizeof(unsigned char) ? UINT_MAX : UCHAR_MAX)

#define TRY_JSON_SCANF_OR(extra, _s, _sz, ...)                           \
  ({                                                                     \
    const char *s = _s;                                                  \
    int sz = _sz;                                                        \
    int rc = json_scanf(s, sz, ##__VA_ARGS__);                           \
    if (rc < 0) FNERR_GT("%s(%.*s): %s", "json_scanf", sz, s, "failed"); \
    rc;                                                                  \
  })
