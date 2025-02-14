/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_osif.o -> zb_esp_abort
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_esp_abort(void)

{
  __assert_func("//builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_osif.c",0xa8,
                "zb_esp_abort","false");
  zb_esp_set_event(s_zb_sched_fd);
  return;
}

