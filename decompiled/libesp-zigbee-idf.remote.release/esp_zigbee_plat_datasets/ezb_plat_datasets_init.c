/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_datasets.o -> ezb_plat_datasets_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_plat_datasets_init(void)

{
  int iVar1;
  
  if (s_nvs_handle != 0) {
    return;
  }
  iVar1 = nvs_open_from_partition(s_storage_name,"zigbee",1,&s_nvs_handle);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  return;
}

