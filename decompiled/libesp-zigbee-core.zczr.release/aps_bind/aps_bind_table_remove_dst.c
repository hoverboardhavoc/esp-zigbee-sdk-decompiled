/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_remove_dst
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_bind_table_remove_dst(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar4 = bind_table_find_dst();
  if (iVar4 == 0) {
    return;
  }
  uVar1 = 0;
  while( true ) {
    iVar2 = core_globals_get();
    uVar5 = *(undefined4 *)(iVar2 + 0x96c);
    iVar2 = core_globals_get();
    uVar3 = bitmap_find_next_bit(uVar5,*(undefined2 *)(iVar2 + 0x970),uVar1);
    iVar2 = core_globals_get();
    if (*(ushort *)(iVar2 + 0x970) <= uVar3) break;
    iVar2 = core_globals_get();
    iVar6 = *(int *)(iVar2 + 0x968);
    iVar2 = bind_src_size();
    uVar1 = uVar3 + 1 & 0xffff;
    bind_table_unbind(iVar2 * uVar3 + iVar6,iVar4);
  }
  return;
}

