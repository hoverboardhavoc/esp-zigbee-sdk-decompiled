/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_refresh_stored_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_reporting_refresh_stored_reporting_info(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  
  zcl_reporting_delete_all_stored_reporting_info();
  iVar3 = core_globals_get();
  puVar1 = *(undefined4 **)(iVar3 + 0xd34);
  while ((piVar2 = puVar1 + -1, piVar2 != (int *)0xfffffffc &&
         (((piVar2 == (int *)0x0 || (*piVar2 == 0)) ||
          (iVar3 = zcl_reporting_store_reporting_info(), iVar3 == 0))))) {
    puVar1 = (undefined4 *)*puVar1;
  }
  return;
}

