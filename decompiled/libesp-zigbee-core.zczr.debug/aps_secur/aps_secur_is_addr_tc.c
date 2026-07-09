/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_is_addr_tc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 aps_secur_is_addr_tc(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  if (*param_1 == 0 && param_1[1] == 0) {
    uVar2 = 0;
  }
  else if ((*param_1 == -1) && (param_1[1] == -1)) {
    uVar2 = 0;
  }
  else {
    piVar1 = (int *)aps_secur_get_tc_address();
    if ((*param_1 == *piVar1) && (param_1[1] == piVar1[1])) {
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

