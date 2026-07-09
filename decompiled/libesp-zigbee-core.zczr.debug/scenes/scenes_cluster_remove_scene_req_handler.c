/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_remove_scene_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 scenes_cluster_remove_scene_req_handler(int param_1,int param_2)

{
  undefined1 uVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined2 uStack_28;
  undefined1 local_25;
  undefined2 uStack_24;
  ushort auStack_22 [5];
  
  uVar1 = *(undefined1 *)(param_1 + 0x15);
  auStack_22[0] = 0;
  uStack_24 = 0;
  local_25 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x2fc,
                  "scenes_cluster_remove_scene_req_handler","packet && rsp");
  }
  else {
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_24);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&local_25);
    uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar2 = uStack_24;
    if (auStack_22[0] <= uVar3) {
      iVar4 = scenes_check_group_id(uStack_24);
      if (iVar4 == 0) {
        iVar5 = scene_table_find_entry(uVar1,uVar2,local_25);
        if (iVar5 == 0) {
          iVar4 = 0x8b;
        }
        else {
          scene_table_remove_entry(uVar1,iVar5);
        }
      }
      goto _L0;
    }
  }
  iVar4 = 0x80;
_L0:
  if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
    uStack_28 = CONCAT11(uStack_28._1_1_,(char)iVar4);
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_28);
    uStack_28 = uStack_24;
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_28);
    uStack_28 = CONCAT11(uStack_28._1_1_,local_25);
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_28);
    uVar6 = zcl_packet_setup_response(param_2,param_1,2);
  }
  else {
    uVar6 = 0xfe;
  }
  return uVar6;
}

