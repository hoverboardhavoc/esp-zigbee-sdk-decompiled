/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_datasets.o -> ezb_plat_datasets_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_plat_datasets_delete(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined1 uStack_12;
  
  if (s_nvs_handle == 0) {
    iVar1 = 0x103;
  }
  else {
    if (param_2 == -1) {
      iVar1 = erase_all_key(param_1);
      if (iVar1 != 0) goto _L0;
    }
    else {
      uStack_18 = 0;
      uStack_14 = 0;
      uStack_12 = 0;
      iVar1 = get_nvs_key_by_index(param_1,param_2,&uStack_18,7);
      if (iVar1 != 0) goto _L0;
      nvs_erase_key(s_nvs_handle,&uStack_18);
    }
    iVar1 = nvs_commit(s_nvs_handle);
    if (iVar1 == 0) {
      return 0;
    }
  }
_L0:
  if (iVar1 == 0x1102) {
    iVar1 = 5;
  }
  else {
    uVar2 = esp_err_to_name(iVar1);
    esp_log(0x12,"ESP-ZIGBEE","Failed to delete dataset %d.%d: %s",param_1,param_2,uVar2);
    if (iVar1 != 0) {
      iVar1 = 5;
    }
  }
  return iVar1;
}

