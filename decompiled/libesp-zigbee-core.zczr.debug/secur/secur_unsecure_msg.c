/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> secur.o -> secur_unsecure_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int secur_unsecure_msg(uint param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  
  if (param_4 != 0) {
    if (param_2 == 0) {
      return 2;
    }
    if (param_3 == 0) {
      return 2;
    }
    if (7 < param_1) {
      return 2;
    }
    uVar2 = param_1 & 3;
    if (uVar2 != 0) {
      uVar2 = 4 << (uVar2 - 1 & 0x1f) & 0xff;
    }
    iVar1 = zmsg_get_length(param_4);
    if ((param_1 & 4) == 0) {
      param_5 = iVar1 - uVar2 & 0xffff;
    }
    iVar1 = crypto_unsecure_msg(param_4,param_2,param_3,param_5,uVar2);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (uVar2 == 0) {
      return 0;
    }
    iVar1 = zmsg_get_length(param_4);
    iVar1 = zmsg_set_length(param_4,iVar1 - uVar2 & 0xffff);
    if (iVar1 == 0) {
      return 0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/secur/secur.c",0x47,
                  "secur_unsecure_msg",0x10000);
  }
  return 2;
}

