/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> hash.o -> crypto_hmac_aes_mmo
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_hmac_aes_mmo(void *param_1,uint param_2,int param_3,uint param_4,undefined4 param_5)

{
  uint uVar1;
  byte local_50 [16];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  byte abStack_30 [28];
  
  abStack_30[0] = 0;
  abStack_30[1] = 0;
  abStack_30[2] = 0;
  abStack_30[3] = 0;
  abStack_30[4] = 0;
  abStack_30[5] = 0;
  abStack_30[6] = 0;
  abStack_30[7] = 0;
  abStack_30[8] = 0;
  abStack_30[9] = 0;
  abStack_30[10] = 0;
  abStack_30[0xb] = 0;
  abStack_30[0xc] = 0;
  abStack_30[0xd] = 0;
  abStack_30[0xe] = 0;
  abStack_30[0xf] = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_50[2] = 0;
  local_50[3] = 0;
  local_50[4] = 0;
  local_50[5] = 0;
  local_50[6] = 0;
  local_50[7] = 0;
  local_50[8] = 0;
  local_50[9] = 0;
  local_50[10] = 0;
  local_50[0xb] = 0;
  local_50[0xc] = 0;
  local_50[0xd] = 0;
  local_50[0xe] = 0;
  local_50[0xf] = 0;
  uStack_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  if (param_2 < 0x11) {
    memcpy(abStack_30,param_1,param_2);
  }
  else {
    crypto_aes_mmo_hash(abStack_30);
  }
  for (uVar1 = 0; uVar1 < 0x10; uVar1 = uVar1 + 1) {
    local_50[uVar1] = abStack_30[uVar1] ^ 0x5c;
    abStack_30[uVar1] = abStack_30[uVar1] ^ 0x36;
  }
  aes_mmo_hash_core(abStack_30,&uStack_40);
  uVar1 = 0;
  while (uVar1 + 0x10 <= param_4) {
    aes_mmo_hash_core(uVar1 + param_3,&uStack_40);
    uVar1 = uVar1 + 0x10;
  }
  aes_mmo_hash_tail(uVar1 + param_3,param_4 + 0x10,&uStack_40);
  crypto_aes_mmo_hash(local_50,0x20,param_5);
  return;
}

