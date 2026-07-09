/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aes_ccm.o -> crypto_secure_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int crypto_secure_msg(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                     int param_5)

{
  uint uVar1;
  int iVar2;
  undefined1 auStack_30 [20];
  
  iVar2 = zmsg_get_length();
  if (iVar2 < param_4 + param_5) {
    iVar2 = 2;
  }
  else {
    iVar2 = zmsg_get_length(param_1);
    uVar1 = (iVar2 - param_4 & 0xffffU) - param_5 & 0xffff;
    iVar2 = crypto_aes_ccm_star_msg(param_1,0,param_2,param_3,param_4,uVar1,auStack_30,param_5);
    if (iVar2 == 0) {
      zmsg_write_bytes(param_1,param_4 + uVar1 & 0xffff,param_5,auStack_30);
    }
  }
  return iVar2;
}

