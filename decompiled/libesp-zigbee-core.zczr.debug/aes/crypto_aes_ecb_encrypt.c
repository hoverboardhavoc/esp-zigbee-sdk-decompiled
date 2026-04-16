/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aes.o -> crypto_aes_ecb_encrypt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Unknown calling convention */

void crypto_aes_ecb_encrypt(crypto_aes_context_t *ctx,uint8_t *in,uint8_t *out)

{
  int iVar1;
  
  iVar1 = ezb_plat_crypto_aes_encrypt();
  if (iVar1 == 0) {
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/crypto/aes.c",0x3f,"crypto_aes_ecb_encrypt",
                "(ezb_plat_crypto_aes_encrypt(&ctx->context, in, out)) == 0");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

