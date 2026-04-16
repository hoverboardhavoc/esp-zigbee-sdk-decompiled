/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_reporting.o -> ds_zcl_reporting_info_itor_read
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ds_zcl_reporting_info_itor_read(ds_zcl_reporting_info_iterator_t *itor)

{
  int iVar1;
  
  memset(itor,0,0x1b);
  iVar1 = ds_internal_read_entry(10,itor->index,itor,0x1b);
  itor->is_done = iVar1 != 0;
  return;
}

