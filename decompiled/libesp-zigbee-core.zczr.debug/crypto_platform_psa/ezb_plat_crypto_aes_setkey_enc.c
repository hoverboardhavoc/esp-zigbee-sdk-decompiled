/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform_psa.o -> ezb_plat_crypto_aes_setkey_enc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_plat_crypto_aes_setkey_enc(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 2;
  }
  else if (*(ushort *)(param_1 + 1) < 4) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = *param_1;
    if (param_2 == (undefined4 *)0x0) {
      uVar1 = 2;
    }
    else {
      uStack_26 = 0;
      uStack_24 = 0;
      uStack_20 = 0;
      uStack_18 = 0;
      uStack_14 = 0;
      uStack_28 = 0x2400;
      uStack_1c = 0x4404400;
      uStack_2c = 0x100;
      psa_extend_key_usage_flags(&uStack_2c);
      uStack_20 = uStack_2c;
      uStack_24 = 0;
      uStack_14 = 0;
      psa_import_key(&uStack_28,*param_2,*(undefined2 *)(param_2 + 1),uVar1);
      uVar1 = psa_to_ezb_error();
    }
  }
  return uVar1;
}

