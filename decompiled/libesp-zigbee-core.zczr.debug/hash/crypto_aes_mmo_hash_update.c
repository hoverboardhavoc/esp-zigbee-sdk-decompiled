/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> hash.o -> crypto_aes_mmo_hash_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_aes_mmo_hash_update(uint *param_1,undefined1 *param_2,uint param_3,uint param_4)

{
  if (param_1 == (uint *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/hash.c",0xad,
                  "crypto_aes_mmo_hash_update","ctx != ((void *)0)");
  }
  else {
    if (param_2 == (undefined1 *)0x0) {
      return;
    }
    if (param_3 == 0) {
      return;
    }
    param_4 = *param_1 & 0xf;
    *param_1 = *param_1 + param_3;
    if (param_4 == 0) goto _L0;
    for (; (param_3 != 0 && (param_4 < 0x10)); param_4 = param_4 + 1 & 0xff) {
      *(undefined1 *)((int)param_1 + param_4 + 0x14) = *param_2;
      param_3 = param_3 - 1 & 0xffff;
      param_2 = param_2 + 1;
    }
  }
  if (param_4 == 0x10) {
    aes_mmo_hash_core(param_1 + 5,param_1 + 1);
  }
_L0:
  for (; 0xf < param_3; param_3 = param_3 - 0x10 & 0xffff) {
    aes_mmo_hash_core(param_2,param_1 + 1);
    param_2 = param_2 + 0x10;
  }
  if (param_3 != 0) {
    memcpy(param_1 + 5,param_2,param_3);
  }
  return;
}

