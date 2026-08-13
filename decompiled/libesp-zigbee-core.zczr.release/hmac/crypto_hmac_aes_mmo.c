/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> hmac.o -> crypto_hmac_aes_mmo
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_hmac_aes_mmo(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  undefined *puStack_40;
  undefined *puStack_3c;
  undefined *puStack_38;
  undefined1 auStack_34 [48];
  
  puStack_40 = &crypto_aes_mmo_hash_start;
  puStack_3c = &crypto_aes_mmo_hash_update;
  puStack_38 = &crypto_aes_mmo_hash_finish;
  crypto_hmac_core(&puStack_40,auStack_34,0x10,param_1,param_2,param_3,param_4);
  return;
}

