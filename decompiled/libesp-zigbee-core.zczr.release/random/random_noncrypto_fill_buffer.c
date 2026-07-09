/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> random.o -> random_noncrypto_fill_buffer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void random_noncrypto_fill_buffer(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  
  puVar2 = param_1 + param_2;
  for (; ((uint)puVar2 & 0xffff) != ((uint)param_1 & 0xffff); param_1 = param_1 + 1) {
    uVar1 = noncrypto_prng_get_next();
    *param_1 = uVar1;
  }
  return;
}

