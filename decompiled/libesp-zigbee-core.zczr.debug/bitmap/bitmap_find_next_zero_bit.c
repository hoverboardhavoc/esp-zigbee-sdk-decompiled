/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> bitmap.o -> bitmap_find_next_zero_bit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t bitmap_find_next_zero_bit(bitmap_t *map,uint16_t nbit,uint16_t pos)

{
  uint uVar1;
  int iVar2;
  undefined2 in_register_0000202e;
  undefined2 in_register_00002032;
  uint uVar3;
  uint uVar4;
  
  uVar1 = CONCAT22(in_register_0000202e,nbit);
  if (CONCAT22(in_register_00002032,pos) < uVar1) {
    uVar3 = CONCAT22(in_register_00002032,pos) >> 3;
    uVar4 = ~(uint)map[uVar3] & -1 << (pos & 7);
    while ((uVar4 & 0xff) == 0) {
      if (uVar1 <= (uVar3 + 1) * 8) goto _L0;
      uVar3 = uVar3 + 1 & 0xffff;
      uVar4 = ~(uint)map[uVar3];
    }
    iVar2 = __ctzsi2();
    uVar4 = uVar3 * 8 + iVar2;
    if (uVar4 < uVar1) {
      uVar1 = uVar4;
    }
    uVar1 = uVar1 & 0xffff;
  }
_L0:
  return (uint16_t)uVar1;
}

