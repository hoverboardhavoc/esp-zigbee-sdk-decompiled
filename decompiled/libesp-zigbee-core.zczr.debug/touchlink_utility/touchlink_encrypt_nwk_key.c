/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_encrypt_nwk_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t touchlink_encrypt_nwk_key
                  (uint8_t *decrypted_key,uint8_t *encrypted_key,uint16_t key_bitmask,
                  uint32_t transaction_id,uint32_t response_id)

{
  ushort common_bitmask;
  uint8_t uVar1;
  int iVar2;
  undefined3 extraout_var;
  uint16_t *__s;
  undefined1 *local_160;
  ezb_crypto_key_t crypto_key;
  crypto_aes_context_t aes_ctx;
  uint8_t transport_key [16];
  
  iVar2 = touchlink_device_info_get();
  common_bitmask = *(ushort *)(iVar2 + 4) & key_bitmask;
  if (encrypted_key == (uint8_t *)0x0) {
    iVar2 = 0xff;
  }
  else if (decrypted_key == (uint8_t *)0x0) {
    iVar2 = 0xff;
  }
  else if (common_bitmask == 0) {
    iVar2 = 0xff;
  }
  else {
    uVar1 = touchlink_calc_transport_key
                      ((uint8_t *)((int)aes_ctx.storage + 0x11c),common_bitmask,transaction_id,
                       response_id);
    iVar2 = CONCAT31(extraout_var,uVar1);
    if (iVar2 != 0xff) {
      __s = &crypto_key.key_len;
      memset(__s,0,0x128);
      local_160 = (undefined1 *)((int)aes_ctx.storage + 0x11c);
      crypto_key.key._0_2_ = 0x10;
      crypto_aes_ecb_init(__s);
      crypto_aes_ecb_setkey_enc(__s,&local_160);
      crypto_aes_ecb_encrypt(__s,decrypted_key,encrypted_key);
      crypto_aes_ecb_free(__s);
    }
  }
  return (uint8_t)iVar2;
}

