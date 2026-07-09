/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_poll_control_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_poll_control_cluster_create(int param_1)

{
  int iVar1;
  undefined2 uStack_1a;
  undefined4 uStack_18;
  undefined4 auStack_14 [2];
  
  iVar1 = poll_control_cluster_create();
  if (iVar1 != 0) {
    auStack_14[0] = 0;
    uStack_18 = 0;
    uStack_1a = 0;
    if (param_1 != 0) {
      auStack_14[0] = *(undefined4 *)(param_1 + 0xc);
      uStack_18 = *(undefined4 *)(param_1 + 0x10);
      uStack_1a = *(undefined2 *)(param_1 + 0x14);
    }
    poll_control_cluster_add_attr(iVar1,4,auStack_14);
    poll_control_cluster_add_attr(iVar1,5,&uStack_18);
    poll_control_cluster_add_attr(iVar1,6,&uStack_1a);
  }
  return iVar1;
}

