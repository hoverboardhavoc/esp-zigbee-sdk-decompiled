/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> crypto_platform_psa.o -> ezb_plat_crypto_aes_setkey_enc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_plat_crypto_aes_setkey_enc(ezb_crypto_context_t *ctx,ezb_crypto_key_t *key)

{
  psa_status_t psa_status;
  ezb_err_t eVar1;
  void *pvVar2;
  undefined2 uStack_28;
  undefined1 auStack_26 [2];
  psa_key_attributes_t attributes;
  
  if (ctx == (ezb_crypto_context_t *)0x0) {
    return 2;
  }
  if (3 < ctx->ctx_size) {
    if (key != (ezb_crypto_key_t *)0x0) {
      pvVar2 = ctx->ctx;
      memset(auStack_26,0,0x16);
      uStack_28 = 0x2400;
      attributes.private_policy.private_usage = 0x4404400;
      attributes.private_lifetime = 0x100;
      psa_status = psa_import_key(&uStack_28,key->key,key->key_len,pvVar2);
      eVar1 = psa_to_ezb_error(psa_status);
      return eVar1;
    }
    return 2;
  }
  return -1;
}

