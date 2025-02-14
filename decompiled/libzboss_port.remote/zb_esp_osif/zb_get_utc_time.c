/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_osif.o -> zb_get_utc_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_get_utc_time(void)

{
  if (get_utc_time_cb != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0001052c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*get_utc_time_cb)();
    return;
  }
  esp_timer_get_time();
  __divdi3(1000000,0);
  return;
}

