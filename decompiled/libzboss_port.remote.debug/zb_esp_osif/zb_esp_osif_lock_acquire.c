/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libzboss_port.remote.debug -> zb_esp_osif.o -> zb_esp_osif_lock_acquire
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool zb_esp_osif_lock_acquire(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (s_zb_mutex == 0) {
    uVar2 = esp_log_timestamp(param_1);
    esp_log(1,"ZB OSIF","E (%lu) %s: Zigbee lock is not ready!\n",uVar2,"ZB OSIF");
    iVar1 = 0;
  }
  else {
    iVar1 = xQueueTakeMutexRecursive();
  }
  return iVar1 == 1;
}

