/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> oui_table_clear_unused_entries
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void oui_table_clear_unused_entries(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = core_globals_get();
  iVar2 = core_globals_get();
  *(undefined1 *)(iVar1 + 0xcaa) = 0;
  *(undefined1 *)(iVar1 + 0xcab) = 0;
  *(undefined1 *)(iVar1 + 0xcac) = 0;
  *(undefined1 *)(iVar1 + 0xcad) = 0;
  uVar3 = 0;
  while (uVar3 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar2 + 0xcb0),*(undefined2 *)(iVar2 + 0xcb8),uVar3),
        uVar3 < *(ushort *)(iVar2 + 0xcb8)) {
    iVar4 = *(int *)(iVar2 + 0xcb4) + uVar3 * 0x10;
    if ((*(ushort *)(iVar4 + 0xe) >> 10 & 1) == 0) {
      test_and_set_bitmap((uint)*(byte *)(iVar4 + 5),(bitmap_t *)(iVar1 + 0xcaa));
    }
    uVar3 = uVar3 + 1 & 0xffff;
  }
  return;
}

