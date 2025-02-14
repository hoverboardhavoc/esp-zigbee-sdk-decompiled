/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_osif.o -> zb_esp_osif_lock_acquire
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
    esp_log_write(1,"ZB OSIF",&_LC3,uVar2,"ZB OSIF");
    iVar1 = 0;
  }
  else {
    iVar1 = xQueueTakeMutexRecursive();
  }
  return iVar1 == 1;
}

