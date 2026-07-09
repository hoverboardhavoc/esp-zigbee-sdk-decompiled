/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_dup.o -> aps_dup_table_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_dup_table_handle_tick(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = core_globals_get();
  uVar3 = 0;
  bVar1 = true;
  while( true ) {
    uVar3 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar2 + 0x988),*(undefined2 *)(iVar2 + 0x98c),uVar3);
    if (*(ushort *)(iVar2 + 0x98c) <= uVar3) break;
    iVar4 = *(int *)(iVar2 + 0x984) + uVar3 * 4;
    *(byte *)(iVar4 + 3) =
         ((byte)((ushort)*(undefined2 *)(iVar4 + 2) >> 8) & 0x3f) + 0x3f & 0x3f |
         *(byte *)(iVar4 + 3) & 0xc0;
    if ((*(byte *)(uVar3 * 4 + *(int *)(iVar2 + 0x984) + 3) & 0x3f) == 0) {
      mempool_free_ent(*(undefined4 *)(iVar2 + 0x988),4,*(undefined2 *)(iVar2 + 0x98c));
    }
    else {
      bVar1 = false;
    }
    uVar3 = uVar3 + 1 & 0xffff;
  }
  if (bVar1) {
    time_ticker_unregister_receiver(4);
  }
  return;
}

