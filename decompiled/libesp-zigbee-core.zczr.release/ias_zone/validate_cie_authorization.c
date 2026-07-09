/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_zone.o -> validate_cie_authorization
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool validate_cie_authorization(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iStack_18;
  int iStack_14;
  
  iStack_18 = 0;
  iStack_14 = 0;
  iVar1 = ias_zone_srv_get_attr_desc(0x10);
  if (iVar1 == 0) {
    iVar1 = __assert_func(0,0,0);
  }
  iVar3 = **(int **)(iVar1 + 8);
  iVar1 = (*(int **)(iVar1 + 8))[1];
  iVar2 = nwk_address_extended_by_short(param_1,&iStack_18);
  return iVar2 == 0 && (iStack_18 == iVar3 && iStack_14 == iVar1);
}

