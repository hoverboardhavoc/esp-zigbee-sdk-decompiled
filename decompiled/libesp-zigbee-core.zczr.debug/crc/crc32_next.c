/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  uVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/crc.c",0x5b);
  p = extraout_a1;
  goto _L0;
}

