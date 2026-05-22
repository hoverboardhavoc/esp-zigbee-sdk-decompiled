/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_start
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_reporting_start(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  ezb_err_t eVar4;
  
  iVar3 = core_globals_get();
  if (*(char *)(iVar3 + 0xd20) == '\0') {
    iVar3 = core_globals_get();
    *(undefined1 *)(iVar3 + 0xd20) = 1;
    iVar3 = core_globals_get();
    for (puVar1 = *(undefined4 **)(iVar3 + 0xd34); puVar2 = puVar1 + -1,
        puVar2 != (undefined4 *)0xfffffffc; puVar1 = (undefined4 *)*puVar1) {
      if (puVar2 != (undefined4 *)0x0) {
        process_attr_report((zcl_reporting_info_t *)*puVar2);
      }
    }
    eVar4 = 0;
  }
  else {
    eVar4 = 3;
  }
  return eVar4;
}

