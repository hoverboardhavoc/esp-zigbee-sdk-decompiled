/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk.o -> nwk_check_assigned_shortaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_check_assigned_shortaddr(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_12 [10];
  
  if (param_1 < 0xfff8) {
    if (param_1 == 0) {
      uVar1 = 0;
    }
    else {
      uVar2 = nwk_get_short_address();
      if (uVar2 == param_1) {
        uVar1 = 0;
      }
      else {
        iVar3 = nwk_address_ref_by_short(param_1,auStack_12);
        if (iVar3 == 0) {
          uVar1 = 1;
        }
        else {
          uVar1 = 0;
        }
      }
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

