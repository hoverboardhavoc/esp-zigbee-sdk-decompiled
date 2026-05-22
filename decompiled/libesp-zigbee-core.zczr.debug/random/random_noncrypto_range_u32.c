/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> random.o -> random_noncrypto_range_u32
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint32_t random_noncrypto_range_u32(uint32_t min,uint32_t max)

{
  undefined1 *puVar1;
  uint32_t uVar2;
  undefined1 *puVar3;
  uint extraout_a1;
  uint uVar4;
  
  if (min < max) {
    uVar2 = random_noncrypto_get_u32();
    return uVar2 % (max - min) + min;
  }
  puVar3 = (undefined1 *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/random.c",0x75,
                         "random_noncrypto_range_u32","min < max");
  puVar1 = puVar3;
  uVar4 = extraout_a1;
  while (uVar4 != 0) {
    puVar3 = (undefined1 *)random_noncrypto_get_u32();
    *puVar1 = (char)puVar3;
    puVar1 = puVar1 + 1;
    uVar4 = uVar4 - 1 & 0xffff;
  }
  return (uint32_t)puVar3;
}

