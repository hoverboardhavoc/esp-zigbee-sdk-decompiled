/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_remove_src
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_bind_table_remove_src(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = bind_table_find_src();
  if (iVar2 != 0) {
    uVar1 = 0;
    while( true ) {
      iVar3 = core_globals_get();
      uVar4 = bitmap_find_next_bit(iVar2 + 6,*(undefined2 *)(iVar3 + 0x97c),uVar1);
      iVar3 = core_globals_get();
      if (*(ushort *)(iVar3 + 0x97c) <= uVar4) break;
      iVar3 = core_globals_get();
      uVar1 = uVar4 + 1 & 0xffff;
      bind_table_unbind(iVar2,*(int *)(iVar3 + 0x974) + uVar4 * 6);
    }
  }
  return;
}

