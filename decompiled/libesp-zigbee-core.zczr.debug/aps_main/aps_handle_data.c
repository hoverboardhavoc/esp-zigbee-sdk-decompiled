/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_handle_data
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_handle_data(undefined2 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  undefined1 uStack_18;
  undefined1 uStack_17;
  undefined4 uStack_14;
  
  uStack_24 = *param_1;
  uStack_22 = param_1[1];
  uStack_20 = param_1[2];
  uStack_1e = param_1[3];
  uStack_1c = param_1[4];
  uStack_1a = param_1[5];
  uStack_18 = *(undefined1 *)((int)param_1 + 0xf);
  uStack_17 = *(undefined1 *)(param_1 + 8);
  uStack_14 = param_2;
  uVar1 = zmsg_get_offset(param_2);
  zmsg_remove_header(param_2,uVar1);
  iVar2 = aps_apsde_user_data_indication(&uStack_24);
  if (iVar2 == 0) {
    aps_apsde_data_indication(&uStack_24);
  }
  return;
}

