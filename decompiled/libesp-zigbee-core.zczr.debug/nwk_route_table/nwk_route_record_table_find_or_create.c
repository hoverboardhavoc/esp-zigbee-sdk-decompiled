/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_record_table_find_or_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 * nwk_route_record_table_find_or_create(uint param_1)

{
  ushort uVar1;
  undefined2 *unaff_s0;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  
  if (param_1 < 0xfff8) {
    unaff_s0 = (undefined2 *)nwk_route_record_table_find();
    if (unaff_s0 != (undefined2 *)0x0) {
      return unaff_s0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_route_table.c",0x1bb,
                  "nwk_route_record_table_find_or_create","!((dst_addr) >= 0xfff8)");
  }
  iVar2 = core_globals_get();
  iVar4 = *(int *)(iVar2 + 0xc70);
  iVar2 = core_globals_get();
  uVar5 = *(undefined4 *)(iVar2 + 0xc74);
  iVar2 = core_globals_get();
  uVar1 = *(ushort *)(iVar2 + 0xc78);
  uVar3 = mempool_alloc_idx(uVar5,(uint)uVar1);
  if ((uVar3 < uVar1) &&
     (unaff_s0 = (undefined2 *)(uVar3 * 0x1c + iVar4), unaff_s0 != (undefined2 *)0x0)) {
    memset(unaff_s0,0,0x1c);
    *unaff_s0 = (short)param_1;
  }
  return unaff_s0;
}

