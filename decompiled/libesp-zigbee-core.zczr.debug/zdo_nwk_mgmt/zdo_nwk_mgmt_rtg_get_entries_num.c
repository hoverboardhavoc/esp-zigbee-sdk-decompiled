/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_rtg_get_entries_num
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

short zdo_nwk_mgmt_rtg_get_entries_num(void)

{
  short sVar1;
  int iVar2;
  
  iVar2 = 0;
  sVar1 = 0;
  while (iVar2 = nwk_route_table_next(iVar2), iVar2 != 0) {
    sVar1 = sVar1 + 1;
  }
  return sVar1;
}

