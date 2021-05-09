#pragma once

#include <mgos-helpers/log.h>

#define TRY_MALLOC_OR(extra, obj) TRY_MALLOC_SZ_OR(extra, sizeof(*obj))
#define TRY_MALLOC_SZ_OR(extra, sz)                                    \
  ({                                                                   \
    void *mem = malloc(sz);                                            \
    if (!mem) FNERR_AND(extra, MALLOC_ERR_FMT, MALLOC_ERR_ARG_SZ(sz)); \
    mem;                                                               \
  })
