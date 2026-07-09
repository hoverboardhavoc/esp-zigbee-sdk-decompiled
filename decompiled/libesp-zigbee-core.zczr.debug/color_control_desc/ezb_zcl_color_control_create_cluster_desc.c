/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> color_control_desc.o -> ezb_zcl_color_control_create_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_color_control_create_cluster_desc(undefined4 *param_1,uint param_2)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_1c = 0x607d616b;
  uStack_18 = "luster_role == 0x01U || cluster_role == 0x02U";
  uStack_14 = 8;
  iVar1 = zcl_create_cluster_desc(0x300,0);
  if (iVar1 != 0) {
    if ((param_2 & 1) == 0) {
      puVar2 = &ezb_zcl_color_control_cluster_client_init;
    }
    else {
      puVar2 = &ezb_zcl_color_control_cluster_server_init;
    }
    *(undefined **)(iVar1 + 8) = puVar2;
    if (param_1 != (undefined4 *)0x0) {
      uStack_1c = *param_1;
      uStack_18 = (char *)param_1[1];
      uStack_14 = param_1[2];
    }
    zcl_cluster_desc_add_revision_attr(iVar1,3);
    if ((param_2 & 1) != 0) {
      ezb_zcl_color_control_cluster_desc_add_attr(iVar1,3,&uStack_1c);
      ezb_zcl_color_control_cluster_desc_add_attr(iVar1,4,(int)&uStack_1c + 2);
      ezb_zcl_color_control_cluster_desc_add_attr(iVar1,8,&uStack_18);
      ezb_zcl_color_control_cluster_desc_add_attr(iVar1,0xf,(int)&uStack_18 + 1);
      ezb_zcl_color_control_cluster_desc_add_attr(iVar1,0x4001,(int)&uStack_18 + 2);
      ezb_zcl_color_control_cluster_desc_add_attr(iVar1,0x400a,&uStack_14);
      ezb_zcl_color_control_cluster_desc_add_attr(iVar1,0x10,(int)&uStack_14 + 2);
      ezb_zcl_cluster_desc_add_manuf_attr(iVar1,0xeff0,0,0x40,0x131b,0);
    }
  }
  return iVar1;
}

