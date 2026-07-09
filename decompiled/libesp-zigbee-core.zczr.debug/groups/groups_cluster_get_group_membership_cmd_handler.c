/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> groups.o -> groups_cluster_get_group_membership_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void groups_cluster_get_group_membership_cmd_handler(int param_1,int param_2)

{
  uint unaff_s0;
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  void *unaff_s2;
  char cVar5;
  uint unaff_s5;
  short *psVar6;
  undefined2 uStack_36;
  byte bStack_33;
  ushort auStack_32 [7];
  
  auStack_32[0] = 0;
  bStack_33 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/groups.c",0x18d,
                  "groups_cluster_get_group_membership_cmd_handler","packet && rsp");
    goto _L0;
  }
  unaff_s5 = (uint)*(byte *)(param_1 + 0x15);
  af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_32,&bStack_33);
  unaff_s0 = (uint)bStack_33;
  unaff_s2 = calloc(unaff_s0,2);
  if (unaff_s0 != 0) {
    if (unaff_s2 == (void *)0x0) {
      uVar4 = 0xfe;
      goto _L0;
    }
    unaff_s0 = 0;
  }
  for (; unaff_s0 < bStack_33; unaff_s0 = unaff_s0 + 1 & 0xff) {
_L0:
    af_read_le16(*(undefined4 *)(param_1 + 0x24),auStack_32,(void *)(unaff_s0 * 2 + (int)unaff_s2));
  }
  uVar2 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  if (uVar2 < auStack_32[0]) {
    uVar4 = 0x80;
_L0:
    zcl_packet_setup_default_response(param_2,param_1,uVar4);
    return;
  }
  uVar4 = *(undefined4 *)(param_2 + 0x24);
  uVar1 = aps_group_table_get_free_size();
  uStack_36._0_1_ = uVar1;
  zmsg_append_bytes(uVar4,1,&uStack_36);
  uVar4 = zmsg_get_length(*(undefined4 *)(param_2 + 0x24));
  uStack_36 = (ushort)uStack_36._1_1_ << 8;
  zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_36);
  if (bStack_33 == 0) {
    psVar6 = (short *)0x0;
    cVar5 = '\0';
    while (psVar6 = (short *)aps_group_table_next_by_endpoint(unaff_s5,psVar6),
          psVar6 != (short *)0x0) {
      uStack_36 = *psVar6;
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_36);
      cVar5 = cVar5 + '\x01';
    }
  }
  else {
    cVar5 = '\0';
    for (uVar2 = 0; uVar2 < bStack_33; uVar2 = uVar2 + 1 & 0xff) {
      psVar6 = (short *)(uVar2 * 2 + (int)unaff_s2);
      iVar3 = aps_group_table_find(*psVar6);
      if ((iVar3 != 0) &&
         (iVar3 = aps_group_table_is_endpoint_in_group(unaff_s5,*psVar6), iVar3 != 0)) {
        uStack_36 = *psVar6;
        zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_36);
        cVar5 = cVar5 + '\x01';
      }
    }
    if ((cVar5 != '\0') && (0xfff7 < *(ushort *)(param_1 + 0xc))) {
      uVar4 = 0xfe;
      goto _L0;
    }
  }
  uStack_36 = CONCAT11(uStack_36._1_1_,cVar5);
  zmsg_write_bytes(*(undefined4 *)(param_2 + 0x24),uVar4,1,&uStack_36);
  zcl_packet_setup_response(param_2,param_1,2);
  return;
}

