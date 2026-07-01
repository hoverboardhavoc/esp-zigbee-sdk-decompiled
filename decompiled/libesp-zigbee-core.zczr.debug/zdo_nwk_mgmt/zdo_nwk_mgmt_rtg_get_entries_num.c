/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_rtg_get_entries_num
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint16_t zdo_nwk_mgmt_rtg_get_entries_num(void)

{
  uint16_t uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = 0;
  while (iVar2 = nwk_route_table_next(iVar2), iVar2 != 0) {
    uVar1 = uVar1 + 1;
  }
  return uVar1;
}

