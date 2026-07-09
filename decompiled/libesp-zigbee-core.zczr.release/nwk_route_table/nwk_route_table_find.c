/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_table_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ushort * nwk_route_table_find(uint param_1)

{
  ushort *puVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = core_globals_get();
  uVar3 = 0;
  while( true ) {
    uVar3 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar2 + 0xc5c),*(undefined2 *)(iVar2 + 0xc60),uVar3);
    if (*(ushort *)(iVar2 + 0xc60) <= uVar3) {
      return (ushort *)0x0;
    }
    puVar1 = (ushort *)(*(int *)(iVar2 + 0xc58) + uVar3 * 0x10);
    if (*puVar1 == param_1) break;
    uVar3 = uVar3 + 1 & 0xffff;
  }
  return puVar1;
}

