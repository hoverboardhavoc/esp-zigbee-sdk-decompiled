/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
  if (*(char *)(iVar2 + 0xd84) == '\0') {
    iVar2 = core_globals_get();
    *(undefined1 *)(iVar2 + 0xd84) = 1;
    iVar2 = core_globals_get();
    for (piVar1 = *(int **)(iVar2 + 0xd98); piVar1 + -1 != (undefined4 *)0xfffffffc;
        piVar1 = (int *)*piVar1) {
      process_attr_report((zcl_reporting_info_t *)piVar1[-1]);
    }
    eVar3 = 0;
  }
  return eVar3;
}

