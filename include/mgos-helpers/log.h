#pragma once

#include <mgos.h>

#define FNERR(...) FNLOG(LL_ERROR, ##__VA_ARGS__)
#define FNERR_AND(extra, ...) \
  do {                        \
    FNERR(__VA_ARGS__);       \
    extra;                    \
  } while (0)
#define FNERR_CONT(...) FNERR_AND(continue, ##__VA_ARGS__)
#define FNERR_GT(...) FNERR_GTL(err, ##__VA_ARGS__)
#define FNERR_GTL(lbl, ...) FNERR_AND(goto lbl, ##__VA_ARGS__)
#define FNERR_RET(ret, ...) FNERR_AND(return ret, ##__VA_ARGS__)
#define FNLOG(lvl, fmt, ...) \
  LOG(lvl, ("%s(): " fmt, __FUNCTION__, ##__VA_ARGS__))

#define try_gt(call, ...)                            \
  ({                                                 \
    if (!call(__VA_ARGS__)) FNERR_GT("%s() failed", #call); \
    true;                                            \
  })