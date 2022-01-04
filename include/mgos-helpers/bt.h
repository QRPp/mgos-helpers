#pragma once

#include <alloca.h>

#include <mgos_bt.h>
#include <mgos_bt_gattc.h>

#define BT_ADDR_STRA(a, f) \
  mgos_bt_addr_to_str((a), (f), alloca(MGOS_BT_ADDR_STR_LEN))
#define BT_UUID_STRA(u) mgos_bt_uuid_to_str((u), alloca(37))

static inline bool mgos_bt_gattc_discover_hnd(
    struct mgos_bt_gattc_discovery_result_arg *res, struct mgos_bt_uuid *svc,
    struct mgos_bt_uuid *chr, uint16_t *hnd) {
  if (!mgos_bt_uuid_eq(&res->svc, svc) || !mgos_bt_uuid_eq(&res->chr, chr))
    return false;
  *hnd = res->handle;
  return true;
}
