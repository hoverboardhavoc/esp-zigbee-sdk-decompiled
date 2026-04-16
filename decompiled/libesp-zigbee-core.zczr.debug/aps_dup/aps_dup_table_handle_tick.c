/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_dup.o -> aps_dup_table_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_dup_table_handle_tick(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  void *obj;
  
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
    obj = (void *)(uVar3 * 4 + (int)*(void **)(iVar2 + 0x984));
    if ((*(byte *)((int)obj + 3) & 0x3f) == 0) {
      mempool_free_ent(*(void **)(iVar2 + 0x984),*(bitmap_t **)(iVar2 + 0x988),4,
                       *(uint16_t *)(iVar2 + 0x98c),obj);
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

