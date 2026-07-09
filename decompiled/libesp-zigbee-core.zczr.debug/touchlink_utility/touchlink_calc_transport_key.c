/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_calc_transport_key
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
  undefined4 *puStack_58;
  undefined2 uStack_54;
  undefined1 auStack_50 [16];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 auStack_24 [4];
  
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  auStack_24[0] = 0;
  if ((param_2 & 1) == 0) {
    write_be32(param_3,&uStack_30);
    write_be32(param_3,&uStack_2c);
    write_be32(param_4,&uStack_28);
    write_be32(param_4,auStack_24);
    uStack_40 = 0xc3c2c1c0;
    uStack_3c = 0xc7c6c5c4;
    uStack_38 = 0xcbcac9c8;
    uStack_34 = 0xcfcecdcc;
    if ((param_2 & 0x10) == 0) {
      if (-1 < (short)param_2) {
        return 0xff;
      }
      puStack_58 = &uStack_40;
      uVar1 = 0xf;
    }
    else {
      iVar2 = touchlink_device_info_get();
      puStack_58 = (undefined4 *)(iVar2 + 6);
      uVar1 = 4;
    }
    uStack_54 = 0x10;
    crypto_aes_ecb_init(auStack_50);
    crypto_aes_ecb_setkey_enc(auStack_50,&puStack_58);
    crypto_aes_ecb_encrypt(auStack_50,&uStack_30,param_1);
    crypto_aes_ecb_free(auStack_50);
  }
  else {
    write_be32(0x50684c69,&uStack_30);
    write_be32(param_3,&uStack_2c);
    write_be32(0x434c534e,&uStack_28);
    write_be32(param_4,auStack_24);
    memcpy(param_1,&uStack_30,0x10);
    uVar1 = 0;
  }
  return uVar1;
}

