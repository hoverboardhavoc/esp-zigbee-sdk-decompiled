/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zha_api.o -> ezb_zha_create_on_off_switch
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_zha_create_on_off_switch(undefined1 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined2 uStack_16;
  
  iVar3 = param_2 + 2;
  if (param_2 == 0) {
    iVar3 = 0;
  }
  memset(&uStack_17,0,7);
  uStack_16 = 0x104;
  uStack_18 = param_1;
  uVar1 = ezb_af_create_endpoint_desc(&uStack_18);
  uVar2 = ezb_zcl_basic_create_cluster_desc(param_2,1);
  ezb_af_endpoint_add_cluster_desc(uVar1,uVar2);
  uVar2 = ezb_zcl_identify_create_cluster_desc(iVar3,1);
  ezb_af_endpoint_add_cluster_desc(uVar1,uVar2);
  uVar2 = ezb_zcl_on_off_create_cluster_desc(0,2);
  ezb_af_endpoint_add_cluster_desc(uVar1,uVar2);
  uVar2 = ezb_zcl_identify_create_cluster_desc(0,2);
  ezb_af_endpoint_add_cluster_desc(uVar1,uVar2);
  return uVar1;
}

