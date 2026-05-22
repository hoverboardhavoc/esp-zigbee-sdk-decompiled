/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform_psa.o -> ezb_plat_crypto_aes_encrypt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_plat_crypto_aes_encrypt(ezb_crypto_context_t *ctx,uint8_t *input,uint8_t *output)

{
  psa_status_t psa_status;
  ezb_err_t eVar1;
  undefined1 auStack_14 [4];
  size_t cipher_len;
  
  if (ctx == (ezb_crypto_context_t *)0x0) {
    eVar1 = 2;
  }
  else if (ctx->ctx_size < 4) {
    eVar1 = -1;
  }
  else if (input == (uint8_t *)0x0) {
    eVar1 = 2;
  }
  else if (output == (uint8_t *)0x0) {
    eVar1 = 2;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    psa_status = psa_cipher_encrypt(*ctx->ctx,0x4404400,input,0x10,output,auStack_14);
    eVar1 = psa_to_ezb_error(psa_status);
  }
  return eVar1;
}

