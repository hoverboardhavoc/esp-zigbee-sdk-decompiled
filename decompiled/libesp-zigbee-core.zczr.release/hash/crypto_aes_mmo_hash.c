/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> hash.o -> crypto_aes_mmo_hash
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 crypto_aes_mmo_hash(int param_1,uint param_2,void *param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 < 0x20000000) {
    uVar2 = 0;
    memset(param_3,0,0x10);
    while( true ) {
      iVar1 = uVar2 + param_1;
      uVar2 = uVar2 + 0x10;
      if (param_2 < uVar2) break;
      aes_mmo_hash_core(iVar1,param_3);
    }
    aes_mmo_hash_tail((param_2 & 0xfffffff0) + param_1,param_2,param_3);
    return 0;
  }
  return 2;
}

