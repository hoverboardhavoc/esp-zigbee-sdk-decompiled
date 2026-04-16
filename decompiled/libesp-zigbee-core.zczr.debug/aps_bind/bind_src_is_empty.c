/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_src_is_empty
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool bind_src_is_empty(aps_bind_src_t *src)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = core_globals_get();
  uVar1 = *(ushort *)(iVar2 + 0x97c);
  uVar3 = bitmap_find_first_bit(src + 1,(uint)uVar1);
  return uVar1 <= uVar3;
}

