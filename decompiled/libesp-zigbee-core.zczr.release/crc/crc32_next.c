/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> crc.o -> crc32_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint32_t crc32_next(uint32_t crc,uint8_t *p,uint32_t len)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint8_t *in_a4;
  uint32_t in_a5;
  
  if (p == (uint8_t *)0x0) {
    uVar3 = 0;
    len = 0;
    uVar1 = __assert_func(0);
    do {
      uVar1 = uVar1 ^ in_a4[in_a5];
      iVar2 = 8;
      do {
        iVar2 = iVar2 + -1;
        uVar1 = uVar1 >> 1 ^ -(uVar1 & 1) & uVar3;
      } while (iVar2 != 0);
      in_a5 = in_a5 + 1;
_L0:
    } while (in_a5 != len);
    return ~uVar1;
  }
  uVar1 = ~crc;
  in_a5 = 0;
  uVar3 = 0xedb88320;
  in_a4 = p;
  goto _L0;
}

