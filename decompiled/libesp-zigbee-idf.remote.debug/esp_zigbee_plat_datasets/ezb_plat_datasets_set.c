/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_datasets.o -> ezb_plat_datasets_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool ezb_plat_datasets_set(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  char acStack_28 [20];
  
  if (s_nvs_handle == 0) {
    iVar1 = 0x103;
  }
  else {
    acStack_28[0] = '\0';
    acStack_28[1] = '\0';
    acStack_28[2] = '\0';
    acStack_28[3] = '\0';
    acStack_28[4] = '\0';
    acStack_28[5] = '\0';
    acStack_28[6] = 0;
    snprintf(acStack_28,7,"ZB%02x%02x");
    iVar1 = nvs_set_blob(s_nvs_handle,acStack_28,param_2,param_3);
    if ((iVar1 == 0) && (iVar1 = nvs_commit(s_nvs_handle), iVar1 == 0)) goto _L0;
  }
  uVar2 = esp_err_to_name(iVar1);
  esp_log(0x12,"ESP-ZIGBEE","Failed to set dataset %d: %s",param_1,uVar2);
_L0:
  return iVar1 != 0;
}

