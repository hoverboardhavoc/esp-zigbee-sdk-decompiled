/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> crc.o -> crc32_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint32_t crc32_next(uint32_t crc,uint8_t *p,uint32_t len)

{
  uint uVar1;
  uint8_t *extraout_a1;
  char *pcVar2;
  uint uVar3;
  uint in_a5;
  char *in_a6;
  
  if (p != (uint8_t *)0x0) {
    uVar1 = ~crc;
    pcVar2 = (char *)len;
    for (in_a6 = (char *)0x0; in_a6 < pcVar2; in_a6 = in_a6 + 1) {
      uVar1 = uVar1 ^ p[(int)in_a6];
      for (uVar3 = 0; uVar3 < 8; uVar3 = uVar3 + 1) {
        in_a5 = uVar1 & 1;
        if (in_a5 != 0) {
          in_a5 = 0xffffffff;
        }
_L0:
        uVar1 = uVar1 >> 1 ^ in_a5 & 0xedb88320;
      }
    }
    return ~uVar1;
  }
  uVar3 = 0x10000;
  pcVar2 = "crc32_next";
  uVar1 = __assert_func("//build/esp-zigbee/src/core/common/crc.c",0x5b);
  p = extraout_a1;
  goto _L0;
}

