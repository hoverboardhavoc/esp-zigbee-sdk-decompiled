/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_cluster_view_group_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void groups_cluster_view_group_cmd_handler(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  char cVar4;
  uint unaff_s2;
  ushort uStack_26;
  ushort uStack_24;
  ushort auStack_22 [7];
  
  auStack_22[0] = 0;
  uStack_24 = 0xffff;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/groups.c",0x148,
                  "groups_cluster_view_group_cmd_handler","packet && rsp");
_L0:
    iVar2 = aps_group_table_is_endpoint_in_group(*(undefined1 *)(param_1 + 0x15),unaff_s2);
    if (iVar2 == 0) {
      cVar4 = -0x75;
    }
    else {
      cVar4 = '\0';
    }
_L0:
    uStack_26 = CONCAT11(uStack_26._1_1_,cVar4);
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_26);
    uStack_26 = uStack_24;
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_26);
    if (cVar4 == '\0') {
      groups_append_group_name(*(undefined4 *)(param_2 + 0x24),0,0);
    }
    else {
      uStack_26 = uStack_26 & 0xff00;
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_26);
    }
    zcl_packet_setup_response(param_2,param_1,1);
  }
  else {
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_24);
    uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar1 < auStack_22[0]) {
      uVar3 = 0x80;
    }
    else {
      if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
        unaff_s2 = (uint)uStack_24;
        iVar2 = groups_check_group_id_is_valid(unaff_s2);
        if (iVar2 != 0) goto _L0;
        cVar4 = -0x79;
        goto _L0;
      }
      uVar3 = 0xfe;
    }
    zcl_packet_setup_default_response(param_2,param_1,uVar3);
  }
  return;
}

