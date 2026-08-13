/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> hash.o -> crypto_hash_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 crypto_hash_init(int *param_1,int param_2)

{
  if (param_1 == (int *)0x0) {
    return 2;
  }
  if (param_2 == 1) {
    param_1[1] = (int)crypto_aes_mmo_hash_start;
    param_1[2] = (int)crypto_aes_mmo_hash_update;
    param_1[3] = (int)crypto_aes_mmo_hash_finish;
  }
  else {
    if (param_2 != 2) {
      return 6;
    }
    param_1[1] = (int)crypto_sha256_hash_start;
    param_1[2] = (int)crypto_sha256_hash_update;
    param_1[3] = (int)crypto_sha256_hash_finish;
  }
  *param_1 = param_2;
  return 0;
}

