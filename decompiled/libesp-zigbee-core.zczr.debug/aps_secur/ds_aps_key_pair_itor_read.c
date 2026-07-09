/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> ds_aps_key_pair_itor_read
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ds_aps_key_pair_itor_read(void *param_1)

{
  int iVar1;
  
  memset(param_1,0,0x30);
  iVar1 = ds_internal_read_entry(9,*(undefined2 *)((int)param_1 + 0x30),param_1,0x30);
  *(bool *)((int)param_1 + 0x32) = iVar1 != 0;
  return;
}

