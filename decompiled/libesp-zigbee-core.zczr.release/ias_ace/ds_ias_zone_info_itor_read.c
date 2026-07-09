/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> ds_ias_zone_info_itor_read
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ds_ias_zone_info_itor_read(void *param_1)

{
  int iVar1;
  
  memset(param_1,0,0x1e);
  iVar1 = ds_internal_read_entry(0xd,*(undefined2 *)((int)param_1 + 0x1e),param_1,0x1e);
  *(bool *)((int)param_1 + 0x20) = iVar1 != 0;
  return;
}

