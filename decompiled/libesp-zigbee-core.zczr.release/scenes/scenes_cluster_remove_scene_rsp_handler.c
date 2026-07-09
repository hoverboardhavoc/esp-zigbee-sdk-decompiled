/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> scenes.o -> scenes_cluster_remove_scene_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void scenes_cluster_remove_scene_rsp_handler(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 uStack_16;
  undefined1 uStack_15;
  ushort uStack_14;
  undefined2 auStack_12 [3];
  
  uStack_14 = 0;
  uStack_16 = 0;
  auStack_12[0] = 0;
  uStack_15 = 0;
  af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_14,&uStack_16);
  af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_14,auStack_12);
  af_read_le8_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_14,&uStack_15);
  uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  uVar2 = 0x80;
  if (uStack_14 <= uVar1) {
    uVar2 = zcl_message_scenes_op_scene_resp(param_1,uStack_16,auStack_12[0],uStack_15);
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

