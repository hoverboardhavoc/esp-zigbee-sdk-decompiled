/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> hash.o -> aes_mmo_hash_core
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: aes */
/* WARNING: Unknown calling convention */

void aes_mmo_hash_core(uint8_t *data,uint8_t *hash)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  uint8_t *puStack_28;
  ezb_crypto_key_t key;
  crypto_aes_context_t aes;
  
  key.key._0_2_ = 0x10;
  puStack_28 = hash;
  crypto_aes_ecb_init(&key.key_len);
  crypto_aes_ecb_setkey_enc(&key.key_len,&puStack_28);
  crypto_aes_ecb_encrypt(&key.key_len,data,hash);
  crypto_aes_ecb_free(&key.key_len);
  iVar3 = 0;
  do {
    pbVar1 = hash + iVar3;
    pbVar2 = data + iVar3;
    iVar3 = iVar3 + 1;
    *pbVar1 = *pbVar2 ^ *pbVar1;
  } while (iVar3 != 0x10);
  return;
}

