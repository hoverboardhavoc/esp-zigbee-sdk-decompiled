/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_commissioning.o -> touchlink_commissioning_get_group_id_req_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_commissioning_get_group_id_req_cmd_handler(int param_1,int param_2)

{
  ushort *puVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char cVar6;
  undefined2 uStack_36;
  byte bStack_33;
  ushort auStack_32 [7];
  
  auStack_32[0] = 0;
  bStack_33 = 0;
  if (param_1 == 0) {
    uVar5 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar5 = 0xfe;
  }
  else {
    uVar3 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_32,&bStack_33);
    if (auStack_32[0] <= uVar3) {
      uVar5 = zmsg_get_length(*(undefined4 *)(param_2 + 0x24));
      uStack_36._0_1_ = 0;
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_36);
      uStack_36._0_1_ = bStack_33;
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_36);
      uVar4 = zmsg_get_length(*(undefined4 *)(param_2 + 0x24));
      uStack_36 = (ushort)uStack_36._1_1_ << 8;
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_36);
      cVar6 = '\0';
      bVar2 = 0;
      puVar1 = (ushort *)0x0;
      while (puVar1 = (ushort *)
                      aps_group_table_next_by_endpoint(*(undefined1 *)(param_1 + 0x15),puVar1),
            puVar1 != (ushort *)0x0) {
        if (bStack_33 <= bVar2) {
          uStack_36 = *puVar1;
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_36);
          uStack_36 = uStack_36 & 0xff00;
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_36);
          cVar6 = cVar6 + '\x01';
        }
        bVar2 = bVar2 + 1;
      }
      uStack_36._0_1_ = bVar2;
      zmsg_write_bytes(*(undefined4 *)(param_2 + 0x24),uVar5,1,&uStack_36);
      uStack_36 = CONCAT11(uStack_36._1_1_,cVar6);
      zmsg_write_bytes(*(undefined4 *)(param_2 + 0x24),uVar4,1,&uStack_36);
      zcl_packet_setup_response(param_2,param_1,0x41);
      return;
    }
    uVar5 = 0x80;
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar5);
  return;
}

