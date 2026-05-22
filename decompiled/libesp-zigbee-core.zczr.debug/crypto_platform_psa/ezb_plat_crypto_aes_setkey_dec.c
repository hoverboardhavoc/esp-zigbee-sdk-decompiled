/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform_psa.o -> ezb_plat_crypto_aes_setkey_dec
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_plat_crypto_aes_setkey_dec(ezb_crypto_context_t *ctx,ezb_crypto_key_t *key)

{
  void *pvVar1;
  psa_status_t psa_status;
  ezb_err_t eVar2;
  psa_key_usage_t pStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  psa_key_attributes_t attributes;
  
  if (ctx == (ezb_crypto_context_t *)0x0) {
    eVar2 = 2;
  }
  else if (ctx->ctx_size < 4) {
    eVar2 = -1;
  }
  else {
    pvVar1 = ctx->ctx;
    if (key == (ezb_crypto_key_t *)0x0) {
      eVar2 = 2;
    }
    else {
      uStack_26 = 0;
      attributes.private_type = 0;
      attributes.private_bits = 0;
      attributes.private_lifetime = 0;
      attributes.private_policy.private_alg = 0;
      attributes.private_policy.private_alg2 = 0;
      uStack_28 = 0x2400;
      attributes.private_policy.private_usage = 0x4404400;
      pStack_2c = 0x200;
      psa_extend_key_usage_flags(&pStack_2c);
      attributes.private_lifetime = pStack_2c;
      attributes.private_type = 0;
      attributes.private_bits = 0;
      attributes.private_policy.private_alg2 = 0;
      psa_status = psa_import_key(&uStack_28,key->key,key->key_len,pvVar1);
      eVar2 = psa_to_ezb_error(psa_status);
    }
  }
  return eVar2;
}

