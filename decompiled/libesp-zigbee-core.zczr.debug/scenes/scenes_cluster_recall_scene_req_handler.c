/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_recall_scene_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 scenes_cluster_recall_scene_req_handler(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined2 uStack_18;
  undefined1 local_15;
  undefined2 uStack_14;
  ushort uStack_12;
  
  uStack_12 = 0;
  uStack_14 = 0;
  local_15 = 0;
  uStack_18 = 0xffff;
  af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_14);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),&uStack_12,&local_15);
  uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  if (uStack_12 < uVar1) {
    af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_18);
  }
  uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  if (uVar1 < uStack_12) {
    uVar2 = 0x80;
  }
  else {
    uVar2 = zcl_scenes_recall_scene(param_1,uStack_14,local_15,uStack_18);
  }
  if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
    uVar2 = zcl_packet_setup_default_response(param_2,param_1,uVar2);
  }
  else {
    uVar2 = 0xfe;
  }
  return uVar2;
}

