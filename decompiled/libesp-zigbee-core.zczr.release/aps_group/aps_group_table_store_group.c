/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_group.o -> aps_group_table_store_group
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_group_table_store_group(undefined2 *param_1)

{
  undefined2 uStack_34;
  undefined1 auStack_32 [42];
  
  memset(&uStack_34,0,0x22);
  aps_group_table_remove_stored_group(param_1);
  uStack_34 = *param_1;
  memcpy(auStack_32,param_1 + 1,0x20);
  ds_internal_add_entry(5,&uStack_34,0x22);
  return;
}

