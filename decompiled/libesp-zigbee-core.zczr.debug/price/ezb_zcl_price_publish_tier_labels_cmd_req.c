/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> price.o -> ezb_zcl_price_publish_tier_labels_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: packet */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_price_publish_tier_labels_cmd_req
                    (ezb_zcl_price_publish_tier_labels_cmd_t *cmd_req)

{
  uint8_t uVar1;
  ezb_err_t eVar2;
  int iVar3;
  uint uVar4;
  ezb_zcl_price_tier_label_entry_t *peVar5;
  uint uVar6;
  uint32_t auStack_3c [2];
  zcl_packet_t packet;
  
  auStack_3c[1] = 0;
  packet.header.src_addr._0_4_ = 0;
  packet.header.src_addr.u._2_4_ = 0;
  packet.header._8_4_ = 0;
  packet.header.dst_addr.u._0_2_ = 0;
  packet.header.dst_addr.u._2_2_ = 0;
  packet.header.dst_addr.u._4_4_ = 0;
  packet.header.src_ep = '\0';
  packet.header.dst_ep = '\0';
  packet.header.cluster_id = 0;
  packet.header.profile_id = 0;
  packet.header.fc = '\0';
  packet.header._27_1_ = 0;
  packet.header.manuf_code = 0;
  packet.header.tsn = '\0';
  packet.header.rssi = '\0';
  packet.header.cmd_id = '\0';
  packet.header._33_1_ = 0;
  packet._34_2_ = 0;
  if (cmd_req == (ezb_zcl_price_publish_tier_labels_cmd_t *)0x0) {
    eVar2 = -1;
  }
  else {
    iVar3 = zcl_packet_init(auStack_3c + 1,0);
    if (iVar3 == 0) {
      eVar2 = zcl_cmd_to_packet(auStack_3c + 1,0,1,(cmd_req->cmd_ctrl).dis_default_rsp,0,8,0x700);
      if (eVar2 == 0) {
        auStack_3c[0] = (cmd_req->payload).provider_id;
        iVar3 = zmsg_append_bytes(packet._32_4_,4,auStack_3c);
        if (iVar3 == 0) {
          auStack_3c[0] = (cmd_req->payload).issuer_event_id;
          iVar3 = zmsg_append_bytes(packet._32_4_,4,auStack_3c);
          if (iVar3 == 0) {
            auStack_3c[0] = (cmd_req->payload).issuer_tariff_id;
            iVar3 = zmsg_append_bytes(packet._32_4_,4,auStack_3c);
            if (iVar3 == 0) {
              auStack_3c[0] = CONCAT31(auStack_3c[0]._1_3_,(cmd_req->payload).command_index);
              iVar3 = zmsg_append_bytes(packet._32_4_,1,auStack_3c);
              if (iVar3 == 0) {
                auStack_3c[0] =
                     CONCAT31(auStack_3c[0]._1_3_,(cmd_req->payload).total_number_of_commands);
                iVar3 = zmsg_append_bytes(packet._32_4_,1,auStack_3c);
                if (iVar3 == 0) {
                  uVar1 = (cmd_req->payload).number_of_labels;
                  if (uVar1 == '\0') {
                    eVar2 = 2;
                  }
                  else if ((cmd_req->payload).tier_labels == (ezb_zcl_price_tier_label_entry_t *)0x0
                          ) {
                    eVar2 = 2;
                  }
                  else {
                    auStack_3c[0] = CONCAT31(auStack_3c[0]._1_3_,uVar1);
                    iVar3 = zmsg_append_bytes(packet._32_4_,1,auStack_3c);
                    uVar6 = 0;
                    if (iVar3 == 0) {
                      for (; uVar6 < (cmd_req->payload).number_of_labels; uVar6 = uVar6 + 1 & 0xff)
                      {
                        auStack_3c[0] =
                             CONCAT31(auStack_3c[0]._1_3_,
                                      (cmd_req->payload).tier_labels[uVar6].tier_id);
                        iVar3 = zmsg_append_bytes(packet._32_4_,1,auStack_3c);
                        if (iVar3 != 0) {
                          eVar2 = 1;
                          goto _L0;
                        }
                        peVar5 = (cmd_req->payload).tier_labels;
                        uVar4 = (uint)peVar5[uVar6].tier_label[0];
                        if (0xc < uVar4) {
                          eVar2 = 2;
                          goto _L0;
                        }
                        iVar3 = zmsg_append_bytes(packet._32_4_,uVar4 + 1,peVar5[uVar6].tier_label);
                        if (iVar3 != 0) {
                          eVar2 = 1;
                          goto _L0;
                        }
                      }
                      zcl_packet_send(auStack_3c + 1,&(cmd_req->cmd_ctrl).cnf_ctx);
                      eVar2 = zcl_status_to_err();
                      if (eVar2 == 0) {
                        return 0;
                      }
                    }
                    else {
                      eVar2 = 1;
                    }
                  }
                }
                else {
                  eVar2 = 1;
                }
              }
              else {
                eVar2 = 1;
              }
            }
            else {
              eVar2 = 1;
            }
          }
          else {
            eVar2 = 1;
          }
        }
        else {
          eVar2 = 1;
        }
      }
    }
    else {
      eVar2 = -1;
    }
  }
_L0:
  zcl_packet_free(auStack_3c + 1);
  return eVar2;
}

