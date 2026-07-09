/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_intrp_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_packet_intrp_send(undefined1 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined1 local_30 [2];
  undefined2 uStack_2e;
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined2 uStack_22;
  undefined2 uStack_20;
  undefined1 uStack_1e;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (param_1 == (undefined1 *)0x0) {
    uVar1 = 0x87;
  }
  else {
    zcl_frame_fill_header();
    local_30[0] = *param_1;
    uStack_2e = 0xffff;
    uStack_2c = *(undefined2 *)(param_1 + 10);
    uStack_2a = *(undefined2 *)(param_1 + 0xc);
    uStack_28 = *(undefined2 *)(param_1 + 0xe);
    uStack_26 = *(undefined2 *)(param_1 + 0x10);
    uStack_24 = *(undefined2 *)(param_1 + 0x12);
    uStack_22 = *(undefined2 *)(param_1 + 0x18);
    uStack_20 = *(undefined2 *)(param_1 + 0x16);
    uStack_1e = 0;
    uStack_1c = zcl_packet_transfer_ownership(param_1);
    if (param_2 == (undefined4 *)0x0) {
      uStack_18 = 0;
      uStack_14 = 0;
    }
    else {
      uStack_18 = *param_2;
      uStack_14 = param_2[1];
    }
    af_intrp_data_request(local_30);
    uVar1 = err_to_zcl_status();
  }
  return uVar1;
}

