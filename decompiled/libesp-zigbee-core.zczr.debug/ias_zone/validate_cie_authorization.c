/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> validate_cie_authorization
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 validate_cie_authorization(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int unaff_s2;
  int iStack_18;
  int iStack_14;
  
  iStack_18 = 0;
  iStack_14 = 0;
  iVar2 = ias_zone_srv_get_attr_desc(0x10);
  if (iVar2 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x78,
                  "validate_cie_authorization","attr_desc");
    iStack_14 = param_2;
  }
  else {
    iVar1 = **(int **)(iVar2 + 8);
    unaff_s2 = (*(int **)(iVar2 + 8))[1];
    iVar2 = nwk_address_extended_by_short(param_1,&iStack_18);
    if (iVar2 != 0) {
      return 0;
    }
    if (iStack_18 != iVar1) {
      return 0;
    }
  }
  if (iStack_14 != unaff_s2) {
    return 0;
  }
  return 1;
}

