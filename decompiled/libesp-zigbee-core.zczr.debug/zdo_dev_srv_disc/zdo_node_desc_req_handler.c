/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_node_desc_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_node_desc_req_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  uint uVar1;
  undefined2 *puVar2;
  zdp_status_t zVar3;
  undefined3 extraout_var;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint16_t uStack_2a;
  undefined1 auStack_28 [2];
  uint16_t short_addr;
  zdp_node_desc_rsp_field_t rsp;
  zdp_node_desc_req_field_t req;
  
  rsp.node_desc.max_outgoing_transfer_size = 0;
  auStack_28[0] = '\0';
  auStack_28[1] = 0;
  short_addr = 0;
  rsp.status = '\0';
  rsp._1_1_ = 0;
  rsp.nwk_addr_of_interest = 0;
  rsp.node_desc.node_flags = 0;
  rsp.node_desc.mac_capability_flags = '\0';
  rsp.node_desc._3_1_ = 0;
  rsp.node_desc.manufacturer_code = 0;
  rsp.node_desc.max_buf_size = '\0';
  rsp.node_desc._7_1_ = 0;
  rsp.node_desc.max_incoming_transfer_size = 0;
  rsp.node_desc.server_mask = 0;
  if (packet == (zdo_packet_t *)0x0) {
    zVar3 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    zVar3 = 0xfe;
  }
  else if (resp == (zdo_packet_t *)0x0) {
    zVar3 = 0xfe;
  }
  else {
    zVar3 = zdo_op_node_desc_req
                      (packet->payload,
                       (zdp_node_desc_req_field_t *)&rsp.node_desc.max_outgoing_transfer_size,false)
    ;
    if (CONCAT31(extraout_var,zVar3) == 0) {
      uVar1 = (uint)rsp.node_desc.max_outgoing_transfer_size;
      if (uVar1 < 0xfff8) {
        _auStack_28 = CONCAT22(rsp.node_desc.max_outgoing_transfer_size,auStack_28);
        uVar4 = nwk_get_short_address();
        if (uVar1 == uVar4) {
          _auStack_28 = _auStack_28 & 0xffffff00;
        }
        else {
          iVar5 = nwk_is_device_zed();
          if (iVar5 == 0) {
            _auStack_28 = CONCAT31(stack0xffffffd9,0x81);
            puVar2 = (undefined2 *)0x0;
            do {
              do {
                puVar2 = (undefined2 *)nwk_neighbor_table_next(puVar2);
                if (puVar2 == (undefined2 *)0x0) goto _L0;
              } while ((*(uint *)(puVar2 + 6) & 3) != 2);
              uStack_2a = 0xffff;
              nwk_address_short_by_ref(*puVar2,&uStack_2a);
            } while (rsp.node_desc.max_outgoing_transfer_size != uStack_2a);
          }
          else {
            _auStack_28 = CONCAT31(stack0xffffffd9,0x80);
          }
        }
_L0:
        rsp.status = '\0';
        rsp._1_1_ = 0;
        rsp.nwk_addr_of_interest = 0;
        rsp.node_desc.node_flags = 0;
        rsp.node_desc.mac_capability_flags = '\0';
        rsp.node_desc._3_1_ = 0;
        rsp.node_desc.manufacturer_code = 0;
        rsp.node_desc.max_buf_size = '\0';
        rsp.node_desc._7_1_ = 0;
        rsp.node_desc.max_incoming_transfer_size = 0;
        rsp.node_desc.server_mask = 0;
        if (((_auStack_28 & 0xff) == 0) &&
           (puVar6 = (undefined4 *)af_get_node_desc(), puVar6 != (undefined4 *)0x0)) {
          rsp._0_4_ = *puVar6;
          rsp.node_desc._0_4_ = puVar6[1];
          rsp.node_desc._4_4_ = puVar6[2];
          rsp.node_desc._8_4_ = puVar6[3];
        }
        zVar3 = zdo_op_node_desc_rsp(resp->payload,(zdp_node_desc_rsp_field_t *)auStack_28,true);
      }
      else {
        zVar3 = 0x8b;
      }
    }
    else {
      zVar3 = 0xfe;
    }
  }
  return zVar3;
}

