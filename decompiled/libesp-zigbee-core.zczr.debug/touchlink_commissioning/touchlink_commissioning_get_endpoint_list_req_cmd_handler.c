/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_commissioning.o -> touchlink_commissioning_get_endpoint_list_req_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_commissioning_get_endpoint_list_req_cmd_handler(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  undefined1 *puVar5;
  char cVar6;
  byte bVar7;
  undefined4 uVar8;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  byte bStack_23;
  ushort auStack_22 [3];
  
  auStack_22[0] = 0;
  bStack_23 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  if (param_1 == 0) {
    uVar8 = 0xfe;
  }
  else if (param_2 == 0) {
    uVar8 = 0xfe;
  }
  else {
    uVar4 = zmsg_get_length(*(undefined4 *)(param_1 + 0x24));
    af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&bStack_23);
    bVar7 = bStack_23;
    if (auStack_22[0] <= uVar4) {
      uStack_2c._0_2_ = CONCAT11(bStack_23,(char)uStack_2c);
      iVar2 = 0;
      while( true ) {
        iVar2 = ezb_af_get_next_simple_desc(iVar2);
        if (iVar2 == 0) break;
        uStack_2c = CONCAT31(uStack_2c._1_3_,(char)uStack_2c + '\x01');
      }
      uStack_2e._0_1_ = (char)uStack_2c;
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_2e);
      uStack_2e._0_1_ = bVar7;
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_2e);
      uStack_2e = (ushort)uStack_2e._1_1_ << 8;
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_2e);
      puVar5 = (undefined1 *)0x0;
      bVar7 = 0;
      while (puVar5 = (undefined1 *)ezb_af_get_next_simple_desc(puVar5), puVar5 != (undefined1 *)0x0
            ) {
        bVar3 = bVar7 + 1;
        bVar1 = bStack_23 <= bVar7;
        bVar7 = bVar3;
        if (bVar1) {
          uVar8 = *(undefined4 *)(param_2 + 0x24);
          uStack_2e = nwk_get_short_address();
          zmsg_append_bytes(uVar8,2,&uStack_2e);
          uStack_2e = CONCAT11(uStack_2e._1_1_,*puVar5);
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_2e);
          uStack_2e = *(ushort *)(puVar5 + 2);
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_2e);
          uStack_2e = *(ushort *)(puVar5 + 4);
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_2e);
          uStack_2e = CONCAT11(uStack_2e._1_1_,(char)*(undefined2 *)(puVar5 + 6)) & 0xff0f;
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_2e);
          cVar6 = uStack_2c._2_1_ + '\x01';
          uStack_2c._0_3_ = CONCAT12(cVar6,(undefined2)uStack_2c);
        }
      }
      uStack_2e = CONCAT11(uStack_2e._1_1_,uStack_2c._2_1_);
      zmsg_write_bytes(*(undefined4 *)(param_2 + 0x24),2,1,&uStack_2e);
      zcl_packet_setup_response(param_2,param_1,0x42);
      return;
    }
    uVar8 = 0x80;
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar8);
  return;
}

