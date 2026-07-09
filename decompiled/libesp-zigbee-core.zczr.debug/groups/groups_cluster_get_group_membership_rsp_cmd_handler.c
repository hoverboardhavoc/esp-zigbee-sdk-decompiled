/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_cluster_get_group_membership_rsp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void groups_cluster_get_group_membership_rsp_cmd_handler(int param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 uVar2;
  void *pvVar3;
  byte local_24;
  undefined1 uStack_23;
  ushort auStack_22 [7];
  
  auStack_22[0] = 0;
  uStack_23 = 0;
  local_24 = 0;
  af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&uStack_23);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&local_24);
  uVar1 = (uint)local_24;
  pvVar3 = calloc(uVar1,2);
  if (uVar1 != 0) {
    if (pvVar3 == (void *)0x0) {
      uVar2 = 0x89;
      goto _L0;
    }
    uVar1 = 0;
  }
  for (; uVar1 < local_24; uVar1 = uVar1 + 1 & 0xff) {
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_22,(void *)(uVar1 * 2 + (int)pvVar3));
  }
  uVar1 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  if (uVar1 < auStack_22[0]) {
    uVar2 = 0x80;
  }
  else {
    uVar2 = zcl_message_groups_get_group_membership_resp(param_1,uStack_23,local_24,pvVar3);
  }
  if (pvVar3 != (void *)0x0) {
    mm_free(pvVar3);
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,uVar2);
  return;
}

