/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_record_table_find_or_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 * nwk_route_record_table_find_or_create(uint param_1)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (0xfff7 < param_1) {
    param_1 = __assert_func(0,0,0,0);
  }
  puVar1 = (undefined2 *)nwk_route_record_table_find();
  if (puVar1 == (undefined2 *)0x0) {
    iVar2 = core_globals_get();
    uVar4 = *(undefined4 *)(iVar2 + 0xc70);
    iVar2 = core_globals_get();
    uVar3 = *(undefined4 *)(iVar2 + 0xc74);
    iVar2 = core_globals_get();
    puVar1 = (undefined2 *)mempool_alloc_ent(uVar4,uVar3,0x1c,*(undefined2 *)(iVar2 + 0xc78));
    if (puVar1 != (undefined2 *)0x0) {
      memset(puVar1 + 1,0,0x1a);
      *puVar1 = (short)param_1;
    }
  }
  return puVar1;
}

