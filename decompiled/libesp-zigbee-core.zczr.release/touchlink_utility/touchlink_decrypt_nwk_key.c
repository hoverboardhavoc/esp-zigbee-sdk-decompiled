/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_decrypt_nwk_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t touchlink_decrypt_nwk_key
                  (uint8_t *encrypted_key,uint8_t *decrypted_key,uint16_t key_bitmask,
                  uint32_t transaction_id,uint32_t response_id)

{
  ushort common_bitmask;
  uint8_t uVar1;
  int iVar2;
  undefined3 extraout_var;
  uint8_t *transport_key_00;
  uint8_t *puStack_48;
  ezb_crypto_key_t crypto_key;
  crypto_aes_context_t aes_ctx;
  uint8_t transport_key [16];
  
  iVar2 = touchlink_device_info_get();
  common_bitmask = key_bitmask & *(ushort *)(iVar2 + 4);
  iVar2 = 0xff;
  if (((encrypted_key != (uint8_t *)0x0) && (decrypted_key != (uint8_t *)0x0)) &&
     (common_bitmask != 0)) {
    transport_key_00 = (uint8_t *)((int)aes_ctx.storage + 4);
    uVar1 = touchlink_calc_transport_key(transport_key_00,common_bitmask,transaction_id,response_id)
    ;
    iVar2 = CONCAT31(extraout_var,uVar1);
    if (iVar2 != 0xff) {
      crypto_key.key._0_2_ = 0x10;
      puStack_48 = transport_key_00;
      crypto_aes_ecb_init(&crypto_key.key_len);
      crypto_aes_ecb_setkey_dec(&crypto_key.key_len,&puStack_48);
      crypto_aes_ecb_decrypt(&crypto_key.key_len,encrypted_key,decrypted_key);
      crypto_aes_ecb_free(&crypto_key.key_len);
    }
  }
  return (uint8_t)iVar2;
}

