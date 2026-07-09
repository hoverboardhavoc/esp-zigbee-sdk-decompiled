/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_is_tc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool aps_secur_is_tc(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)nwk_get_extended_address();
  iVar2 = core_globals_get();
  return *piVar1 == *(int *)(iVar2 + 0x9ac) && piVar1[1] == *(int *)(iVar2 + 0x9b0);
}

