/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aes_ccm.o -> crypto_aes_ccm_star_auth_and_decrypt
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
crypto_aes_ccm_star_auth_and_decrypt
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
          uint param_6,undefined4 param_7)

{
  uint uVar1;
  undefined4 uVar2;
  uint in_stack_00000004;
  undefined1 auStack_40 [24];
  
  if (param_6 < in_stack_00000004) {
    uVar2 = 2;
  }
  else {
    uVar1 = param_6 - in_stack_00000004 & 0xffff;
    memcpy(auStack_40,(void *)(param_5 + uVar1),in_stack_00000004);
    uVar2 = crypto_aes_ccm_star(1,param_1,param_2,param_3,param_4,param_5,uVar1,param_7);
  }
  return uVar2;
}

