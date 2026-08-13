/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> hmac.o -> crypto_hmac_core
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_hmac_core(undefined4 *param_1,undefined4 param_2,uint param_3,uint param_4,void *param_5
                     ,uint param_6,int param_7,int param_8)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  undefined1 *unaff_s7;
  undefined1 *unaff_s8;
  int in_stack_00000000;
  undefined1 auStack_50 [14];
  undefined1 auStack_42 [14];
  
  if (param_1 == (undefined4 *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/hmac.c",0x16,"crypto_hmac_core"
                  ,0x10000);
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/crypto/hmac.c",0x17,"crypto_hmac_core"
                  ,"block_size >= output_size");
  }
  else {
    if (param_3 < param_4) goto _L0;
    iVar1 = -(param_3 + 0xf & 0x1f0);
    unaff_s7 = auStack_50 + iVar1;
    iVar2 = -(param_4 + param_3 + 0xf & 0x3f0);
    unaff_s8 = auStack_50 + iVar2 + iVar1;
    if (param_5 == (void *)0x0) {
      return;
    }
    if (param_6 == 0) {
      return;
    }
    if (param_7 == 0) {
      return;
    }
    if (param_8 == 0) {
      return;
    }
    if (in_stack_00000000 == 0) {
      return;
    }
    memset(auStack_50 + iVar1,0,param_3);
    memset(auStack_50 + iVar2 + iVar1,0,param_4 + param_3);
    if (param_3 < param_6) {
      (*(code *)*param_1)(param_2,(code *)*param_1);
      (*(code *)param_1[1])(param_2,param_5,param_6,(code *)param_1[1]);
      (*(code *)param_1[2])(param_2,auStack_50 + iVar1,param_3,auStack_42,(code *)param_1[2]);
      unaff_s7 = auStack_50 + iVar1;
      unaff_s8 = auStack_50 + iVar2 + iVar1;
      goto _L0;
    }
  }
  memcpy(unaff_s7,param_5,param_6);
_L0:
  for (uVar4 = 0; uVar4 < param_3; uVar4 = uVar4 + 1 & 0xff) {
    pbVar3 = unaff_s7 + uVar4;
    unaff_s8[uVar4] = *pbVar3 ^ 0x5c;
    *pbVar3 = *pbVar3 ^ 0x36;
  }
  (*(code *)*param_1)(param_2,(code *)*param_1);
  (*(code *)param_1[1])(param_2,unaff_s7,param_3,(code *)param_1[1]);
  (*(code *)param_1[1])(param_2,param_7,param_8,(code *)param_1[1]);
  (*(code *)param_1[2])(param_2,unaff_s8 + param_3,param_4,auStack_42,(code *)param_1[2]);
  (*(code *)*param_1)(param_2,(code *)*param_1);
  (*(code *)param_1[1])(param_2,unaff_s8,param_3 + param_4,(code *)param_1[1]);
  (*(code *)param_1[2])(param_2,in_stack_00000000,param_4,auStack_42,(code *)param_1[2]);
  memset(unaff_s7,0,param_3);
  return;
}

