/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_intrp.o -> aps_handle_intrp_data_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_handle_intrp_data_ind(int param_1,int param_2)

{
  int aiStack_44 [3];
  undefined2 uStack_38;
  undefined2 uStack_36;
  undefined2 uStack_34;
  undefined2 uStack_32;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined1 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined1 uStack_13;
  
  uStack_38 = *(undefined2 *)(param_1 + 6);
  uStack_36 = *(undefined2 *)(param_1 + 8);
  uStack_34 = *(undefined2 *)(param_1 + 10);
  uStack_32 = *(undefined2 *)(param_1 + 0xc);
  uStack_30 = *(undefined2 *)(param_1 + 0xe);
  uStack_2e = *(undefined2 *)(param_1 + 0x10);
  uStack_2c = *(undefined2 *)(param_1 + 0x12);
  uStack_2a = *(undefined2 *)(param_1 + 0x14);
  uStack_28 = *(undefined2 *)(param_1 + 0x16);
  uStack_26 = *(undefined2 *)(param_1 + 0x18);
  uStack_24 = *(undefined2 *)(param_1 + 0x1a);
  uStack_22 = *(undefined2 *)(param_1 + 0x1c);
  uStack_20 = *(undefined2 *)(param_1 + 4);
  uStack_1e = *(undefined2 *)(param_1 + 2);
  uStack_1c = 0;
  aiStack_44[0] = param_2;
  uStack_18 = aps_intrp_msg_transfer_ownership(aiStack_44);
  uStack_14 = *(undefined1 *)(param_1 + 0x1e);
  uStack_13 = *(undefined1 *)(param_1 + 0x1f);
  aps_intrp_data_indication(&uStack_38);
  if (aiStack_44[0] != 0) {
    zmsg_free();
  }
  return;
}

