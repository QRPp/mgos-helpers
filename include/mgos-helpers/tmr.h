#pragma once

#include <mgos_timers.h>

#define MGOS_TMR_RESET(tmr, ...)      \
  ({                                  \
    MGOS_TMR_CLR(tmr);                \
    MGOS_TMR_SET(tmr, ##__VA_ARGS__); \
  })

#define MGOS_TMR_SET(tmr, ...) ({ tmr = mgos_set_timer(__VA_ARGS__); })

#define MGOS_TMR_CLR(tmr)          \
  do {                             \
    if (tmr) {                     \
      mgos_clear_timer(tmr);       \
      tmr = MGOS_INVALID_TIMER_ID; \
    }                              \
  } while (0)
