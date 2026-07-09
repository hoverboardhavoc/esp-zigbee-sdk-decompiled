/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_start(int param_1,short *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = mac_is_enabled();
  if (iVar1 == 0) {
    uVar2 = 3;
  }
  else if (param_2 == (short *)0x0) {
    uVar2 = 2;
  }
  else if (*(short *)(param_1 + 8) == -1) {
    uVar2 = 0x1ec;
  }
  else if (*param_2 == -1) {
    uVar2 = 0x1e8;
  }
  else {
    iVar1 = mac_set_pan_channel(param_1,*(undefined1 *)((int)param_2 + 3),(char)param_2[1]);
    if (iVar1 == 0) {
      mac_set_pan_coord(param_1,param_2[2] & 1);
      mac_set_panid(param_1,*param_2);
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

