/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_store_scene_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void scenes_cluster_store_scene_rsp_handler(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 uStack_17;
  undefined2 uStack_16;
  undefined1 uStack_13;
  ushort uStack_12;
  
  uStack_12 = 0;
  uStack_13 = 0;
  uStack_16 = 0;
  uStack_17 = 0;
  af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_13);
  af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_16);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_17);
  uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  if (uVar1 < uStack_12) {
    uVar2 = 0x80;
  }
  else {
    uVar2 = zcl_message_scenes_op_scene_resp(param_1,uStack_13,uStack_16,uStack_17);
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

