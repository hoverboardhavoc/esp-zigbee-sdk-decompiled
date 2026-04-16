/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform.o -> ezb_plat_crypto_aes_setkey_dec
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_plat_crypto_aes_setkey_dec(ezb_crypto_context_t *ctx,ezb_crypto_key_t *key)

{
  ezb_err_t eVar1;
  
  if (ctx == (ezb_crypto_context_t *)0x0) {
    eVar1 = 2;
  }
  else if (ctx->ctx_size < 0x118) {
    eVar1 = -1;
  }
  else {
    eVar1 = mbedtls_aes_setkey_dec(ctx->ctx,key->key,(uint)key->key_len << 3);
    if (eVar1 != 0) {
      eVar1 = -1;
    }
  }
  return eVar1;
}

