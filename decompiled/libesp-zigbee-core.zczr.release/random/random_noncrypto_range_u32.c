/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> random.o -> random_noncrypto_range_u32
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int random_noncrypto_range_u32(uint param_1,uint param_2)

{
  uint uVar1;
  uint extraout_a1;
  
  if (param_2 <= param_1) {
    param_1 = __assert_func(0,0,0,0);
    param_2 = extraout_a1;
  }
  uVar1 = noncrypto_prng_get_next();
  return uVar1 % (param_2 - param_1) + param_1;
}

