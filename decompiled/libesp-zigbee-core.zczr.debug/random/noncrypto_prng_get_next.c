/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> random.o -> noncrypto_prng_get_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void noncrypto_prng_get_next(void)

{
  int iVar1;
  
  if ((s_next_3 == 0) && (iVar1 = ezb_plat_crypto_entropy_get(&s_next_3,4), iVar1 != 0)) {
    s_next_3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/random.c",0x5b,
                             "noncrypto_prng_get_next",0x10000);
  }
  else {
    s_next_3 = (s_next_3 * 0x834e >> 1) + (int)((ulonglong)s_next_3 * 0x834e >> 0x20);
    if (-1 < (int)s_next_3) {
      return;
    }
  }
  s_next_3 = (s_next_3 & 0x7fffffff) + 1;
  return;
}

