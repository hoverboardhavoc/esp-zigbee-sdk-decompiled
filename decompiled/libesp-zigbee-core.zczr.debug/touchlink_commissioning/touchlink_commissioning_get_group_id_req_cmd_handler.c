/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_commissioning.o -> touchlink_commissioning_get_group_id_req_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
touchlink_commissioning_get_group_id_req_cmd_handler(zcl_packet_t *packet,zcl_packet_t *resp)

{
  ushort *puVar1;
  byte bVar2;
  ezb_zcl_status_t eVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char cVar7;
  undefined2 uStack_36;
  byte bStack_33;
  uint16_t uStack_32;
  uint8_t start_index;
  uint16_t offset;
  
  uStack_32 = 0;
  bStack_33 = 0;
  if (packet == (zcl_packet_t *)0x0) {
    uVar6 = 0xfe;
  }
  else if (resp == (zcl_packet_t *)0x0) {
    uVar6 = 0xfe;
  }
  else {
    uVar4 = zmsg_get_length(packet->payload);
    af_read_le8(packet->payload,&uStack_32,&bStack_33);
    if (uStack_32 <= uVar4) {
      uVar6 = zmsg_get_length(resp->payload);
      uStack_36._0_1_ = 0;
      zmsg_append_bytes(resp->payload,1,&uStack_36);
      uStack_36._0_1_ = bStack_33;
      zmsg_append_bytes(resp->payload,1,&uStack_36);
      uVar5 = zmsg_get_length(resp->payload);
      uStack_36 = (ushort)uStack_36._1_1_ << 8;
      zmsg_append_bytes(resp->payload,1,&uStack_36);
      cVar7 = '\0';
      bVar2 = 0;
      puVar1 = (ushort *)0x0;
      while (puVar1 = (ushort *)aps_group_table_next_by_endpoint((packet->header).dst_ep,puVar1),
            puVar1 != (ushort *)0x0) {
        if (bStack_33 <= bVar2) {
          uStack_36 = *puVar1;
          zmsg_append_bytes(resp->payload,2,&uStack_36);
          uStack_36 = uStack_36 & 0xff00;
          zmsg_append_bytes(resp->payload,1,&uStack_36);
          cVar7 = cVar7 + '\x01';
        }
        bVar2 = bVar2 + 1;
      }
      uStack_36._0_1_ = bVar2;
      zmsg_write_bytes(resp->payload,uVar6,1,&uStack_36);
      uStack_36 = CONCAT11(uStack_36._1_1_,cVar7);
      zmsg_write_bytes(resp->payload,uVar5,1,&uStack_36);
      eVar3 = zcl_packet_setup_response(resp,packet,0x41);
      return eVar3;
    }
    uVar6 = 0x80;
  }
  eVar3 = zcl_packet_setup_default_response(resp,packet,uVar6);
  return eVar3;
}

