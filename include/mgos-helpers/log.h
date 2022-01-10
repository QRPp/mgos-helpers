#pragma once

#include <mgos.h>

#define CALL_FAILED(fn) CALL_FAILED_FMT, #fn
#define CALL_FAILED_FMT "%s() failed"

#define FNERR(...) FNLOG(LL_ERROR, __VA_ARGS__)
#define FNERR_AND(extra, ...) \
  do {                        \
    FNERR(__VA_ARGS__);       \
    extra;                    \
  } while (0)
#define FNERR_CONT(...) FNERR_AND(continue, ##__VA_ARGS__)
#define FNERR_GT(...) FNERR_GTL(err, ##__VA_ARGS__)
#define FNERR_GTL(lbl, ...) FNERR_AND(goto lbl, ##__VA_ARGS__)
#define FNERR_RET(ret, ...) FNERR_AND(return ret, ##__VA_ARGS__)
#define FNERR_RETF(...) FNERR_RET(false, ##__VA_ARGS__)
#define FNLOG(lvl, fmt, ...) \
  LOG(lvl, ("%s(): " fmt, __FUNCTION__, ##__VA_ARGS__))

#define MUL(num) MULS(num, "", "s")
#define MULS(num, s, m) ((num) == 1 ? (s) : (m))
#define ON_OFF(b) (b ? "ON" : "OFF")
#define YES_NO(b) (b ? "YES" : "NO")

#define TRY_OR(extra, call, ...)                  \
  ({                                              \
    bool ok = call(__VA_ARGS__);                  \
    if (!ok) FNERR_AND(extra, CALL_FAILED(call)); \
    ok;                                           \
  })
#define TRY_CONT(call, ...) TRY_OR(continue, call, ##__VA_ARGS__)
#define TRY_GT(call, ...) TRY_GTL(err, call, ##__VA_ARGS__)
#define TRY_GTL(lbl, call, ...) TRY_OR(goto lbl, call, ##__VA_ARGS__)
#define TRY_RET(ret, call, ...) TRY_OR(return ret, call, ##__VA_ARGS__)
#define TRY_RETF(call, ...) TRY_RET(false, call, ##__VA_ARGS__)
