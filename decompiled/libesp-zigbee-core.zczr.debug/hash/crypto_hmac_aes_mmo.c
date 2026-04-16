/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> hash.o -> crypto_hmac_aes_mmo
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void crypto_hmac_aes_mmo(uint8_t *key,uint32_t key_len,uint8_t *input,uint32_t input_len,
                        uint8_t *output)

{
  byte bVar1;
  uint uVar2;
  byte local_50 [4];
  uint8_t msg2 [32];
  uint8_t key0 [16];
  
  msg2[0x1c] = '\0';
  msg2[0x1d] = '\0';
  msg2[0x1e] = '\0';
  msg2[0x1f] = '\0';
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  msg2[0] = '\0';
  msg2[1] = '\0';
  msg2[2] = '\0';
  msg2[3] = '\0';
  msg2[4] = '\0';
  msg2[5] = '\0';
  msg2[6] = '\0';
  msg2[7] = '\0';
  msg2[8] = '\0';
  msg2[9] = '\0';
  msg2[10] = '\0';
  msg2[0xb] = '\0';
  msg2[0xc] = '\0';
  msg2[0xd] = '\0';
  msg2[0xe] = '\0';
  msg2[0xf] = '\0';
  msg2[0x10] = '\0';
  msg2[0x11] = '\0';
  msg2[0x12] = '\0';
  msg2[0x13] = '\0';
  msg2[0x14] = '\0';
  msg2[0x15] = '\0';
  msg2[0x16] = '\0';
  msg2[0x17] = '\0';
  msg2[0x18] = '\0';
  msg2[0x19] = '\0';
  msg2[0x1a] = '\0';
  msg2[0x1b] = '\0';
  if (key_len < 0x11) {
    memcpy(msg2 + 0x1c,key,key_len);
  }
  else {
    crypto_aes_mmo_hash(key,key_len,msg2 + 0x1c);
  }
  for (uVar2 = 0; uVar2 < 0x10; uVar2 = uVar2 + 1) {
    bVar1 = msg2[uVar2 + 0x1c];
    msg2[uVar2 - 4] = bVar1 ^ 0x5c;
    msg2[uVar2 + 0x1c] = bVar1 ^ 0x36;
  }
  aes_mmo_hash_core(msg2 + 0x1c,msg2 + 0xc);
  uVar2 = 0;
  while (uVar2 + 0x10 <= input_len) {
    aes_mmo_hash_core(input + uVar2,msg2 + 0xc);
    uVar2 = uVar2 + 0x10;
  }
  aes_mmo_hash_tail(input + uVar2,input_len + 0x10,msg2 + 0xc);
  crypto_aes_mmo_hash(local_50,0x20,output);
  return;
}

