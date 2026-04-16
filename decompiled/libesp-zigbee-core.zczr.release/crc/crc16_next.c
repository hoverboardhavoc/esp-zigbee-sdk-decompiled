/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> crc.o -> crc16_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t crc16_next(uint16_t crc,uint8_t *p,uint32_t len)

{
  undefined2 in_register_0000202a;
  uint uVar1;
  int iVar2;
  uint32_t in_a4;
  uint in_a6;
  
  uVar1 = CONCAT22(in_register_0000202a,crc);
  if (p == (uint8_t *)0x0) {
    len = 0;
    uVar1 = __assert_func(0);
    do {
      iVar2 = 8;
      uVar1 = uVar1 ^ p[in_a4];
      do {
        iVar2 = iVar2 + -1;
        uVar1 = (-(uVar1 & 1) & in_a6 ^ uVar1 >> 1) & 0xffff;
      } while (iVar2 != 0);
      in_a4 = in_a4 + 1;
_L0:
    } while (in_a4 != len);
    return (uint16_t)uVar1;
  }
  in_a4 = 0;
  in_a6 = 0xffff8408;
  goto _L0;
}

