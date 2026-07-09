/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_ed_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
mac_ed_scan(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = mac_is_enabled();
  if (iVar1 == 0) {
    uVar2 = 3;
  }
  else {
    iVar1 = mac_can_scan(param_1);
    if (iVar1 == 0) {
      uVar2 = 9;
    }
    else {
      *(undefined4 *)(param_1 + 0x38) = param_4;
      *(undefined4 *)(param_1 + 0x3c) = param_5;
      mac_scan(param_1,2,param_2,param_3);
      uVar2 = 0;
    }
  }
  return uVar2;
}

