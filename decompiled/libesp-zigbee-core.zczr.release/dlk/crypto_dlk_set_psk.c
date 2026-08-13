/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> dlk.o -> crypto_dlk_set_psk
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 crypto_dlk_set_psk(uint *param_1,void *param_2,uint param_3)

{
  undefined4 uVar1;
  uint *puVar2;
  void *extraout_a1;
  uint uVar3;
  
  uVar3 = *param_1 >> 5 & 3;
  if (uVar3 == 1) {
    if (((*param_1 & 0x60) == 0x20) && ((*param_1 & 0x1c) == 4)) {
      uVar3 = *param_1 & 3;
      puVar2 = param_1 + 0x26;
      if (uVar3 == 1) {
        crypto_aes_mmo_hash(param_2,param_3,puVar2);
        memcpy(param_1 + 0x2a,puVar2,0x10);
      }
      else {
        if (uVar3 != 2) {
          return 6;
        }
        crypto_sha256_hash(param_3,puVar2);
        *(byte *)(param_1 + 0x26) = 9;
      }
      *(byte *)(param_1 + 0x2e) = 0x20;
      uVar1 = crypto_ecdh_set_generator(param_1 + 2,puVar2);
      return uVar1;
    }
  }
  else if (uVar3 == 2) {
    puVar2 = param_1;
    uVar3 = param_3;
    if (0x20 < param_3) {
      uVar3 = 0;
      puVar2 = (uint *)__assert_func(0,0,0);
      param_2 = extraout_a1;
    }
    memcpy(puVar2 + 0x26,param_2,uVar3);
    *(byte *)(param_1 + 0x2e) = (byte)param_3;
    return 0;
  }
  return 6;
}

