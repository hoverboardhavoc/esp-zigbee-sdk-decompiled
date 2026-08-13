/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> hash.o -> crypto_aes_mmo_hash
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_aes_mmo_hash(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 auStack_36 [2];
  undefined1 auStack_34 [36];
  
  crypto_aes_mmo_hash_start(auStack_34);
  crypto_aes_mmo_hash_update(auStack_34,param_1,param_2);
  crypto_aes_mmo_hash_finish(auStack_34,param_3,0x10,auStack_36);
  return;
}

