/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libzboss_port.remote.debug -> zb_esp_osif.o -> zb_esp_osif_lock_release
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_esp_osif_lock_release(void)

{
  undefined4 uVar1;
  
  if (s_zb_mutex == 0) {
    uVar1 = esp_log_timestamp();
    esp_log(1,"ZB OSIF","E (%lu) %s: Zigbee lock is not ready!\n",uVar1,"ZB OSIF");
  }
  else {
    xQueueGiveMutexRecursive();
  }
  return;
}

