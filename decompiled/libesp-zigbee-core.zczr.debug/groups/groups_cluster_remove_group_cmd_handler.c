/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_cluster_remove_group_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 groups_cluster_remove_group_cmd_handler(int param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 uVar5;
  uint unaff_s2;
  ushort uStack_16;
  ushort uStack_14;
  ushort uStack_12;
  
  uStack_12 = 0;
  uStack_14 = 0xffff;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/groups.c",0x1dd,
                  "groups_cluster_remove_group_cmd_handler","packet && rsp");
_L0:
    iVar3 = aps_group_table_find(unaff_s2);
    if (iVar3 == 0) {
      uVar5 = 0x8b;
    }
    else {
      aps_group_table_remove_group(uStack_14);
      uVar5 = 0;
    }
  }
  else {
    af_read_le16(*(undefined4 *)(param_1 + 0x24),&uStack_12,&uStack_14);
    uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    if (uVar2 < uStack_12) {
      bVar1 = true;
      goto _L0;
    }
    unaff_s2 = (uint)uStack_14;
    iVar3 = groups_check_group_id_is_valid(unaff_s2);
    if (iVar3 != 0) goto _L0;
    uVar5 = 0x87;
  }
  uStack_16 = CONCAT11(uStack_16._1_1_,uVar5);
  zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_16);
  uStack_16 = uStack_14;
  zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_16);
  bVar1 = false;
_L0:
  if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
    if (bVar1) {
      uVar4 = zcl_packet_setup_default_response(param_2,param_1);
    }
    else {
      uVar4 = zcl_packet_setup_response(param_2,param_1,3);
    }
  }
  else {
    uVar4 = 0xfe;
  }
  return uVar4;
}

