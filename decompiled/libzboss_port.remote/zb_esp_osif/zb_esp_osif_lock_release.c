/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_osif.o -> zb_esp_osif_lock_release
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_esp_osif_lock_release(void)

{
  undefined4 uVar1;
  
  if (s_zb_mutex != 0) {
    xQueueGiveMutexRecursive();
    return;
  }
  uVar1 = esp_log_timestamp();
  esp_log_write(1,"ZB OSIF",&_LC3,uVar1,"ZB OSIF");
  return;
}

