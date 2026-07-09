/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> zone_table_store_zone
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zone_table_store_zone(undefined1 param_1,undefined1 *param_2)

{
  undefined1 local_30;
  undefined3 uStack_2f;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined2 uStack_14;
  
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_2f = CONCAT21(*(undefined2 *)(param_2 + 2),*param_2);
  local_30 = 0;
  uStack_2c = *(undefined4 *)(param_2 + 4);
  uStack_28 = *(undefined4 *)(param_2 + 8);
  uStack_24 = (byte)*(undefined2 *)(param_2 + 0xc) & 0xffffff01;
  memcpy((void *)((int)&uStack_24 + 1),param_2 + 0xd,0x11);
  _local_30 = CONCAT31(uStack_2f,param_1);
  ds_internal_add_entry(0xd,&local_30,0x1e);
  return;
}

