/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aes.o -> crypto_aes_ecb_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void crypto_aes_ecb_init(crypto_aes_context_t *ctx)

{
  int iVar1;
  
  (ctx->context).ctx = ctx->storage;
  (ctx->context).ctx_size = 0x120;
  iVar1 = ezb_plat_crypto_aes_init();
  if (iVar1 != 0) {
    __assert_func(0,0,0,0);
  }
  return;
}

