#pragma once

#include <mgos_time.h>

#define MGOS_US_SINCE(when) (mgos_uptime_micros() - (when))
#define MGOS_OLDER_THAN_S(when, s) \
  (MGOS_US_SINCE(when) > ((int64_t) s) * 1000000)
#define MGOS_OLDER_THAN_MS(when, ms) \
  (MGOS_US_SINCE(when) > ((int64_t) ms) * 1000)
#define MGOS_OLDER_THAN_US(when, us) (MGOS_US_SINCE(when) > (us))
