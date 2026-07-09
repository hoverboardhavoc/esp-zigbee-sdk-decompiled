/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aes.o -> crypto_aes_ecb_setkey_enc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void crypto_aes_ecb_setkey_enc(void)

{
  int iVar1;
  
  iVar1 = ezb_plat_crypto_aes_setkey_enc();
  if (iVar1 == 0) {
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/aes.c",0x35,
                "crypto_aes_ecb_setkey_enc",0x100ac);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

