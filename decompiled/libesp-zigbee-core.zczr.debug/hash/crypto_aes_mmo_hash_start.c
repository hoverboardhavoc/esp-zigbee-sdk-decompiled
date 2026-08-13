/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> hash.o -> crypto_aes_mmo_hash_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_aes_mmo_hash_start(void *param_1)

{
  int iVar1;
  int extraout_a1;
  uint uVar2;
  int iStack_38;
  undefined2 uStack_34;
  undefined1 auStack_30 [16];
  
  if (param_1 != (void *)0x0) {
    memset(param_1,0,0x24);
    return;
  }
  iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/hash.c",0xa6,
                        "crypto_aes_mmo_hash_start","ctx != ((void *)0)");
  uStack_34 = 0x10;
  iStack_38 = extraout_a1;
  crypto_aes_ecb_init(auStack_30);
  crypto_aes_ecb_setkey_enc(auStack_30,&iStack_38);
  crypto_aes_ecb_encrypt(auStack_30,iVar1,extraout_a1);
  crypto_aes_ecb_free(auStack_30);
  for (uVar2 = 0; uVar2 < 0x10; uVar2 = uVar2 + 1) {
    *(byte *)(extraout_a1 + uVar2) = *(byte *)(extraout_a1 + uVar2) ^ *(byte *)(iVar1 + uVar2);
  }
  return;
}

