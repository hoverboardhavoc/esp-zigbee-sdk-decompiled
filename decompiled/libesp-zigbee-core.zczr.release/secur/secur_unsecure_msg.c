/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> secur.o -> secur_unsecure_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int secur_unsecure_msg(uint param_1,int param_2,int param_3,int param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  
  if ((((param_4 != 0) && (param_2 != 0)) && (param_3 != 0)) && (param_1 < 8)) {
    uVar1 = param_1 & 3;
    if (uVar1 != 0) {
      uVar1 = 4 << (uVar1 - 1 & 0x1f) & 0xff;
    }
    iVar2 = zmsg_get_length(param_4);
    if ((param_1 & 4) == 0) {
      param_5 = iVar2 - uVar1 & 0xffff;
    }
    iVar2 = crypto_unsecure_msg(param_4,param_2,param_3,param_5,uVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    if (uVar1 == 0) {
      return 0;
    }
    iVar2 = zmsg_get_length(param_4);
    iVar2 = zmsg_set_length(param_4,iVar2 - uVar1 & 0xffff);
    if (iVar2 == 0) {
      return 0;
    }
    __assert_func(0,0,0,0);
  }
  return 2;
}

