/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> color_control_desc.o -> ezb_zcl_color_control_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_color_control_create_cluster_desc(void *param_1,uint param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined1 auStack_1c [2];
  undefined1 auStack_1a [2];
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined1 auStack_16 [2];
  undefined1 auStack_14 [2];
  undefined1 auStack_12 [2];
  
  memcpy(auStack_1c,&_LANCHOR0,0xc);
  iVar1 = zcl_create_cluster_desc(0x300,param_2,0);
  if (iVar1 != 0) {
    if ((param_2 & 1) == 0) {
      puVar2 = &ezb_zcl_color_control_cluster_client_init;
    }
    else {
      puVar2 = &ezb_zcl_color_control_cluster_server_init;
    }
    *(undefined **)(iVar1 + 8) = puVar2;
    if (param_1 != (void *)0x0) {
      memcpy(auStack_1c,param_1,0xc);
    }
    zcl_cluster_desc_add_revision_attr(iVar1,3);
    if ((param_2 & 1) != 0) {
      ezb_zcl_color_control_cluster_desc_add_attr(iVar1,3,auStack_1c);
      ezb_zcl_color_control_cluster_desc_add_attr(iVar1,4,auStack_1a);
      ezb_zcl_color_control_cluster_desc_add_attr(iVar1,8,&uStack_18);
      ezb_zcl_color_control_cluster_desc_add_attr(iVar1,0xf,&uStack_17);
      ezb_zcl_color_control_cluster_desc_add_attr(iVar1,0x4001,auStack_16);
      ezb_zcl_color_control_cluster_desc_add_attr(iVar1,0x400a,auStack_14);
      ezb_zcl_color_control_cluster_desc_add_attr(iVar1,0x10,auStack_12);
      ezb_zcl_cluster_desc_add_manuf_attr(iVar1,0xeff0,0,0x40,0x131b,0);
    }
  }
  return iVar1;
}

