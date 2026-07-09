/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_send_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_send_data_confirm(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined2 uStack_3c;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined1 uStack_34;
  int iStack_30;
  undefined1 auStack_2c [4];
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined2 uStack_20;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  byte bStack_14;
  
  zmsg_get_footer(auStack_2c,0x1c);
  zmsg_remove_footer(param_1,0x1c);
  if ((*(ushort *)(param_1 + 0x16) & 0x20) == 0) {
    uVar1 = zmsg_get_offset(param_1);
    zmsg_remove_header(param_1,uVar1);
    uStack_44 = uStack_28;
    uStack_40 = uStack_24;
    uStack_3c = uStack_20;
    uStack_3a = uStack_1e;
    uStack_39 = uStack_1d;
    uStack_38 = uStack_1c;
    uStack_36 = uStack_1a;
    uStack_34 = (undefined1)param_2;
    iStack_30 = param_1;
    if ((bStack_14 & 0x20) == 0) {
      aps_apsde_data_confirm(&uStack_44);
    }
    else {
      aps_apsde_user_data_confirm(&uStack_44);
    }
  }
  else {
    aps_bind_trans_confirm(param_1,param_2);
  }
  return;
}

