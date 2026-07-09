/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_decrypt_nwk_key
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int touchlink_decrypt_nwk_key
              (int param_1,int param_2,ushort param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  undefined1 *puStack_48;
  undefined2 uStack_44;
  undefined1 auStack_40 [16];
  undefined1 auStack_30 [28];
  
  iVar2 = touchlink_device_info_get();
  iVar1 = 0xff;
  if (((param_1 != 0) && (param_2 != 0)) && ((param_3 & *(ushort *)(iVar2 + 4)) != 0)) {
    iVar1 = touchlink_calc_transport_key(auStack_30,param_4,param_5);
    if (iVar1 != 0xff) {
      uStack_44 = 0x10;
      puStack_48 = auStack_30;
      crypto_aes_ecb_init(auStack_40);
      crypto_aes_ecb_setkey_dec(auStack_40,&puStack_48);
      crypto_aes_ecb_decrypt(auStack_40,param_1,param_2);
      crypto_aes_ecb_free(auStack_40);
    }
  }
  return iVar1;
}

