/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> hash.o -> crypto_aes_mmo_hash_finish
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void crypto_aes_mmo_hash_finish(undefined4 *param_1,void *param_2,uint param_3,undefined2 *param_4)

{
  if (param_1 == (undefined4 *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/hash.c",0xcf,
                  "crypto_aes_mmo_hash_finish","ctx != ((void *)0)");
  }
  else if (0xf < param_3) {
    aes_mmo_hash_tail(param_1 + 5,*param_1,param_1 + 1);
    memcpy(param_2,param_1 + 1,0x10);
    *param_4 = 0x10;
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/hash.c",0xd0,
                "crypto_aes_mmo_hash_finish","output_len >= 16");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

