/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bitmap.o -> bitmap_find_next_bit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t bitmap_find_next_bit(bitmap_t *map,uint16_t nbit,uint16_t pos)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined2 in_register_0000202e;
  undefined2 in_register_00002032;
  
  uVar2 = CONCAT22(in_register_0000202e,nbit);
  if (CONCAT22(in_register_00002032,pos) < uVar2) {
    uVar1 = CONCAT22(in_register_00002032,pos) >> 3;
    uVar3 = (uint)map[uVar1] & -1 << (pos & 7);
    while (uVar3 == 0) {
      if (uVar2 <= (uVar1 + 1) * 8) goto _L0;
      uVar1 = uVar1 + 1 & 0xffff;
      uVar3 = (uint)map[uVar1];
    }
    iVar4 = __ctzsi2();
    uVar1 = uVar1 * 8 + iVar4;
    if (uVar2 < uVar1) {
      uVar1 = uVar2;
    }
    uVar2 = uVar1 & 0xffff;
  }
_L0:
  return (uint16_t)uVar2;
}

