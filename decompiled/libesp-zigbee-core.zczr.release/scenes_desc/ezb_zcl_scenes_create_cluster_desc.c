/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> scenes_desc.o -> ezb_zcl_scenes_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_scenes_create_cluster_desc(void *param_1,uint param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uStack_18;
  undefined2 uStack_14;
  undefined1 auStack_12 [2];
  
  uStack_18 = 0;
  uStack_14 = 0;
  auStack_12[0] = 0xf;
  iVar1 = zcl_create_cluster_desc(5,0);
  if (iVar1 != 0) {
    if ((param_2 & 1) == 0) {
      puVar2 = &ezb_zcl_scenes_cluster_client_init;
    }
    else {
      puVar2 = &ezb_zcl_scenes_cluster_server_init;
    }
    *(undefined **)(iVar1 + 8) = puVar2;
    if (param_1 != (void *)0x0) {
      memcpy(&uStack_18,param_1,8);
    }
    zcl_cluster_desc_add_revision_attr(iVar1,3);
    if ((param_2 & 1) != 0) {
      ezb_zcl_scenes_cluster_desc_add_attr(iVar1,0,&uStack_18);
      ezb_zcl_scenes_cluster_desc_add_attr(iVar1,1,(int)&uStack_18 + 1);
      ezb_zcl_scenes_cluster_desc_add_attr(iVar1,2,(int)&uStack_18 + 2);
      ezb_zcl_scenes_cluster_desc_add_attr(iVar1,3,&uStack_14);
      ezb_zcl_scenes_cluster_desc_add_attr(iVar1,4,(int)&uStack_14 + 1);
      ezb_zcl_cluster_desc_add_manuf_attr(iVar1,0xeff0,0x20,0x40,0x131b,auStack_12);
      ezb_zcl_cluster_desc_add_manuf_attr(iVar1,0xeff1,0,0x40,0x131b,0);
    }
  }
  return iVar1;
}

