/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_table_remove_dst
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bind_table_remove_dst(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar1 = 0;
  while( true ) {
    iVar3 = core_globals_get();
    uVar4 = *(undefined4 *)(iVar3 + 0x96c);
    iVar3 = core_globals_get();
    uVar1 = bitmap_find_next_bit(uVar4,*(undefined2 *)(iVar3 + 0x970),uVar1);
    iVar3 = core_globals_get();
    if (*(ushort *)(iVar3 + 0x970) <= uVar1) break;
    iVar3 = core_globals_get();
    iVar3 = *(int *)(iVar3 + 0x968);
    uVar2 = bind_src_size();
    bind_table_unbind((uVar2 & 0xffff) * uVar1 + iVar3,param_1);
    uVar1 = uVar1 + 1 & 0xffff;
  }
  return;
}

