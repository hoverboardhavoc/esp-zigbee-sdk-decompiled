/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_table_remove_dst
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void bind_table_remove_dst(aps_bind_dst_t *dst)

{
  uint uVar1;
  size_t sVar2;
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
    sVar2 = bind_src_size();
    bind_table_unbind((aps_bind_src_t *)((sVar2 & 0xffff) * uVar1 + iVar3),dst);
    uVar1 = uVar1 + 1 & 0xffff;
  }
  return;
}

