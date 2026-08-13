/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> hmac.o -> crypto_hmac_core
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_hmac_core(undefined4 *param_1,undefined4 param_2,size_t param_3,uint param_4,
                     void *param_5,uint param_6,int param_7,int param_8)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_a1;
  uint uVar6;
  size_t __n;
  int in_stack_00000000;
  byte local_50 [14];
  undefined1 auStack_42 [14];
  
  if (param_3 < param_4) {
    param_4 = 0;
    param_3 = 0;
    param_1 = (undefined4 *)__assert_func(0,0);
    param_2 = extraout_a1;
  }
  __n = param_3 + param_4;
  iVar2 = -(param_3 + 0xf & 0x1f0);
  iVar3 = -(__n + 0xf & 0x3f0);
  if ((((param_5 != (void *)0x0) && (param_6 != 0)) && (param_7 != 0)) &&
     ((param_8 != 0 && (in_stack_00000000 != 0)))) {
    memset(local_50 + iVar2,0,param_3);
    memset(local_50 + iVar3 + iVar2,0,__n);
    if (param_3 < param_6) {
      (*(code *)*param_1)(param_2,(code *)*param_1);
      (*(code *)param_1[1])(param_2,param_5,param_6,(code *)param_1[1]);
      (*(code *)param_1[2])(param_2,local_50 + iVar2,param_3,auStack_42,(code *)param_1[2]);
    }
    else {
      memcpy(local_50 + iVar2,param_5,param_6);
    }
    uVar6 = 0;
    do {
      iVar4 = uVar6 + iVar2;
      bVar1 = local_50[iVar4];
      iVar5 = uVar6 + iVar3 + iVar2;
      uVar6 = uVar6 + 1;
      local_50[iVar4] = bVar1 ^ 0x36;
      local_50[iVar5] = bVar1 ^ 0x5c;
    } while ((uVar6 & 0xff) < param_3);
    (*(code *)*param_1)(param_2,(code *)*param_1);
    (*(code *)param_1[1])(param_2,local_50 + iVar2,param_3,(code *)param_1[1]);
    (*(code *)param_1[1])(param_2,param_7,param_8,(code *)param_1[1]);
    (*(code *)param_1[2])
              (param_2,local_50 + param_3 + iVar3 + iVar2,param_4,auStack_42,(code *)param_1[2]);
    (*(code *)*param_1)(param_2,(code *)*param_1);
    (*(code *)param_1[1])(param_2,local_50 + iVar3 + iVar2,__n,(code *)param_1[1]);
    (*(code *)param_1[2])(param_2,in_stack_00000000,param_4,auStack_42,(code *)param_1[2]);
  }
  return;
}

