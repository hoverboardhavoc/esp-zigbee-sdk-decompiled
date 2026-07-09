/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_get_free_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short aps_group_table_get_free_size(void)

{
  uint uVar1;
  int iVar2;
  short sVar3;
  undefined4 uVar4;
  
  uVar1 = 0;
  sVar3 = 0;
  while( true ) {
    iVar2 = core_globals_get();
    uVar4 = *(undefined4 *)(iVar2 + 0x960);
    iVar2 = core_globals_get();
    uVar1 = bitmap_find_next_bit(uVar4,*(undefined2 *)(iVar2 + 0x964),uVar1);
    iVar2 = core_globals_get();
    if (*(ushort *)(iVar2 + 0x964) <= uVar1) break;
    sVar3 = sVar3 + 1;
    uVar1 = uVar1 + 1 & 0xffff;
  }
  iVar2 = core_globals_get();
  return *(short *)(iVar2 + 0x964) - sVar3;
}

