/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> bind_table_remove_dst
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bind_table_remove_dst(aps_bind_dst_t *dst)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  size_t sVar4;
  undefined4 uVar5;
  
  uVar1 = 0;
  while( true ) {
    iVar2 = core_globals_get();
    uVar5 = *(undefined4 *)(iVar2 + 0x96c);
    iVar2 = core_globals_get();
    uVar3 = bitmap_find_next_bit(uVar5,*(undefined2 *)(iVar2 + 0x970),uVar1);
    iVar2 = core_globals_get();
    if (*(ushort *)(iVar2 + 0x970) <= uVar3) break;
    iVar2 = core_globals_get();
    iVar2 = *(int *)(iVar2 + 0x968);
    sVar4 = bind_src_size();
    uVar1 = uVar3 + 1 & 0xffff;
    bind_table_unbind((aps_bind_src_t *)(sVar4 * uVar3 + iVar2),dst);
  }
  return;
}

