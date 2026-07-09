/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_dump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_bind_table_dump(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  log_write(3,"aps_bind.c","Dump APS Bind Table");
  uVar5 = 0;
  while( true ) {
    iVar3 = core_globals_get();
    uVar1 = *(undefined4 *)(iVar3 + 0x96c);
    iVar3 = core_globals_get();
    uVar5 = bitmap_find_next_bit(uVar1,*(undefined2 *)(iVar3 + 0x970),uVar5);
    iVar3 = core_globals_get();
    if (*(ushort *)(iVar3 + 0x970) <= uVar5) break;
    iVar3 = core_globals_get();
    iVar3 = *(int *)(iVar3 + 0x968);
    uVar4 = bind_src_size();
    iVar3 = iVar3 + (uVar4 & 0xffff) * uVar5;
    bind_table_dump_src(iVar3);
    uVar4 = 0;
    while( true ) {
      iVar2 = core_globals_get();
      uVar4 = bitmap_find_next_bit(iVar3 + 6,*(undefined2 *)(iVar2 + 0x97c),uVar4);
      iVar2 = core_globals_get();
      if (*(ushort *)(iVar2 + 0x97c) <= uVar4) break;
      iVar2 = core_globals_get();
      bind_table_dump_dst(*(int *)(iVar2 + 0x974) + uVar4 * 6);
      uVar4 = uVar4 + 1 & 0xffff;
    }
    uVar5 = uVar5 + 1 & 0xffff;
  }
  return;
}

