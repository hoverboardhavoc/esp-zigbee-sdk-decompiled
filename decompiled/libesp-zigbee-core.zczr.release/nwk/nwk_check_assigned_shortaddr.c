/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_check_assigned_shortaddr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool nwk_check_assigned_shortaddr(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined1 auStack_12 [10];
  
  if (0xfff6 < (param_1 - 1U & 0xffff)) {
    return false;
  }
  iVar2 = nwk_get_short_address();
  if (iVar2 == param_1) {
    bVar1 = false;
  }
  else {
    iVar2 = nwk_address_ref_by_short(param_1,auStack_12);
    bVar1 = iVar2 == 0;
  }
  return bVar1;
}

