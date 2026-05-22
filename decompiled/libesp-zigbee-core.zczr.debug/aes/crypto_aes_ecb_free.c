/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aes.o -> crypto_aes_ecb_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void crypto_aes_ecb_free(crypto_aes_context_t *ctx)

{
  uint in_t2;
  int iVar1;
  uint unaff_s2;
  
  iVar1 = ezb_plat_crypto_aes_free();
  if (iVar1 == 0) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/aes.c",0x49,"crypto_aes_ecb_free"
                ,0x1027c);
  if (unaff_s2 < in_t2) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

