/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_remove_dst_all
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_bind_table_remove_dst_all(void *param_1)

{
  int iVar1;
  undefined1 auStack_1c [2];
  undefined1 auStack_1a [22];
  
  auStack_1c[0] = 3;
  memcpy(auStack_1a,param_1,8);
  while (iVar1 = bind_table_find_dst(auStack_1c,0xff), iVar1 != 0) {
    bind_table_remove_dst();
  }
  return;
}

