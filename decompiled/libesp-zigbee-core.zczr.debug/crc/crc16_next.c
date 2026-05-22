/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> crc.o -> crc16_next
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
  uint8_t *extraout_a1;
  char *pcVar2;
  uint32_t i;
  char *pcVar3;
  uint in_a5;
  
  uVar1 = CONCAT22(in_register_0000202a,crc);
  if (p != (uint8_t *)0x0) {
    pcVar2 = (char *)len;
    for (pcVar3 = (char *)0x0; pcVar3 < pcVar2; pcVar3 = pcVar3 + 1) {
      uVar1 = uVar1 ^ p[(int)pcVar3];
      for (in_a5 = 0; in_a5 < 8; in_a5 = in_a5 + 1) {
        if ((uVar1 & 1) == 0) {
_L0:
          uVar1 = uVar1 >> 1;
        }
        else {
          uVar1 = (uVar1 >> 1 ^ 0xffff8408) & 0xffff;
        }
      }
    }
    return (uint16_t)uVar1;
  }
  pcVar3 = "p != ((void *)0)";
  pcVar2 = "crc16_next";
  uVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/common/crc.c",0x3b);
  p = extraout_a1;
  goto _L0;
}

