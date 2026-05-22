/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_join.o -> zdo_comm_get_scan_duration
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_comm_get_scan_duration(uint8_t *scan_duration)

{
  int iVar1;
  ezb_err_t eVar2;
  
  iVar1 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x00010136. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  eVar2 = (**(code **)(iVar1 + 0xcd4))(0,1,scan_duration,*(code **)(iVar1 + 0xcd4));
  return eVar2;
}

