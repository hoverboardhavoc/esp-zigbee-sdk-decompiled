/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_cluster_view_group_rsp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void groups_cluster_view_group_rsp_cmd_handler(int param_1,undefined4 param_2)

{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined2 uStack_26;
  undefined1 uStack_23;
  ushort local_22 [7];
  
  local_22[0] = 0;
  uStack_23 = 0;
  uStack_26 = 0xffff;
  uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  af_read_le8(*(undefined4 *)(param_1 + 0x24),local_22,&uStack_23);
  af_read_le16(*(undefined4 *)(param_1 + 0x24),local_22,&uStack_26);
  uVar1 = local_22[0];
  if (local_22[0] <= uVar3) {
    sVar2 = groups_read_group_name(*(undefined4 *)(param_1 + 0x24),(uint)local_22[0],0);
    local_22[0] = uVar1 + sVar2;
  }
  if (uVar3 < local_22[0]) {
    uVar4 = 0x80;
  }
  else {
    uVar4 = zcl_message_groups_view_group_resp(param_1,uStack_23,uStack_26,0);
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar4);
  return;
}

