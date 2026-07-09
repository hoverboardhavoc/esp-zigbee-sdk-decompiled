/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> time_ticker.o -> time_ticker_unregister_receiver
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void time_ticker_unregister_receiver(uint param_1)

{
  __atomic_fetch_and_4(s_tmtk + (param_1 >> 5) * 4,~(1 << (param_1 & 0x1f)),5);
  if (s_tmtk._16_4_ == 0) {
    milli_timer_stop(s_tmtk);
    return;
  }
  return;
}

