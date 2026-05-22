/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zcl_reporting.o -> zcl_reporting_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_reporting_start(void)

{
  int *piVar1;
  int iVar2;
  ezb_err_t eVar3;
  
  iVar2 = core_globals_get();
  eVar3 = 3;
  if (*(char *)(iVar2 + 0xd20) == '\0') {
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0xd20) = 1;
    iVar2 = core_globals_get();
    for (piVar1 = *(int **)(iVar2 + 0xd34); piVar1 + -1 != (undefined4 *)0xfffffffc;
        piVar1 = (int *)*piVar1) {
      process_attr_report((zcl_reporting_info_t *)piVar1[-1]);
    }
    eVar3 = 0;
  }
  return eVar3;
}

