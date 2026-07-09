/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> secur.o -> secur_secure_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int secur_secure_msg(uint param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_4 == 0) {
    return 2;
  }
  if (((param_2 == 0) || (param_3 == 0)) || (7 < param_1)) {
    iVar3 = 2;
  }
  else {
    uVar1 = param_1 & 3;
    if (uVar1 != 0) {
      uVar1 = 4 << (uVar1 - 1 & 0x1f) & 0xff;
    }
    uVar2 = zmsg_get_length(param_4);
    if ((param_1 & 4) == 0) {
      param_5 = uVar2;
    }
    iVar3 = zmsg_get_length(param_4);
    iVar3 = zmsg_set_length(param_4,uVar1 + iVar3 & 0xffff);
    if (iVar3 == 0) {
      iVar3 = crypto_secure_msg(param_4,param_2,param_3,param_5,uVar1);
      return iVar3;
    }
  }
  return iVar3;
}

