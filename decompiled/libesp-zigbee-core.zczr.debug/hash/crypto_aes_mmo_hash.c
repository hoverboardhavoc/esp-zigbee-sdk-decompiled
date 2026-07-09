/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> hash.o -> crypto_aes_mmo_hash
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 crypto_aes_mmo_hash(int param_1,uint param_2,void *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (param_2 < 0x20000000) {
    memset(param_3,0,0x10);
    uVar1 = 0;
    while (uVar1 + 0x10 <= param_2) {
      aes_mmo_hash_core(uVar1 + param_1,param_3);
      uVar1 = uVar1 + 0x10;
    }
    aes_mmo_hash_tail(uVar1 + param_1,param_2,param_3);
    uVar2 = 0;
  }
  else {
    uVar2 = 2;
  }
  return uVar2;
}

