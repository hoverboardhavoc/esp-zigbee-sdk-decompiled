/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> secur.o -> secur_secure_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int secur_secure_msg(uint param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_4 == 0) {
    iVar2 = 2;
  }
  else if (param_2 == 0) {
    iVar2 = 2;
  }
  else if (param_3 == 0) {
    iVar2 = 2;
  }
  else if (param_1 < 8) {
    uVar3 = param_1 & 3;
    if (uVar3 != 0) {
      uVar3 = 4 << (uVar3 - 1 & 0x1f) & 0xff;
    }
    uVar1 = zmsg_get_length(param_4);
    if ((param_1 & 4) == 0) {
      param_5 = uVar1;
    }
    iVar2 = zmsg_get_length(param_4);
    iVar2 = zmsg_set_length(param_4,iVar2 + uVar3 & 0xffff);
    if (iVar2 == 0) {
      iVar2 = crypto_secure_msg(param_4,param_2,param_3,param_5,uVar3);
    }
  }
  else {
    iVar2 = 2;
  }
  return iVar2;
}

