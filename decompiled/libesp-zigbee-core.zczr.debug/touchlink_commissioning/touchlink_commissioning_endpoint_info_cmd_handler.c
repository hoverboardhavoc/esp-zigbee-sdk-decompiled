/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_commissioning.o -> touchlink_commissioning_endpoint_info_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_commissioning_endpoint_info_cmd_handler(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  ushort auStack_22 [7];
  
  auStack_22[0] = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  if (param_1 == 0) {
    uVar2 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar2 = 0xfe;
  }
  else {
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_bytes(*(undefined4 *)(param_1 + 0x24),auStack_22,8,&uStack_34);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_2c);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_2c + 2);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_28);
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(int)&uStack_28 + 2);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_24);
    if (uVar1 < auStack_22[0]) {
      uVar2 = 0x80;
    }
    else {
      uVar2 = zcl_message_to_touchlink_ep_info(param_1,&uStack_34);
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

