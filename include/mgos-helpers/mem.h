#pragma once

#include <errno.h>
#include <string.h>

#include <mgos-helpers/log.h>

#define MALLOC_ERR_FMT "%s(%u): (%d) %s"
#define MALLOC_ERR_ARG(obj) MALLOC_ERR_ARG_SZ(sizeof(*obj))
#define MALLOC_ERR_ARG_SZ(sz) "malloc", (sz), errno, strerror(errno)

#define TRY_CALLOC_OR(extra, o) TRY_CALLOC_SZ_OR(extra, sizeof(*o))
#define TRY_CALLOC_SZ_OR(extra, sz) memset(TRY_MALLOC_SZ_OR(extra, sz), 0, sz)
#define TRY_MALLOC_OR(extra, o) TRY_MALLOC_SZ_OR(extra, sizeof(*o))
#define TRY_MALLOC_SZ_OR(extra, sz)                                    \
  ({                                                                   \
    void *mem = malloc(sz);                                            \
    if (!mem) FNERR_AND(extra, MALLOC_ERR_FMT, MALLOC_ERR_ARG_SZ(sz)); \
    mem;                                                               \
  })
