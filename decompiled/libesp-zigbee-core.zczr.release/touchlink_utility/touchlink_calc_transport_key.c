/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_calc_transport_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
touchlink_calc_transport_key(void *param_1,ushort param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puStack_58;
  undefined2 uStack_54;
  undefined1 auStack_50 [16];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined1 auStack_30 [28];
  
  uVar1 = _swap32(param_4);
  uStack_3c = _swap32(param_3);
  uStack_34 = uVar1;
  if ((param_2 & 1) == 0) {
    uStack_40 = uStack_3c;
    uStack_38 = uVar1;
    memcpy(auStack_30,&_L0,0x10);
    if ((param_2 & 0x10) == 0) {
      if (-1 < (short)param_2) {
        return 0xff;
      }
      puStack_58 = auStack_30;
      uVar1 = 0xf;
    }
    else {
      iVar2 = touchlink_device_info_get();
      puStack_58 = (undefined1 *)(iVar2 + 6);
      uVar1 = 4;
    }
    uStack_54 = 0x10;
    crypto_aes_ecb_init(auStack_50);
    crypto_aes_ecb_setkey_enc(auStack_50,&puStack_58);
    crypto_aes_ecb_encrypt(auStack_50,&uStack_40,param_1);
    crypto_aes_ecb_free(auStack_50);
  }
  else {
    uStack_40 = 0x694c6850;
    uStack_38 = 0x4e534c43;
    uVar1 = 0;
    memcpy(param_1,&uStack_40,0x10);
  }
  return uVar1;
}

