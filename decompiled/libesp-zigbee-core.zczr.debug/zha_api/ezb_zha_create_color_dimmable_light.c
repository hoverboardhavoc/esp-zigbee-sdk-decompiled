/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zha_api.o -> ezb_zha_create_color_dimmable_light
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_zha_create_color_dimmable_light(byte param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  ushort uStack_38;
  undefined2 uStack_36;
  undefined4 uStack_34;
  
  if (param_2 == 0) {
    iVar1 = 0;
    iVar4 = 0;
    iVar5 = 0;
    iVar6 = 0;
    iVar7 = 0;
    iVar8 = 0;
  }
  else {
    iVar8 = param_2 + 2;
    iVar7 = param_2 + 4;
    iVar6 = param_2 + 6;
    iVar5 = param_2 + 0xe;
    iVar4 = param_2 + 0xf;
    iVar1 = param_2 + 0x10;
  }
  _uStack_38 = CONCAT22(0x104,(ushort)param_1);
  uStack_34 = 0x102;
  uVar2 = ezb_af_create_endpoint_desc(&uStack_38);
  uVar3 = ezb_zcl_basic_create_cluster_desc(param_2,1);
  ezb_af_endpoint_add_cluster_desc(uVar2,uVar3);
  uVar3 = ezb_zcl_identify_create_cluster_desc(iVar8,1);
  ezb_af_endpoint_add_cluster_desc(uVar2,uVar3);
  uVar3 = ezb_zcl_groups_create_cluster_desc(iVar7,1);
  ezb_af_endpoint_add_cluster_desc(uVar2,uVar3);
  uVar3 = ezb_zcl_scenes_create_cluster_desc(iVar6,1);
  ezb_af_endpoint_add_cluster_desc(uVar2,uVar3);
  uVar3 = ezb_zcl_on_off_create_cluster_desc(iVar5,1);
  ezb_af_endpoint_add_cluster_desc(uVar2,uVar3);
  uVar3 = ezb_zcl_level_create_cluster_desc(iVar4,1);
  ezb_af_endpoint_add_cluster_desc(uVar2,uVar3);
  uVar3 = ezb_zcl_color_control_create_cluster_desc(iVar1,1);
  ezb_af_endpoint_add_cluster_desc(uVar2,uVar3);
  return uVar2;
}

