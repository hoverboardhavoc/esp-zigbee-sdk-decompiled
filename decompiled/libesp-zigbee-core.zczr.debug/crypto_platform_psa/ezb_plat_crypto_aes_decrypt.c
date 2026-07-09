/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> crypto_platform_psa.o -> ezb_plat_crypto_aes_decrypt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_plat_crypto_aes_decrypt(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  undefined1 auStack_14 [16];
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 2;
  }
  else if (*(ushort *)(param_1 + 1) < 4) {
    uVar1 = 0xffffffff;
  }
  else if (param_2 == 0) {
    uVar1 = 2;
  }
  else if (param_3 == 0) {
    uVar1 = 2;
  }
  else {
    psa_cipher_decrypt(*(undefined4 *)*param_1,0x4404400,param_2,0x10,param_3,auStack_14);
    uVar1 = psa_to_ezb_error();
  }
  return uVar1;
}

