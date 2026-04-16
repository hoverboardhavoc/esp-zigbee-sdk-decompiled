/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aes.o -> crypto_aes_ecb_setkey_dec
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void crypto_aes_ecb_setkey_dec(crypto_aes_context_t *ctx,ezb_crypto_key_t *key)

{
  int iVar1;
  
  iVar1 = ezb_plat_crypto_aes_setkey_dec();
  if (iVar1 != 0) {
    __assert_func(0,0,0,0);
  }
  return;
}

