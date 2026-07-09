/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> hash.o -> crypto_hmac_aes_mmo
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_hmac_aes_mmo(void *param_1,uint param_2,int param_3,uint param_4,undefined4 param_5)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  byte *__s;
  byte local_50 [32];
  undefined1 auStack_30 [16];
  
  pbVar4 = local_50;
  __s = local_50 + 0x10;
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
  memset(__s,0,0x20);
  if (param_2 < 0x11) {
    memcpy(local_50,param_1,param_2);
  }
  else {
    crypto_aes_mmo_hash(param_1,param_2,local_50);
  }
  iVar5 = 0;
  do {
    bVar1 = *pbVar4;
    pbVar3 = __s + iVar5;
    iVar5 = iVar5 + 1;
    *pbVar4 = bVar1 ^ 0x36;
    *pbVar3 = bVar1 ^ 0x5c;
    pbVar4 = pbVar4 + 1;
  } while (iVar5 != 0x10);
  aes_mmo_hash_core(local_50,auStack_30);
  uVar2 = 0;
  while( true ) {
    iVar5 = param_3 + uVar2;
    uVar2 = uVar2 + 0x10;
    if (param_4 < uVar2) break;
    aes_mmo_hash_core(iVar5,auStack_30);
  }
  aes_mmo_hash_tail(param_4 + 0x10,auStack_30);
  crypto_aes_mmo_hash(__s,0x20,param_5);
  return;
}

