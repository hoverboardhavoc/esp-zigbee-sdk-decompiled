/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> hash.o -> crypto_sha256_hash_finish
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_sha256_hash_finish(undefined4 param_1,undefined2 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_a1;
  char *pcVar3;
  undefined1 auStack_58 [38];
  undefined2 auStack_32 [7];
  
  iVar1 = ezb_plat_crypto_sha256_finish();
  if (iVar1 == 0) {
    iVar1 = ezb_plat_crypto_sha256_free(param_1);
    if (iVar1 == 0) {
      *param_2 = 0x20;
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/hash.c",0xf2,
                  "crypto_sha256_hash_finish",0x10550);
  }
  pcVar3 = "crypto_sha256_hash_finish";
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/hash.c",0xf3,
                        "crypto_sha256_hash_finish",
                        "(ezb_plat_crypto_sha256_free(&ctx->context)) == 0");
  crypto_aes_mmo_hash_start(auStack_58);
  crypto_aes_mmo_hash_update(auStack_58,uVar2,extraout_a1);
  auStack_32[0] = 0;
  crypto_aes_mmo_hash_finish(auStack_58,pcVar3,0x10,auStack_32);
  return;
}

