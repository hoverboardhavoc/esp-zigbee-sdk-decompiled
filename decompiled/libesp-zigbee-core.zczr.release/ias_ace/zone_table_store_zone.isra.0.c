/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ias_ace.o -> zone_table_store_zone.isra.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zone_table_store_zone_isra_0(undefined1 param_1,undefined1 *param_2)

{
  undefined1 local_30;
  undefined1 uStack_2f;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  byte bStack_24;
  undefined1 auStack_23 [27];
  
  uStack_2f = *param_2;
  uStack_2e = *(undefined2 *)(param_2 + 2);
  uStack_2c = *(undefined4 *)(param_2 + 4);
  uStack_28 = *(undefined4 *)(param_2 + 8);
  bStack_24 = (byte)*(undefined2 *)(param_2 + 0xc) & 1;
  memcpy(auStack_23,param_2 + 0xd,0x11);
  local_30 = param_1;
  ds_internal_add_entry(0xd,&local_30,0x1e);
  return;
}

