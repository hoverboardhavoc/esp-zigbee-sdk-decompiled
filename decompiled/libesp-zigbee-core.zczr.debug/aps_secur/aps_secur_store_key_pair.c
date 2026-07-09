/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_store_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_store_key_pair(undefined4 *param_1)

{
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  
  local_40 = 0;
  uStack_3c = 0;
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  iStack_18 = 0;
  uStack_14 = 0;
  aps_secur_remove_stored_key_pair();
  local_40 = *param_1;
  uStack_3c = param_1[1];
  memcpy(&uStack_38,(void *)((int)param_1 + 0x12),0x10);
  memcpy(&uStack_28,(void *)((int)param_1 + 0x22),0x10);
  iStack_18 = param_1[2] + 0x400;
  uStack_14 = *(undefined4 *)((int)param_1 + 0x32);
  ds_internal_add_entry(9,&local_40,0x30);
  return;
}

