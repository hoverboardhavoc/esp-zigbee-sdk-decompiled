/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aes_ccm.o -> crypto_aes_ccm_star_encrypt_and_tag
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int crypto_aes_ccm_star_encrypt_and_tag
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,int param_6,int param_7,uint param_8)

{
  int iVar1;
  int *in_stack_00000000;
  size_t in_stack_00000004;
  undefined1 auStack_30 [24];
  
  if (param_8 < param_6 + in_stack_00000004) {
    iVar1 = 2;
  }
  else {
    iVar1 = crypto_aes_ccm_star(0,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    if (iVar1 == 0) {
      memcpy((void *)(param_7 + param_6),auStack_30,in_stack_00000004);
      *in_stack_00000000 = *in_stack_00000000 + in_stack_00000004;
    }
  }
  return iVar1;
}

