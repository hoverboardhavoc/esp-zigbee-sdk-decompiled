/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_store_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_store_key_pair(undefined4 *param_1)

{
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined1 auStack_38 [16];
  undefined1 auStack_28 [16];
  int iStack_18;
  undefined2 uStack_14;
  undefined2 uStack_12;
  
  memset(&local_40,0,0x30);
  aps_secur_remove_stored_key_pair(param_1);
  local_40 = *param_1;
  uStack_3c = param_1[1];
  secur_key_copy(auStack_38,(int)param_1 + 0x12);
  secur_key_copy(auStack_28,(int)param_1 + 0x22);
  uStack_14 = *(undefined2 *)((int)param_1 + 0x32);
  iStack_18 = param_1[2] + 0x400;
  uStack_12 = *(undefined2 *)(param_1 + 0xd);
  ds_internal_add_entry(9,&local_40,0x30);
  return;
}

