#pragma once

#include <errno.h>
#include <string.h>

#include <mgos-helpers/log.h>

#define MALLOC_ERR_FMT "%s(%u): (%d) %s"
#define MALLOC_ERR_ARG(obj) MALLOC_ERR_ARG_SZ(sizeof(*obj))
#define MALLOC_ERR_ARG_SZ(sz) "malloc", (sz), errno, strerror(errno)

#define TRY_MALLOC_OR(extra, obj) TRY_MALLOC_SZ_OR(extra, sizeof(*obj))
#define TRY_MALLOC_SZ_OR(extra, sz)                                    \
  ({                                                                   \
    void *mem = malloc(sz);                                            \
    if (!mem) FNERR_AND(extra, MALLOC_ERR_FMT, MALLOC_ERR_ARG_SZ(sz)); \
    mem;                                                               \
  })
