/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_calc_transport_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t touchlink_calc_transport_key
                  (uint8_t *transport_key,uint16_t common_bitmask,uint32_t transaction_id,
                  uint32_t response_id)

{
  uint8_t uVar1;
  uint32_t uVar2;
  int iVar3;
  uint32_t *local_170;
  ezb_crypto_key_t crypto_key;
  uint32_t expanded_input [4];
  uint8_t certification_key [16];
  crypto_aes_context_t aes_ctx;
  
  uVar2 = _swap32(response_id);
  expanded_input[0] = _swap32(transaction_id);
  expanded_input[2] = uVar2;
  if ((common_bitmask & 1) == 0) {
    crypto_key._4_4_ = expanded_input[0];
    expanded_input[1] = uVar2;
    memcpy(expanded_input + 3,&_L0,0x10);
    if ((common_bitmask & 0x10) == 0) {
      if (-1 < (short)common_bitmask) {
        return 0xff;
      }
      local_170 = expanded_input + 3;
      uVar1 = '\x0f';
    }
    else {
      iVar3 = touchlink_device_info_get();
      local_170 = (uint32_t *)(iVar3 + 6);
      uVar1 = '\x04';
    }
    crypto_key.key._0_2_ = 0x10;
    crypto_aes_ecb_init(certification_key + 0xc);
    crypto_aes_ecb_setkey_enc(certification_key + 0xc,&local_170);
    crypto_aes_ecb_encrypt(certification_key + 0xc,&crypto_key.key_len,transport_key);
    crypto_aes_ecb_free(certification_key + 0xc);
  }
  else {
    crypto_key.key_len = 0x6850;
    crypto_key._6_2_ = 0x694c;
    expanded_input[1] = 0x4e534c43;
    uVar1 = '\0';
    memcpy(transport_key,&crypto_key.key_len,0x10);
  }
  return uVar1;
}

