/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> aps_group_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 aps_group_table_add(int param_1,uint param_2)

{
  ushort uVar1;
  undefined2 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  
  if (0xfd < (param_2 - 1 & 0xff)) {
    return 2;
  }
  if (param_1 == 0) {
    return 2;
  }
  puVar2 = (undefined2 *)group_table_find();
  if (puVar2 == (undefined2 *)0x0) {
    iVar3 = core_globals_get();
    iVar3 = *(int *)(iVar3 + 0x95c);
    iVar4 = core_globals_get();
    uVar7 = *(undefined4 *)(iVar4 + 0x960);
    iVar4 = core_globals_get();
    uVar1 = *(ushort *)(iVar4 + 0x964);
    uVar5 = mempool_alloc_idx(uVar7,(uint)uVar1);
    if (uVar1 <= uVar5) {
      return 1;
    }
    puVar2 = (undefined2 *)(iVar3 + uVar5 * 0x22);
    if (puVar2 == (undefined2 *)0x0) {
      return 1;
    }
    memset(puVar2 + 1,0,0x20);
    *puVar2 = (short)param_1;
  }
  uVar5 = 1 << (param_2 & 7) & 0xff;
  uVar6 = __atomic_fetch_or_1((int)puVar2 + (param_2 >> 3) + 2,uVar5,5);
  if ((uVar5 & uVar6) == 0) {
    aps_group_table_store_group(puVar2);
  }
  return 0;
}

