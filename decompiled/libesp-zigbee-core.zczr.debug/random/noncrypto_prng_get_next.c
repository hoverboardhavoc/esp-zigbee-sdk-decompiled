/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> random.o -> noncrypto_prng_get_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint32_t noncrypto_prng_get_next(void)

{
  int iVar1;
  
  if ((noncrypto_prng_get_next::s_next == 0) &&
     (iVar1 = ezb_plat_crypto_entropy_get(&noncrypto_prng_get_next::s_next,4), iVar1 != 0)) {
    noncrypto_prng_get_next::s_next =
         __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/random.c",0x5b,
                       "noncrypto_prng_get_next",0x10000);
  }
  else {
    noncrypto_prng_get_next::s_next =
         (noncrypto_prng_get_next::s_next * 0x834e >> 1) +
         (int)((ulonglong)noncrypto_prng_get_next::s_next * 0x834e >> 0x20);
    if (-1 < (int)noncrypto_prng_get_next::s_next) {
      return noncrypto_prng_get_next::s_next;
    }
  }
  noncrypto_prng_get_next::s_next = (noncrypto_prng_get_next::s_next & 0x7fffffff) + 1;
  return noncrypto_prng_get_next::s_next;
}

