/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_reporting_start(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = core_globals_get();
  uVar3 = 3;
  if (*(char *)(iVar2 + 0xd20) == '\0') {
    iVar2 = core_globals_get(3);
    *(undefined1 *)(iVar2 + 0xd20) = 1;
    iVar2 = core_globals_get();
    for (piVar1 = *(int **)(iVar2 + 0xd34); piVar1 + -1 != (undefined4 *)0xfffffffc;
        piVar1 = (int *)*piVar1) {
      process_attr_report(piVar1[-1]);
    }
    uVar3 = 0;
  }
  return uVar3;
}

