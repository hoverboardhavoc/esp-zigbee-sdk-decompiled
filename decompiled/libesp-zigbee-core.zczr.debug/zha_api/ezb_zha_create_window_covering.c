/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zha_api.o -> ezb_zha_create_window_covering
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_zha_create_window_covering(byte param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ushort uStack_28;
  undefined2 uStack_26;
  undefined4 uStack_24;
  
  if (param_2 == 0) {
    iVar1 = 0;
    iVar4 = 0;
    iVar5 = 0;
    iVar6 = 0;
  }
  else {
    iVar6 = param_2 + 2;
    iVar5 = param_2 + 4;
    iVar4 = param_2 + 7;
    iVar1 = param_2 + 8;
  }
  _uStack_28 = CONCAT22(0x104,(ushort)param_1);
  uStack_24 = 0x202;
  uVar2 = ezb_af_create_endpoint_desc(&uStack_28);
  uVar3 = ezb_zcl_basic_create_cluster_desc(param_2,1);
  ezb_af_endpoint_add_cluster_desc(uVar2,uVar3);
  uVar3 = ezb_zcl_identify_create_cluster_desc(iVar6,1);
  ezb_af_endpoint_add_cluster_desc(uVar2,uVar3);
  uVar3 = ezb_zcl_window_covering_create_cluster_desc(iVar5,1);
  ezb_af_endpoint_add_cluster_desc(uVar2,uVar3);
  uVar3 = ezb_zcl_groups_create_cluster_desc(iVar4,1);
  ezb_af_endpoint_add_cluster_desc(uVar2,uVar3);
  uVar3 = ezb_zcl_scenes_create_cluster_desc(iVar1,1);
  ezb_af_endpoint_add_cluster_desc(uVar2,uVar3);
  return uVar2;
}

