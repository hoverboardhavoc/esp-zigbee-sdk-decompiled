/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_cluster_desc_add_revision_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_cluster_desc_add_revision_attr(int param_1,undefined2 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 auStack_12 [5];
  
  if (param_1 == 0) {
    uVar2 = 2;
  }
  else {
    auStack_12[0] = param_2;
    iVar1 = zcl_create_attr_desc(0xfffd,0x21,1,0,auStack_12);
    *(undefined4 *)(iVar1 + 0xc) = *(undefined4 *)(param_1 + 0xc);
    *(int *)(param_1 + 0xc) = iVar1;
    uVar2 = 0;
  }
  return uVar2;
}

