/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> door_lock_desc.o -> ezb_zcl_door_lock_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_door_lock_create_cluster_desc(undefined1 *param_1,uint param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined1 uStack_14;
  undefined1 uStack_13;
  undefined1 auStack_12 [2];
  
  uStack_14 = 0;
  uStack_13 = 0;
  auStack_12[0] = 0;
  iVar1 = zcl_create_cluster_desc(0x101,0);
  if (iVar1 != 0) {
    if ((param_2 & 1) == 0) {
      puVar2 = &ezb_zcl_door_lock_cluster_client_init;
    }
    else {
      puVar2 = &ezb_zcl_door_lock_cluster_server_init;
    }
    *(undefined **)(iVar1 + 8) = puVar2;
    if (param_1 != (undefined1 *)0x0) {
      uStack_14 = *param_1;
      uStack_13 = param_1[1];
      auStack_12[0] = param_1[2];
    }
    zcl_cluster_desc_add_revision_attr(iVar1,1);
    if ((param_2 & 1) != 0) {
      ezb_zcl_door_lock_cluster_desc_add_attr(iVar1,0,&uStack_14);
      ezb_zcl_door_lock_cluster_desc_add_attr(iVar1,1,&uStack_13);
      ezb_zcl_door_lock_cluster_desc_add_attr(iVar1,2,auStack_12);
    }
  }
  return iVar1;
}

