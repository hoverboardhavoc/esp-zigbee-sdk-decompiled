/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_thermostat_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_thermostat_cluster_create(int param_1)

{
  int iVar1;
  undefined2 uStack_14;
  undefined2 auStack_12 [3];
  
  iVar1 = thermostat_cluster_create();
  if (iVar1 != 0) {
    auStack_12[0] = 0xa28;
    uStack_14 = 2000;
    if (param_1 != 0) {
      auStack_12[0] = *(undefined2 *)(param_1 + 4);
      uStack_14 = *(undefined2 *)(param_1 + 6);
    }
    thermostat_cluster_add_attr(iVar1,0x11,auStack_12);
    thermostat_cluster_add_attr(iVar1,0x12,&uStack_14);
  }
  return iVar1;
}

