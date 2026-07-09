/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 aps_group_table_add(int param_1,int param_2)

{
  ushort uVar1;
  undefined2 *__s;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  if ((param_2 - 1U & 0xff) < 0xfe) {
    if (param_1 == 0) {
      uVar2 = 2;
    }
    else {
      __s = (undefined2 *)group_table_find();
      if (__s == (undefined2 *)0x0) {
        iVar3 = core_globals_get();
        iVar3 = *(int *)(iVar3 + 0x95c);
        iVar4 = core_globals_get();
        uVar2 = *(undefined4 *)(iVar4 + 0x960);
        iVar4 = core_globals_get();
        uVar1 = *(ushort *)(iVar4 + 0x964);
        uVar5 = mempool_alloc_idx(uVar2,(uint)uVar1);
        if (uVar1 <= uVar5) {
          return 1;
        }
        __s = (undefined2 *)(iVar3 + uVar5 * 0x22);
        if (__s == (undefined2 *)0x0) {
          return 1;
        }
        memset(__s,0,0x22);
        *__s = (short)param_1;
      }
      group_add_endpoint(__s,param_2);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}

