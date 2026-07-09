/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> random.o -> random_noncrypto_range_u32
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * random_noncrypto_range_u32(uint param_1,uint param_2)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint extraout_a1;
  
  if (param_1 < param_2) {
    uVar2 = random_noncrypto_get_u32();
    return (undefined1 *)(uVar2 % (param_2 - param_1) + param_1);
  }
  puVar3 = (undefined1 *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/random.c",0x75,
                         "random_noncrypto_range_u32","min < max");
  puVar1 = puVar3;
  uVar2 = extraout_a1;
  while( true ) {
    if (uVar2 == 0) break;
    puVar3 = (undefined1 *)random_noncrypto_get_u32();
    *puVar1 = (char)puVar3;
    puVar1 = puVar1 + 1;
    uVar2 = uVar2 - 1 & 0xffff;
  }
  return puVar3;
}

