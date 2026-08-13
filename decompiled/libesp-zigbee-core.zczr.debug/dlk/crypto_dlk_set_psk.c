/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> dlk.o -> crypto_dlk_set_psk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int crypto_dlk_set_psk(uint *param_1,void *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_a1;
  uint uVar3;
  
  uVar3 = *param_1 >> 5 & 3;
  if (uVar3 == 1) {
    iVar1 = crypto_dlk_generate_base_point((char)*param_1,param_1 + 0x26,param_1 + 0x2e);
    if (iVar1 == 0) {
      iVar1 = crypto_ecdh_set_generator(param_1 + 2,param_1 + 0x26);
    }
  }
  else if (uVar3 == 2) {
    if (0x20 < param_3) {
      iVar1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/dlk.c",100,
                            "crypto_dlk_set_psk","psk_len <= sizeof(ctx->psk)");
      iVar2 = crypto_ecdh_generate_keypair(iVar1 + 8);
      if (iVar2 == 0) {
        iVar2 = crypto_ecdh_export_public(iVar1 + 8,extraout_a1);
      }
      return iVar2;
    }
    memcpy(param_1 + 0x26,param_2,param_3);
    *(char *)(param_1 + 0x2e) = (char)param_3;
    iVar1 = 0;
  }
  else {
    iVar1 = 6;
  }
  return iVar1;
}

