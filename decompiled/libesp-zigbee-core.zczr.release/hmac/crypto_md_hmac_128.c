/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> hmac.o -> crypto_md_hmac_128
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void crypto_md_hmac_128(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,void *param_6)

{
  undefined4 extraout_a1;
  undefined4 uVar1;
  int iVar2;
  undefined4 auStack_20 [2];
  undefined1 auStack_18 [8];
  
  if (*param_1 != 1) {
    iVar2 = 0x20;
    uVar1 = 0x40;
    if (*param_1 == 2) goto _L0;
    param_1 = (int *)__assert_func(0,0,0,0,param_4,param_5);
    param_2 = extraout_a1;
  }
  iVar2 = 0x10;
  uVar1 = 0x10;
_L0:
  *(undefined1 **)((int)auStack_20 + -iVar2) = auStack_18 + -iVar2;
  crypto_hmac_core(param_1 + 1,param_1 + 4,uVar1,param_2,param_3);
  memcpy(param_6,auStack_18 + -iVar2,0x10);
  return;
}

