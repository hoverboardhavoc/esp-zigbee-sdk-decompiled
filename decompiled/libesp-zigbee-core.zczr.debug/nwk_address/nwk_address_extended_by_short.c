/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_extended_by_short
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_address_extended_by_short(int *param_1)

{
  int iVar1;
  undefined2 auStack_12 [5];
  
  iVar1 = nwk_address_ref_by_short(auStack_12);
  if ((iVar1 == 0) && (iVar1 = nwk_address_extended_by_ref(auStack_12[0],param_1), iVar1 == 0)) {
    if (*param_1 == 0 && param_1[1] == 0) {
      iVar1 = 5;
    }
    else if ((*param_1 == -1) && (param_1[1] == -1)) {
      iVar1 = 5;
    }
  }
  return iVar1;
}

