/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> aes_ccm.o -> crypto_psa_import_aes_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: attributes */
/* WARNING: Unknown calling convention */

psa_status_t
crypto_psa_import_aes_key
          (uint8_t *key,psa_algorithm_t alg,psa_key_usage_t usage,psa_key_id_t *key_id)

{
  psa_status_t pVar1;
  undefined2 uStack_28;
  undefined1 auStack_26 [2];
  psa_key_attributes_t attributes;
  
  memset(auStack_26,0,0x16);
  uStack_28 = 0x2400;
  attributes.private_lifetime = usage;
  attributes.private_policy.private_usage = alg;
  pVar1 = psa_import_key(&uStack_28,key,0x10,key_id);
  return pVar1;
}

