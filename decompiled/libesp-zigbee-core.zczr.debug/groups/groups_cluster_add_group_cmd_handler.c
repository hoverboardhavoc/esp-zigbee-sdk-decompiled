/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_cluster_add_group_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 groups_cluster_add_group_cmd_handler(int param_1,int param_2)

{
  bool bVar1;
  undefined2 uVar2;
  ushort uVar3;
  undefined1 uVar4;
  short sVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint unaff_s2;
  undefined2 uStack_26;
  undefined2 uStack_24;
  ushort auStack_22 [7];
  
  auStack_22[0] = 0;
  uStack_24 = 0xffff;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/groups.c",0x100,
                  "groups_cluster_add_group_cmd_handler","packet && rsp");
_L0:
    iVar7 = ezb_zcl_is_identifying(*(undefined1 *)(param_1 + 0x15));
    if (iVar7 == 0) {
      bVar1 = false;
      goto _L0;
    }
  }
  else {
    uVar6 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_24);
    uVar3 = auStack_22[0];
    if (auStack_22[0] < uVar6) {
      sVar5 = groups_read_group_name(*(undefined4 *)(param_1 + 0x24),(uint)auStack_22[0],0);
      auStack_22[0] = uVar3 + sVar5;
    }
    if (uVar6 < auStack_22[0]) {
      unaff_s2 = 0;
      bVar1 = true;
      goto _L0;
    }
    unaff_s2 = (uint)(*(char *)(param_1 + 0x20) == '\x05');
    if (*(char *)(param_1 + 0x20) == '\x05') goto _L0;
  }
  uVar2 = uStack_24;
  iVar7 = groups_check_group_id_is_valid(uStack_24);
  if (iVar7 == 0) {
    uStack_26 = CONCAT11(uStack_26._1_1_,0x87);
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_26);
    bVar1 = false;
  }
  else {
    aps_group_table_add(uVar2,*(undefined1 *)(param_1 + 0x15));
    uVar4 = err_to_zcl_status();
    uStack_26 = CONCAT11(uStack_26._1_1_,uVar4);
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_26);
    uStack_26 = uStack_24;
    zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_26);
    bVar1 = false;
  }
_L0:
  if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
    if ((bVar1) || (unaff_s2 != 0)) {
      uVar8 = zcl_packet_setup_default_response(param_2,param_1);
    }
    else {
      uVar8 = zcl_packet_setup_response(param_2,param_1);
    }
  }
  else {
    uVar8 = 0xfe;
  }
  return uVar8;
}

