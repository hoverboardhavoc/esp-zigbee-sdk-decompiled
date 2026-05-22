/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> aes_ccm.o -> crypto_psa_import_aes_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

psa_status_t
crypto_psa_import_aes_key
          (uint8_t *key,psa_algorithm_t alg,psa_key_usage_t usage,psa_key_id_t *key_id)

{
  psa_status_t pVar1;
  psa_key_usage_t pStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  psa_key_attributes_t attributes;
  
  uStack_26 = 0;
  attributes.private_type = 0;
  attributes.private_bits = 0;
  attributes.private_lifetime = 0;
  attributes.private_policy.private_alg = 0;
  attributes.private_policy.private_alg2 = 0;
  uStack_28 = 0x2400;
  pStack_2c = usage;
  attributes.private_policy.private_usage = alg;
  psa_extend_key_usage_flags(&pStack_2c);
  attributes.private_lifetime = pStack_2c;
  attributes.private_type = 0;
  attributes.private_bits = 0;
  attributes.private_policy.private_alg2 = 0;
  pVar1 = psa_import_key(&uStack_28,key,0x10,key_id);
  return pVar1;
}

