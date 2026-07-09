/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_join.o -> zdo_comm_get_scan_duration.isra.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_comm_get_scan_duration_isra_0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = core_globals_get();
                    /* WARNING: Could not recover jumptable at 0x00010136. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0xcd4))(0,1,param_1,*(code **)(iVar1 + 0xcd4));
  return;
}

