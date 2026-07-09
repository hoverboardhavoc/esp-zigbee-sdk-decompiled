/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> scenes_cluster_enhanced_view_scene_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 scenes_cluster_enhanced_view_scene_req_handler(int param_1,int param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  int unaff_s0;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int unaff_s4;
  undefined4 uVar7;
  ushort uStack_28;
  undefined1 local_25;
  ushort uStack_24;
  ushort auStack_22 [3];
  
  uVar1 = *(undefined1 *)(param_1 + 0x15);
  auStack_22[0] = 0;
  uStack_24 = 0;
  local_25 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/scenes.c",0x462,
                  "scenes_cluster_enhanced_view_scene_req_handler","packet && rsp");
_L0:
    uStack_28 = uStack_28 & 0xff00;
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_28);
  }
  else {
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_24);
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&local_25);
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    uVar2 = uStack_24;
    if (uVar4 < auStack_22[0]) {
      unaff_s4 = 0x80;
      goto _L0;
    }
    unaff_s4 = scenes_check_group_id(uStack_24);
    if (unaff_s4 != 0) goto _L0;
    unaff_s0 = scene_table_find_entry(uVar1,uVar2,local_25);
    if (unaff_s0 == 0) {
      unaff_s4 = 0x8b;
      goto _L0;
    }
    uStack_28 = uStack_28 & 0xff00;
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_28);
    uStack_28 = *(ushort *)(unaff_s0 + 2);
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_28);
    uStack_28 = CONCAT11(uStack_28._1_1_,*(undefined1 *)(unaff_s0 + 4));
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_28);
    uStack_28 = *(ushort *)(unaff_s0 + 6);
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_28);
    uStack_28 = CONCAT11(uStack_28._1_1_,*(char *)(unaff_s0 + 0x19) != '\0');
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_28);
    iVar5 = scene_name_is_supported(uVar1);
    if (iVar5 == 0) goto _L0;
    uVar7 = *(undefined4 *)(param_2 + 0x24);
    uVar6 = ezb_zcl_get_attr_value_size(0x42,unaff_s0 + 8);
    zmsg_append_bytes(uVar7,uVar6,unaff_s0 + 8);
  }
  for (puVar3 = *(undefined4 **)(unaff_s0 + 0x1c); puVar3 != (undefined4 *)0x0;
      puVar3 = (undefined4 *)*puVar3) {
    uStack_28 = *(ushort *)(puVar3 + 1);
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_28);
    uStack_28 = CONCAT11(uStack_28._1_1_,*(undefined1 *)((int)puVar3 + 6));
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_28);
    if (*(char *)((int)puVar3 + 6) != '\0') {
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),puVar3[2]);
    }
  }
_L0:
  if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
    if (unaff_s4 != 0) {
      uStack_28 = CONCAT11(uStack_28._1_1_,(char)unaff_s4);
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_28);
      uStack_28 = uStack_24;
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_28);
      uStack_28 = CONCAT11(uStack_28._1_1_,local_25);
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_28);
    }
    uVar6 = zcl_packet_setup_response(param_2,param_1,0x41);
  }
  else {
    uVar6 = 0xfe;
  }
  return uVar6;
}

