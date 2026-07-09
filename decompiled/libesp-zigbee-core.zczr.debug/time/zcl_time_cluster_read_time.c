/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> time.o -> zcl_time_cluster_read_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_time_cluster_read_time(undefined4 param_1,int param_2,uint *param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_3 == (uint *)0x0) {
    uVar3 = 0x87;
  }
  else {
    puVar1 = (undefined4 *)time_server_get_interface();
    pcVar6 = (code *)*puVar1;
    if (pcVar6 == (code *)0x0) {
      uVar3 = 0x8b;
    }
    else if (param_2 == 6) {
      iVar4 = time_server_get_attr_desc(param_1,2);
      if ((iVar4 == 0) || (*(int *)(iVar4 + 8) == 0)) {
        uVar2 = (*(code *)*puVar1)((code *)*puVar1);
        *param_3 = uVar2;
        uVar3 = 0;
      }
      else {
        iVar5 = (*(code *)*puVar1)((code *)*puVar1);
        *param_3 = iVar5 + **(int **)(iVar4 + 8);
        uVar3 = 0;
      }
    }
    else if (param_2 == 7) {
      uVar2 = (*pcVar6)();
      *param_3 = uVar2;
      iVar4 = time_server_get_attr_desc(param_1,2);
      if (iVar4 == 0) {
        iVar4 = 0;
      }
      else if (*(int **)(iVar4 + 8) == (int *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = **(int **)(iVar4 + 8);
      }
      uVar2 = *param_3;
      iVar5 = time_server_get_attr_desc(param_1,3);
      if (iVar5 == 0) {
        uVar7 = 0xffffffff;
      }
      else if (*(uint **)(iVar5 + 8) == (uint *)0x0) {
        uVar7 = 0xffffffff;
      }
      else {
        uVar7 = **(uint **)(iVar5 + 8);
      }
      iVar5 = time_server_get_attr_desc(param_1,4);
      if (iVar5 == 0) {
        uVar8 = 0xffffffff;
      }
      else if (*(uint **)(iVar5 + 8) == (uint *)0x0) {
        uVar8 = 0xffffffff;
      }
      else {
        uVar8 = **(uint **)(iVar5 + 8);
      }
      iVar5 = time_server_get_attr_desc(param_1,5);
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else if (*(int **)(iVar5 + 8) == (int *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = **(int **)(iVar5 + 8);
      }
      if ((((uVar7 == 0xffffffff) || (uVar8 == 0xffffffff)) || (*param_3 < uVar7)) ||
         (uVar8 < *param_3)) {
        *param_3 = uVar2 + iVar4;
        uVar3 = 0;
      }
      else {
        *param_3 = iVar5 + uVar2 + iVar4;
        uVar3 = 0;
      }
    }
    else if (param_2 == 0) {
      uVar2 = (*pcVar6)();
      *param_3 = uVar2;
      uVar3 = 0;
    }
    else {
      uVar3 = 0;
    }
  }
  return uVar3;
}

