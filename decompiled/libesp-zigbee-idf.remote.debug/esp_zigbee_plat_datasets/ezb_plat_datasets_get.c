/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.debug -> esp_zigbee_plat_datasets.o -> ezb_plat_datasets_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

int ezb_plat_datasets_get(undefined4 param_1,undefined4 param_2,undefined4 param_3,ushort *param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint auStack_2c [2];
  undefined2 uStack_24;
  undefined1 uStack_22;
  
  if (s_nvs_handle == 0) {
    iVar1 = 0x103;
  }
  else {
    auStack_2c[1] = 0;
    uStack_24 = 0;
    uStack_22 = 0;
    iVar1 = get_nvs_key_by_index(param_1,param_2,auStack_2c + 1,7);
    if (iVar1 == 0) {
      if (param_4 == (ushort *)0x0) {
        auStack_2c[0] = 0;
      }
      else {
        auStack_2c[0] = (uint)*param_4;
      }
      iVar1 = nvs_get_blob(s_nvs_handle,auStack_2c + 1,param_3,auStack_2c);
      if (iVar1 == 0) {
        if (param_4 == (ushort *)0x0) {
          return 0;
        }
        *param_4 = (ushort)auStack_2c[0];
        return 0;
      }
    }
  }
  if (iVar1 == 0x1102) {
    iVar1 = 5;
  }
  else {
    uVar2 = esp_err_to_name(iVar1);
    esp_log(0x12,"ESP-ZIGBEE","Failed to get dataset %d.%d: %s",param_1,param_2,uVar2);
    if (iVar1 != 0) {
      iVar1 = 5;
    }
  }
  return iVar1;
}

