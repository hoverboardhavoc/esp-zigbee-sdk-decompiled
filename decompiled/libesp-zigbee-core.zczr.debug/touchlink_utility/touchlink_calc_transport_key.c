/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_calc_transport_key
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
  uint16_t *puVar1;
  uint8_t uVar2;
  int iVar3;
  undefined1 *puStack_58;
  ezb_crypto_key_t crypto_key;
  crypto_aes_context_t aes_ctx;
  uint8_t certification_key [16];
  uint32_t expanded_input [4];
  
  certification_key[0xc] = '\0';
  certification_key[0xd] = '\0';
  certification_key[0xe] = '\0';
  certification_key[0xf] = '\0';
  expanded_input[0] = 0;
  expanded_input[1] = 0;
  expanded_input[2] = 0;
  if ((common_bitmask & 1) == 0) {
    write_be32(transaction_id,certification_key + 0xc);
    write_be32(transaction_id,(uint8_t *)expanded_input);
    write_be32(response_id,(uint8_t *)(expanded_input + 1));
    write_be32(response_id,(uint8_t *)(expanded_input + 2));
    aes_ctx.storage[0]._4_4_ = 0xc3c2c1c0;
    certification_key[0] = 0xc4;
    certification_key[1] = 0xc5;
    certification_key[2] = 0xc6;
    certification_key[3] = 199;
    certification_key[4] = 200;
    certification_key[5] = 0xc9;
    certification_key[6] = 0xca;
    certification_key[7] = 0xcb;
    certification_key[8] = 0xcc;
    certification_key[9] = 0xcd;
    certification_key[10] = 0xce;
    certification_key[0xb] = 0xcf;
    if ((common_bitmask & 0x10) == 0) {
      if (-1 < (short)common_bitmask) {
        return 0xff;
      }
      puStack_58 = (undefined1 *)((int)aes_ctx.storage + 4);
      uVar2 = '\x0f';
    }
    else {
      iVar3 = touchlink_device_info_get();
      puStack_58 = (undefined1 *)(iVar3 + 6);
      uVar2 = '\x04';
    }
    crypto_key.key._0_2_ = 0x10;
    puVar1 = &crypto_key.key_len;
    crypto_aes_ecb_init(puVar1);
    crypto_aes_ecb_setkey_enc(puVar1,&puStack_58);
    crypto_aes_ecb_encrypt(puVar1,certification_key + 0xc,transport_key);
    crypto_aes_ecb_free(puVar1);
  }
  else {
    write_be32(0x50684c69,certification_key + 0xc);
    write_be32(transaction_id,(uint8_t *)expanded_input);
    write_be32(0x434c534e,(uint8_t *)(expanded_input + 1));
    write_be32(response_id,(uint8_t *)(expanded_input + 2));
    memcpy(transport_key,certification_key + 0xc,0x10);
    uVar2 = '\0';
  }
  return uVar2;
}

