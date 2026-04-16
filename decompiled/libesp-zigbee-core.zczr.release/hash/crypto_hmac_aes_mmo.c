/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> hash.o -> crypto_hmac_aes_mmo
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: msg2 */
/* WARNING: Unknown calling convention */

void crypto_hmac_aes_mmo(uint8_t *key,uint32_t key_len,uint8_t *input,uint32_t input_len,
                        uint8_t *output)

{
  byte bVar1;
  uint uVar2;
  uint8_t *data;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  uint8_t *input_00;
  byte local_50 [4];
  uint8_t key0 [16];
  uint8_t msg2 [32];
  
  pbVar4 = local_50;
  input_00 = key0 + 0xc;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  key0[0] = '\0';
  key0[1] = '\0';
  key0[2] = '\0';
  key0[3] = '\0';
  key0[4] = '\0';
  key0[5] = '\0';
  key0[6] = '\0';
  key0[7] = '\0';
  key0[8] = '\0';
  key0[9] = '\0';
  key0[10] = '\0';
  key0[0xb] = '\0';
  memset(input_00,0,0x20);
  if (key_len < 0x11) {
    memcpy(local_50,key,key_len);
  }
  else {
    crypto_aes_mmo_hash(key,key_len,local_50);
  }
  iVar5 = 0;
  do {
    bVar1 = *pbVar4;
    pbVar3 = input_00 + iVar5;
    iVar5 = iVar5 + 1;
    *pbVar4 = bVar1 ^ 0x36;
    *pbVar3 = bVar1 ^ 0x5c;
    pbVar4 = pbVar4 + 1;
  } while (iVar5 != 0x10);
  aes_mmo_hash_core(local_50,msg2 + 0xc);
  uVar2 = 0;
  while( true ) {
    data = input + uVar2;
    uVar2 = uVar2 + 0x10;
    if (input_len < uVar2) break;
    aes_mmo_hash_core(data,msg2 + 0xc);
  }
  aes_mmo_hash_tail(data,input_len + 0x10,msg2 + 0xc);
  crypto_aes_mmo_hash(input_00,0x20,output);
  return;
}

