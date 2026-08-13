/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> hash.o -> crypto_aes_mmo_hash
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_aes_mmo_hash(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 auStack_48 [38];
  undefined2 auStack_22 [7];
  
  crypto_aes_mmo_hash_start(auStack_48);
  crypto_aes_mmo_hash_update(auStack_48,param_1,param_2);
  auStack_22[0] = 0;
  crypto_aes_mmo_hash_finish(auStack_48,param_3,0x10,auStack_22);
  return;
}

