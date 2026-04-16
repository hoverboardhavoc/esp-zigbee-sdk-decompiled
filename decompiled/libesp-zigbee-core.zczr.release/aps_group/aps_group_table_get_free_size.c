/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> aps_group_table_get_free_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t aps_group_table_get_free_size(void)

{
  undefined4 uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  sVar2 = 0;
  while( true ) {
    iVar3 = core_globals_get();
    uVar1 = *(undefined4 *)(iVar3 + 0x960);
    iVar3 = core_globals_get();
    uVar4 = bitmap_find_next_bit(uVar1,*(undefined2 *)(iVar3 + 0x964),uVar4);
    iVar3 = core_globals_get();
    if (*(ushort *)(iVar3 + 0x964) <= uVar4) break;
    sVar2 = sVar2 + 1;
    uVar4 = uVar4 + 1 & 0xffff;
  }
  iVar3 = core_globals_get();
  return *(short *)(iVar3 + 0x964) - sVar2;
}

