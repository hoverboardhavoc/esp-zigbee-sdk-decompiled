/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> time.o -> zcl_time_cluster_read_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_time_cluster_read_time(undefined4 param_1,int param_2,uint *param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_3 == (uint *)0x0) {
    return 0x87;
  }
  puVar1 = (undefined4 *)time_server_get_interface();
  pcVar4 = (code *)*puVar1;
  if (pcVar4 == (code *)0x0) {
    return 0x8b;
  }
  if (param_2 == 6) {
    iVar3 = time_server_get_attr_desc(param_1,2);
    pcVar4 = (code *)*puVar1;
    if ((iVar3 != 0) && (*(int *)(iVar3 + 8) != 0)) {
      iVar5 = (*pcVar4)();
      uVar2 = **(int **)(iVar3 + 8) + iVar5;
      goto _L0;
    }
  }
  else {
    if (param_2 == 7) {
      uVar2 = (*pcVar4)(0x8b);
      *param_3 = uVar2;
      iVar3 = time_server_get_attr_desc(param_1,2);
      iVar5 = 0;
      if ((iVar3 != 0) && (*(int **)(iVar3 + 8) != (int *)0x0)) {
        iVar5 = **(int **)(iVar3 + 8);
      }
      uVar2 = *param_3;
      iVar3 = time_server_get_attr_desc(param_1,3);
      uVar8 = 0xffffffff;
      if ((iVar3 != 0) && (*(uint **)(iVar3 + 8) != (uint *)0x0)) {
        uVar8 = **(uint **)(iVar3 + 8);
      }
      iVar3 = time_server_get_attr_desc(param_1,4);
      uVar7 = 0xffffffff;
      if ((iVar3 != 0) && (*(uint **)(iVar3 + 8) != (uint *)0x0)) {
        uVar7 = **(uint **)(iVar3 + 8);
      }
      iVar3 = time_server_get_attr_desc(param_1,5);
      iVar6 = 0;
      if ((iVar3 != 0) && (*(int **)(iVar3 + 8) != (int *)0x0)) {
        iVar6 = **(int **)(iVar3 + 8);
      }
      if ((((uVar8 == 0xffffffff) || (uVar7 == 0xffffffff)) || (*param_3 < uVar8)) ||
         (uVar7 < *param_3)) {
        *param_3 = iVar5 + uVar2;
        return 0;
      }
      uVar2 = iVar6 + iVar5 + uVar2;
_L0:
      *param_3 = uVar2;
      return 0;
    }
    if (param_2 != 0) {
      return 0;
    }
  }
  uVar2 = (*pcVar4)();
  *param_3 = uVar2;
  return 0;
}

