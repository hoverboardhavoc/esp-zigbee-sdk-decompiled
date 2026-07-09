/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> crypto_platform_psa.o -> ezb_plat_crypto_aes_setkey_dec
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_plat_crypto_aes_setkey_dec(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined2 uStack_28;
  undefined1 auStack_26 [6];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  if (param_1 == (undefined4 *)0x0) {
    return 2;
  }
  if (3 < *(ushort *)(param_1 + 1)) {
    if (param_2 != (undefined4 *)0x0) {
      uVar1 = *param_1;
      memset(auStack_26,0,0x16);
      uStack_28 = 0x2400;
      uStack_1c = 0x4404400;
      uStack_20 = 0x200;
      psa_import_key(&uStack_28,*param_2,*(undefined2 *)(param_2 + 1),uVar1);
      uVar1 = psa_to_ezb_error();
      return uVar1;
    }
    return 2;
  }
  return 0xffffffff;
}

