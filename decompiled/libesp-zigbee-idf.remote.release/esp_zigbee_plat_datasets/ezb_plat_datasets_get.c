/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_datasets.o -> ezb_plat_datasets_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */

undefined4
ezb_plat_datasets_get(undefined4 param_1,undefined4 param_2,undefined4 param_3,ushort *param_4)

{
  int iVar1;
  uint auStack_1c [2];
  undefined2 uStack_14;
  undefined1 uStack_12;
  
  if (s_nvs_handle != 0) {
    auStack_1c[1] = 0;
    uStack_14 = 0;
    uStack_12 = 0;
    iVar1 = get_nvs_key_by_index_constprop_0(param_1,param_2,auStack_1c + 1);
    if (iVar1 == 0) {
      auStack_1c[0] = 0;
      if (param_4 != (ushort *)0x0) {
        auStack_1c[0] = (uint)*param_4;
      }
      iVar1 = nvs_get_blob(s_nvs_handle,auStack_1c + 1,param_3,auStack_1c);
      if (iVar1 == 0) {
        if (param_4 == (ushort *)0x0) {
          return 0;
        }
        *param_4 = (ushort)auStack_1c[0];
        return 0;
      }
    }
  }
  return 5;
}

