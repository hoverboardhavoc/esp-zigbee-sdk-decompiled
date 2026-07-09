/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_datasets.o -> ezb_plat_datasets_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool ezb_plat_datasets_set(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char acStack_18 [8];
  
  if (s_nvs_handle == 0) {
    iVar1 = 0x103;
  }
  else {
    acStack_18[0] = '\0';
    acStack_18[1] = '\0';
    acStack_18[2] = '\0';
    acStack_18[3] = '\0';
    acStack_18[4] = '\0';
    acStack_18[5] = '\0';
    acStack_18[6] = 0;
    snprintf(acStack_18,7,"ZB%02x%02x");
    iVar1 = nvs_set_blob(s_nvs_handle,acStack_18,param_1,param_2);
    if (iVar1 == 0) {
      iVar1 = nvs_commit(s_nvs_handle);
    }
  }
  return iVar1 != 0;
}

