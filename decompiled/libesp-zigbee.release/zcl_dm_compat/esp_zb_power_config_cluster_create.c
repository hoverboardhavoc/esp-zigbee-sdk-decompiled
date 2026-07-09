/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_power_config_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_power_config_cluster_create(int param_1)

{
  int iVar1;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined2 auStack_12 [3];
  
  iVar1 = power_config_cluster_create();
  if (iVar1 != 0) {
    uStack_14 = 0;
    uStack_13 = 0;
    auStack_12[0] = 0;
    if (param_1 != 0) {
      uStack_14 = *(undefined1 *)(param_1 + 8);
      uStack_13 = *(undefined1 *)(param_1 + 9);
      auStack_12[0] = *(undefined2 *)(param_1 + 6);
    }
    power_config_cluster_add_attr(iVar1,1,&uStack_14);
    power_config_cluster_add_attr(iVar1,0x10,&uStack_13);
    power_config_cluster_add_attr(iVar1,0x13,auStack_12);
  }
  return iVar1;
}

