/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> groups.o -> groups_cluster_add_group_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 groups_cluster_add_group_cmd_handler(int param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  int unaff_s1;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  ushort uStack_14;
  short sStack_12;
  
  uStack_14 = 0;
  sStack_12 = -1;
  if ((param_1 == 0) || (unaff_s1 = param_2, param_2 == 0)) {
    param_1 = __assert_func(0,0,0,0);
  }
  uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
  af_read_le16_isra_0(*(undefined4 *)(param_1 + 0x24),&uStack_14,&sStack_12);
  if (uVar3 < uStack_14) {
    bVar1 = false;
    bVar2 = true;
  }
  else {
    bVar1 = *(char *)(param_1 + 0x20) == '\x05';
    if ((*(char *)(param_1 + 0x20) == '\x05') &&
       (iVar4 = ezb_zcl_is_identifying(*(undefined1 *)(param_1 + 0x15)), iVar4 == 0)) {
      bVar1 = true;
    }
    else if ((ushort)(sStack_12 - 1U) < 0xfff7) {
      aps_group_table_add(*(undefined1 *)(param_1 + 0x15));
      uVar5 = err_to_zcl_status();
      zmsg_append_u8(*(undefined4 *)(unaff_s1 + 0x24),uVar5);
      zmsg_append_le16(*(undefined4 *)(unaff_s1 + 0x24),sStack_12);
    }
    else {
      zmsg_append_u8(*(undefined4 *)(unaff_s1 + 0x24),0x87);
    }
    bVar2 = false;
  }
  uVar5 = 0xfe;
  if (*(ushort *)(param_1 + 0xc) < 0xfff8) {
    if ((bVar2) || (bVar1)) {
      uVar5 = zcl_packet_setup_default_response(unaff_s1,param_1);
    }
    else {
      uVar5 = zcl_packet_setup_response();
    }
  }
  return uVar5;
}

