/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_check_shortaddr_conflict
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool nwk_check_shortaddr_conflict(int *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  int iStack_18;
  int iStack_14;
  
  iVar2 = nwk_address_extended_by_short(param_2,&iStack_18);
  if (iVar2 == 0) {
    bVar1 = iStack_18 == *param_1 && param_1[1] == iStack_14;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}

