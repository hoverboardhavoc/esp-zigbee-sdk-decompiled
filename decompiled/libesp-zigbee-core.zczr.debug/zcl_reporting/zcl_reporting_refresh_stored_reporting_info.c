/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> zcl_reporting_refresh_stored_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void zcl_reporting_refresh_stored_reporting_info(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  ezb_err_t eVar4;
  
  zcl_reporting_delete_all_stored_reporting_info();
  iVar3 = core_globals_get();
  puVar1 = *(undefined4 **)(iVar3 + 0xd34);
  while ((puVar2 = puVar1 + -1, puVar2 != (undefined4 *)0xfffffffc &&
         (((puVar2 == (undefined4 *)0x0 ||
           ((zcl_reporting_info_t *)*puVar2 == (zcl_reporting_info_t *)0x0)) ||
          (eVar4 = zcl_reporting_store_reporting_info((zcl_reporting_info_t *)*puVar2), eVar4 == 0))
         ))) {
    puVar1 = (undefined4 *)*puVar1;
  }
  return;
}

