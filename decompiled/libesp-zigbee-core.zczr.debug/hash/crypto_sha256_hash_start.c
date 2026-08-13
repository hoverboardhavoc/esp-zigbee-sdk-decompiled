/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> hash.o -> crypto_sha256_hash_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void crypto_sha256_hash_start(int *param_1)

{
  int iVar1;
  
  *param_1 = (int)(param_1 + 2);
  *(undefined2 *)(param_1 + 1) = 0xe8;
  iVar1 = ezb_plat_crypto_sha256_init();
  if (iVar1 == 0) {
    iVar1 = ezb_plat_crypto_sha256_start(param_1);
    if (iVar1 == 0) {
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/hash.c",0xe7,
                  "crypto_sha256_hash_start","(ezb_plat_crypto_sha256_init(&ctx->context)) == 0");
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/hash.c",0xe8,
                "crypto_sha256_hash_start","(ezb_plat_crypto_sha256_start(&ctx->context)) == 0");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

