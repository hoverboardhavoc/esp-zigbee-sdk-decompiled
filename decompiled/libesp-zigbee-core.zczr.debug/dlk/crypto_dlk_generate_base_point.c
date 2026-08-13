/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> dlk.o -> crypto_dlk_generate_base_point
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
crypto_dlk_generate_base_point
          (uint param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4,
          undefined1 *param_5)

{
  undefined4 uVar1;
  
  if ((param_1 & 0x60) == 0x20) {
    if ((param_1 & 0x1c) == 4) {
      if ((param_1 & 3) == 1) {
        crypto_aes_mmo_hash(param_2,param_3,param_4);
        memcpy(param_4 + 0x10,param_4,0x10);
      }
      else {
        if ((param_1 & 3) != 2) {
          return 6;
        }
        crypto_sha256_hash(param_4);
        *param_4 = 9;
      }
      *param_5 = 0x20;
      uVar1 = 0;
    }
    else {
      uVar1 = 6;
    }
  }
  else {
    uVar1 = 6;
  }
  return uVar1;
}

