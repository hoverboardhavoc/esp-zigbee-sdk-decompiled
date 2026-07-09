/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_send_msg_loopback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_send_msg_loopback(undefined4 *param_1,undefined4 param_2)

{
  short sVar1;
  int iVar2;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  sVar1 = *(short *)(param_1 + 1);
  iVar2 = zmsg_clone(param_2);
  if (iVar2 != 0) {
    uStack_18 = 0;
    uStack_24 = *param_1;
    uStack_20 = param_1[1];
    uStack_1c = param_1[2];
    uStack_14 = 0x7f;
    aps_handle_data(&uStack_24,iVar2);
  }
  if (sVar1 == 0) {
    aps_send_data_confirm(param_2,iVar2 == 0);
  }
  return;
}

