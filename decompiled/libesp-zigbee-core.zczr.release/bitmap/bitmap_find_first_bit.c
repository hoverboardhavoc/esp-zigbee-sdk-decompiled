/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> bitmap.o -> bitmap_find_first_bit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t bitmap_find_first_bit(bitmap_t *map,uint16_t nbit)

{
  uint uVar1;
  int iVar2;
  undefined2 in_register_0000202e;
  uint uVar3;
  
  uVar1 = CONCAT22(in_register_0000202e,nbit);
  uVar3 = 0;
  do {
    if (uVar1 <= uVar3 * 8) {
_L0:
      return (uint16_t)uVar1;
    }
    if (map[uVar3] != '\0') {
      iVar2 = __ctzsi2();
      uVar3 = iVar2 + uVar3 * 8;
      if (uVar1 < uVar3) {
        uVar3 = uVar1;
      }
      uVar1 = uVar3 & 0xffff;
      goto _L0;
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while( true );
}

