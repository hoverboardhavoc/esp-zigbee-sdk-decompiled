/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_table_remove_src
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bind_table_remove_src(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while( true ) {
    iVar2 = core_globals_get();
    uVar1 = bitmap_find_next_bit(param_1 + 6,*(undefined2 *)(iVar2 + 0x97c),uVar1);
    iVar2 = core_globals_get();
    if (*(ushort *)(iVar2 + 0x97c) <= uVar1) break;
    iVar2 = core_globals_get();
    bind_table_unbind(param_1,*(int *)(iVar2 + 0x974) + uVar1 * 6);
    uVar1 = uVar1 + 1 & 0xffff;
  }
  return;
}

