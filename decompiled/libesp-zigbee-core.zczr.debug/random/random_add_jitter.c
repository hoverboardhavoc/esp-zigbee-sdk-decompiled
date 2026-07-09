/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> random.o -> random_add_jitter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint random_add_jitter(uint param_1,uint param_2)

{
  int iVar1;
  
  if (param_1 != 0xffffffff) {
    if (~param_1 < param_2) {
      param_2 = ~param_1;
    }
    param_2 = param_2 & 0xffff;
    if (0xfffe < param_2) {
      param_2 = 0xfffffffe;
    }
    iVar1 = random_noncrypto_range_u32(0,(param_2 & 0xffff) + 1);
    param_1 = iVar1 + param_1;
  }
  return param_1;
}

