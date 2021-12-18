#pragma once

#include <limits.h>
#include <stdbool.h>

#include <mgos-helpers/log.h>

#define BOOL_INVAL (sizeof(bool) > sizeof(unsigned char) ? UINT_MAX : UCHAR_MAX)

#define JSON_OUT_BUFA(len)                             \
  ({                                                   \
    struct json_out *o = alloca(sizeof(*o));           \
    size_t l = (len);                                  \
    *o = (struct json_out) JSON_OUT_BUF(alloca(l), l); \
    o;                                                 \
  })

#define TRY_JSON_SCANF_OR(extra, _s, _sz, ...)                           \
  ({                                                                     \
    const char *s = _s;                                                  \
    int sz = _sz;                                                        \
    int rc = json_scanf(s, sz, ##__VA_ARGS__);                           \
    if (rc < 0) FNERR_GT("%s(%.*s): %s", "json_scanf", sz, s, "failed"); \
    rc;                                                                  \
  })
