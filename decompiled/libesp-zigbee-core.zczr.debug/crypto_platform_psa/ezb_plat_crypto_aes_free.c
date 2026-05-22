/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform_psa.o -> ezb_plat_crypto_aes_free
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_plat_crypto_aes_free(ezb_crypto_context_t *ctx)

{
  undefined4 *puVar1;
  psa_status_t psa_status;
  ezb_err_t eVar2;
  
  if (ctx == (ezb_crypto_context_t *)0x0) {
    eVar2 = 2;
  }
  else if (ctx->ctx_size < 4) {
    eVar2 = -1;
  }
  else {
    puVar1 = (undefined4 *)ctx->ctx;
    psa_status = psa_destroy_key(*puVar1);
    eVar2 = psa_to_ezb_error(psa_status);
    *puVar1 = 0;
  }
  return eVar2;
}

