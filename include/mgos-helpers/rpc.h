#pragma once

#include <limits.h>
#include <stdbool.h>

#include <mgos_rpc.h>

#define BOOL_INVAL (sizeof(bool) > sizeof(unsigned char) ? UINT_MAX : UCHAR_MAX)

#define mg_rpc_errorf_and(extra, ...)      \
  do {                                     \
    mg_rpc_send_errorf(ri, ##__VA_ARGS__); \
    ri = NULL;                             \
    extra;                                 \
  } while (0)
#define mg_rpc_errorf_gt(...) mg_rpc_errorf_and(goto err, ##__VA_ARGS__)
#define mg_rpc_errorf_ret(...) mg_rpc_errorf_and(return, ##__VA_ARGS__)
#define mg_rpc_errorf_retv(ret, ...) \
  mg_rpc_errorf_and(return ret, ##__VA_ARGS__)
