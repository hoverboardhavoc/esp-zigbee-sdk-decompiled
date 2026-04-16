/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform.o -> ezb_plat_crypto_random_get
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_plat_crypto_random_get(uint8_t *output,uint16_t output_length)

{
  ezb_err_t eVar1;
  undefined2 in_register_0000202e;
  
  eVar1 = mbedtls_ctr_drbg_random
                    (&s_ctr_drbg_ctx,output,CONCAT22(in_register_0000202e,output_length));
  if (eVar1 != 0) {
    eVar1 = -1;
  }
  return eVar1;
}

