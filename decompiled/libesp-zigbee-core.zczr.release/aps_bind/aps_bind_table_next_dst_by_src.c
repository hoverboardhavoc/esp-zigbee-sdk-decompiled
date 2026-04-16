/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_next_dst_by_src
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

aps_bind_dst_t * aps_bind_table_next_dst_by_src(aps_bind_src_t *src,aps_bind_dst_t *dst)

{
  uint uVar1;
  int iVar2;
  aps_bind_dst_t *paVar3;
  
  if (dst == (aps_bind_dst_t *)0x0) {
    uVar1 = 0xffff;
  }
  else {
    iVar2 = core_globals_get();
    uVar1 = ((int)dst - *(int *)(iVar2 + 0x974) >> 1) * -0x55555555 & 0xffff;
  }
  iVar2 = core_globals_get();
  uVar1 = bitmap_find_next_bit(src + 1,*(undefined2 *)(iVar2 + 0x97c),uVar1 + 1 & 0xffff);
  iVar2 = core_globals_get();
  paVar3 = (aps_bind_dst_t *)0x0;
  if (uVar1 < *(ushort *)(iVar2 + 0x97c)) {
    iVar2 = core_globals_get();
    paVar3 = (aps_bind_dst_t *)(*(int *)(iVar2 + 0x974) + uVar1 * 6);
  }
  return paVar3;
}

