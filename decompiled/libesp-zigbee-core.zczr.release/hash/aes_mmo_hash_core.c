/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> hash.o -> aes_mmo_hash_core
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aes_mmo_hash_core(int param_1,int param_2)

{
  byte *pbVar1;
  byte *pbVar2;
  int iVar3;
  int iStack_28;
  undefined2 uStack_24;
  undefined1 auStack_20 [16];
  
  uStack_24 = 0x10;
  iStack_28 = param_2;
  crypto_aes_ecb_init(auStack_20);
  crypto_aes_ecb_setkey_enc(auStack_20,&iStack_28);
  crypto_aes_ecb_encrypt(auStack_20,param_1,param_2);
  crypto_aes_ecb_free(auStack_20);
  iVar3 = 0;
  do {
    pbVar1 = (byte *)(param_2 + iVar3);
    pbVar2 = (byte *)(param_1 + iVar3);
    iVar3 = iVar3 + 1;
    *pbVar1 = *pbVar2 ^ *pbVar1;
  } while (iVar3 != 0x10);
  return;
}

