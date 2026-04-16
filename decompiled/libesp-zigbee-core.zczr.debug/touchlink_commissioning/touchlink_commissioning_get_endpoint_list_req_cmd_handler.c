/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_commissioning.o -> touchlink_commissioning_get_endpoint_list_req_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
touchlink_commissioning_get_endpoint_list_req_cmd_handler(zcl_packet_t *packet,zcl_packet_t *resp)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  ezb_zcl_status_t eVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  char cVar8;
  byte bVar9;
  zcl_packet_payload_t *pzVar10;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  ezb_zcl_touchlink_get_ep_list_rsp_t rsp;
  uint8_t start_index;
  uint16_t offset;
  
  rsp.records._2_2_ = 0;
  rsp.records._1_1_ = 0;
  uStack_2c = 0;
  rsp.total = '\0';
  rsp.start_index = '\0';
  rsp.count = '\0';
  rsp._3_1_ = 0;
  if (packet == (zcl_packet_t *)0x0) {
    uVar7 = 0xfe;
  }
  else if (resp == (zcl_packet_t *)0x0) {
    uVar7 = 0xfe;
  }
  else {
    uVar5 = zmsg_get_length(packet->payload);
    af_read_le8(packet->payload,(uint16_t *)((int)&rsp.records + 2),
                (uint8_t *)((int)&rsp.records + 1));
    bVar9 = rsp.records._1_1_;
    if (rsp.records._2_2_ <= uVar5) {
      uStack_2c._0_2_ = CONCAT11(rsp.records._1_1_,(char)uStack_2c);
      iVar2 = 0;
      while( true ) {
        iVar2 = ezb_af_get_next_simple_desc(iVar2);
        if (iVar2 == 0) break;
        uStack_2c = CONCAT31(uStack_2c._1_3_,(char)uStack_2c + '\x01');
      }
      uStack_2e._0_1_ = (char)uStack_2c;
      zmsg_append_bytes(resp->payload,1,&uStack_2e);
      uStack_2e._0_1_ = bVar9;
      zmsg_append_bytes(resp->payload,1,&uStack_2e);
      uStack_2e = (ushort)uStack_2e._1_1_ << 8;
      zmsg_append_bytes(resp->payload,1,&uStack_2e);
      puVar6 = (undefined1 *)0x0;
      bVar9 = 0;
      while (puVar6 = (undefined1 *)ezb_af_get_next_simple_desc(puVar6), puVar6 != (undefined1 *)0x0
            ) {
        bVar3 = bVar9 + 1;
        bVar1 = rsp.records._1_1_ <= bVar9;
        bVar9 = bVar3;
        if (bVar1) {
          pzVar10 = resp->payload;
          uStack_2e = nwk_get_short_address();
          zmsg_append_bytes(pzVar10,2,&uStack_2e);
          uStack_2e = CONCAT11(uStack_2e._1_1_,*puVar6);
          zmsg_append_bytes(resp->payload,1,&uStack_2e);
          uStack_2e = *(ushort *)(puVar6 + 2);
          zmsg_append_bytes(resp->payload,2,&uStack_2e);
          uStack_2e = *(ushort *)(puVar6 + 4);
          zmsg_append_bytes(resp->payload,2,&uStack_2e);
          uStack_2e = CONCAT11(uStack_2e._1_1_,(char)*(undefined2 *)(puVar6 + 6)) & 0xff0f;
          zmsg_append_bytes(resp->payload,1,&uStack_2e);
          cVar8 = uStack_2c._2_1_ + '\x01';
          uStack_2c._0_3_ = CONCAT12(cVar8,(undefined2)uStack_2c);
        }
      }
      uStack_2e = CONCAT11(uStack_2e._1_1_,uStack_2c._2_1_);
      zmsg_write_bytes(resp->payload,2,1,&uStack_2e);
      eVar4 = zcl_packet_setup_response(resp,packet,0x42);
      return eVar4;
    }
    uVar7 = 0x80;
  }
  eVar4 = zcl_packet_setup_default_response(resp,packet,uVar7);
  return eVar4;
}

