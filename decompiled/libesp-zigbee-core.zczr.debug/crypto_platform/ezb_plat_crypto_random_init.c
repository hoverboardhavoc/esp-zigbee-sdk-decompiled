/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform.o -> ezb_plat_crypto_random_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void ezb_plat_crypto_random_init(void)

{
  int iVar1;
  
  mbedtls_entropy_init(&s_entropy_ctx);
  mbedtls_entropy_add_source(&s_entropy_ctx,0x10000,0,0x10,1);
  mbedtls_ctr_drbg_init(&s_ctr_drbg_ctx);
  iVar1 = mbedtls_ctr_drbg_seed(&s_ctr_drbg_ctx,&mbedtls_entropy_func,&s_entropy_ctx,0,0);
  if (iVar1 == 0) {
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/crypto/crypto_platform.c",0xa7,
                "ezb_plat_crypto_random_init",
                "(mbedtls_ctr_drbg_seed(&s_ctr_drbg_ctx, mbedtls_entropy_func, &s_entropy_ctx, ((void *)0), 0)) == 0"
               );
  mbedtls_entropy_free(&s_entropy_ctx);
  mbedtls_ctr_drbg_free(&s_ctr_drbg_ctx);
  return;
}

