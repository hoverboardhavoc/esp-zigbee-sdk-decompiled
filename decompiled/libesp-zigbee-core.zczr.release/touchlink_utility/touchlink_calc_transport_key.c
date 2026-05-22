/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  uint32_t *puStack_58;
  ezb_crypto_key_t crypto_key;
  crypto_aes_context_t aes_ctx;
  uint32_t expanded_input [4];
  uint8_t certification_key [16];
  
  uVar2 = _swap32(response_id);
  expanded_input[0] = _swap32(transaction_id);
  expanded_input[2] = uVar2;
  if ((common_bitmask & 1) == 0) {
    aes_ctx.storage[0]._4_4_ = expanded_input[0];
    expanded_input[1] = uVar2;
    memcpy(expanded_input + 3,&_L0,0x10);
    if ((common_bitmask & 0x10) == 0) {
      if (-1 < (short)common_bitmask) {
        return 0xff;
      }
      puStack_58 = expanded_input + 3;
      uVar1 = '\x0f';
    }
    else {
      iVar3 = touchlink_device_info_get();
      puStack_58 = (uint32_t *)(iVar3 + 6);
      uVar1 = '\x04';
    }
    crypto_key.key._0_2_ = 0x10;
    crypto_aes_ecb_init(&crypto_key.key_len);
    crypto_aes_ecb_setkey_enc(&crypto_key.key_len,&puStack_58);
    crypto_aes_ecb_encrypt
              (&crypto_key.key_len,(undefined1 *)((int)aes_ctx.storage + 4),transport_key);
    crypto_aes_ecb_free(&crypto_key.key_len);
  }
  else {
    aes_ctx.storage[0]._4_4_ = 0x694c6850;
    expanded_input[1] = 0x4e534c43;
    uVar1 = '\0';
    memcpy(transport_key,(void *)((int)aes_ctx.storage + 4),0x10);
  }
  return uVar1;
}

