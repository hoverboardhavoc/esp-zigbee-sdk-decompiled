/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_remove_all_scenes_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 scenes_cluster_remove_all_scenes_req_handler(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 uStack_26;
  undefined2 uStack_24;
  ushort auStack_22 [7];
  
  uVar1 = *(undefined1 *)(param_1 + 0x15);
  auStack_22[0] = 0;
  uStack_24 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x31b,
                  "scenes_cluster_remove_all_scenes_req_handler","packet && rsp");
  }
  else {
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_24);
    uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar2 = uStack_24;
    if (auStack_22[0] <= uVar3) {
      iVar4 = scenes_check_group_id(uStack_24);
      if (iVar4 == 0) {
        iVar4 = scene_table_remove_all_associated_scene(uVar1,uVar2);
      }
      goto _L0;
    }
  }
  iVar4 = 0x80;
_L0:
  uStack_26 = CONCAT11(uStack_26._1_1_,(char)iVar4);
  zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_26);
  uStack_26 = uStack_24;
  zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_26);
  if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
    uVar5 = zcl_packet_setup_response(param_2,param_1,3);
  }
  else {
    uVar5 = 0xfe;
  }
  return uVar5;
}

