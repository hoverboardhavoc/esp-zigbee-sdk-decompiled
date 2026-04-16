/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> price.o -> ezb_zcl_price_publish_price_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_price_publish_price_cmd_req(ezb_zcl_price_publish_price_cmd_t *cmd_req)

{
  int iVar1;
  uint uVar2;
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
  if (cmd_req == (ezb_zcl_price_publish_price_cmd_t *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = zcl_packet_init(auStack_3c + 1,0);
    if ((iVar1 == 0) &&
       (iVar1 = zcl_cmd_to_packet(auStack_3c + 1,0,1,(cmd_req->cmd_ctrl).dis_default_rsp,0,0,0x700),
       iVar1 == 0)) {
      auStack_3c[0] = (cmd_req->payload).provider_id;
      iVar1 = zmsg_append_bytes(packet._32_4_,4,auStack_3c);
      if (iVar1 == 0) {
        uVar2 = (uint)(cmd_req->payload).rate_label[0];
        if (uVar2 < 0xd) {
          iVar1 = zmsg_append_bytes(packet._32_4_,uVar2 + 1,(cmd_req->payload).rate_label);
          if (iVar1 == 0) {
            auStack_3c[0] =
                 (uint)*(byte *)((int)&(cmd_req->payload).issuer_event_id + 3) << 0x18 |
                 *(uint *)((cmd_req->payload).rate_label + 0xc) >> 8;
            iVar1 = zmsg_append_bytes(packet._32_4_,4,auStack_3c);
            if (iVar1 == 0) {
              auStack_3c[0] =
                   (uint)*(byte *)((int)&(cmd_req->payload).current_time + 3) << 0x18 |
                   *(uint *)((int)&(cmd_req->payload).issuer_event_id + 3) >> 8;
              iVar1 = zmsg_append_bytes(packet._32_4_,4,auStack_3c);
              if (iVar1 == 0) {
                auStack_3c[0] = CONCAT31(auStack_3c[0]._1_3_,(cmd_req->payload).unit_of_measure);
                iVar1 = zmsg_append_bytes(packet._32_4_,1,auStack_3c);
                if (iVar1 == 0) {
                  auStack_3c[0] = CONCAT22(auStack_3c[0]._2_2_,(cmd_req->payload).currency);
                  iVar1 = zmsg_append_bytes(packet._32_4_,2,auStack_3c);
                  if (iVar1 == 0) {
                    uVar2 = *(uint *)&(cmd_req->payload).field_0x1c;
                    auStack_3c[0] =
                         CONCAT31(auStack_3c[0]._1_3_,
                                  (byte)(uVar2 >> 4) & 0xf | (byte)((uVar2 & 0xf) << 4));
                    iVar1 = zmsg_append_bytes(packet._32_4_,1,auStack_3c);
                    if (iVar1 == 0) {
                      uVar2 = *(uint *)&(cmd_req->payload).field_0x1c;
                      auStack_3c[0] =
                           CONCAT31(auStack_3c[0]._1_3_,
                                    (byte)((uVar2 >> 8 & 0xf) << 4) | (byte)(uVar2 >> 0xc) & 0xf);
                      iVar1 = zmsg_append_bytes(packet._32_4_,1,auStack_3c);
                      if (iVar1 == 0) {
                        auStack_3c[0] = (cmd_req->payload).start_time;
                        iVar1 = zmsg_append_bytes(packet._32_4_,4,auStack_3c);
                        if (iVar1 == 0) {
                          auStack_3c[0] =
                               CONCAT22(auStack_3c[0]._2_2_,(cmd_req->payload).duration_in_minutes);
                          iVar1 = zmsg_append_bytes(packet._32_4_,2,auStack_3c);
                          if (iVar1 == 0) {
                            auStack_3c[0] = (cmd_req->payload).price;
                            iVar1 = zmsg_append_bytes(packet._32_4_,4,auStack_3c);
                            if (iVar1 == 0) {
                              auStack_3c[0] =
                                   CONCAT31(auStack_3c[0]._1_3_,(cmd_req->payload).price_ratio);
                              iVar1 = zmsg_append_bytes(packet._32_4_,1,auStack_3c);
                              if (iVar1 == 0) {
                                auStack_3c[0] =
                                     (uint)*(byte *)((int)&(cmd_req->payload).generation_price + 3)
                                     << 0x18 | *(uint *)&(cmd_req->payload).price_ratio >> 8;
                                iVar1 = zmsg_append_bytes(packet._32_4_,4,auStack_3c);
                                if (iVar1 == 0) {
                                  auStack_3c[0] =
                                       CONCAT31(auStack_3c[0]._1_3_,
                                                (cmd_req->payload).generation_price_ratio);
                                  iVar1 = zmsg_append_bytes(packet._32_4_,1,auStack_3c);
                                  if (iVar1 == 0) {
                                    auStack_3c[0] = (cmd_req->payload).alternate_cost_delivered;
                                    iVar1 = zmsg_append_bytes(packet._32_4_,4,auStack_3c);
                                    if (iVar1 == 0) {
                                      auStack_3c[0] =
                                           CONCAT31(auStack_3c[0]._1_3_,
                                                    (cmd_req->payload).alternate_cost_unit);
                                      iVar1 = zmsg_append_bytes(packet._32_4_,1,auStack_3c);
                                      if (iVar1 == 0) {
                                        auStack_3c[0] =
                                             CONCAT31(auStack_3c[0]._1_3_,
                                                      (cmd_req->payload).
                                                      alternate_cost_trailing_digit);
                                        iVar1 = zmsg_append_bytes(packet._32_4_,1,auStack_3c);
                                        if (iVar1 == 0) {
                                          auStack_3c[0] =
                                               CONCAT31(auStack_3c[0]._1_3_,
                                                        (cmd_req->payload).
                                                        number_of_block_thresholds);
                                          iVar1 = zmsg_append_bytes(packet._32_4_,1,auStack_3c);
                                          if (iVar1 == 0) {
                                            auStack_3c[0] =
                                                 CONCAT31(auStack_3c[0]._1_3_,
                                                          (cmd_req->payload).price_control);
                                            iVar1 = zmsg_append_bytes(packet._32_4_,1,auStack_3c);
                                            if (iVar1 == 0) {
                                              auStack_3c[0] =
                                                   CONCAT31(auStack_3c[0]._1_3_,
                                                            (cmd_req->payload).
                                                            number_of_generation_tiers);
                                              iVar1 = zmsg_append_bytes(packet._32_4_,1,auStack_3c);
                                              if (iVar1 == 0) {
                                                auStack_3c[0] =
                                                     CONCAT31(auStack_3c[0]._1_3_,
                                                              (cmd_req->payload).generation_tier);
                                                iVar1 = zmsg_append_bytes(packet._32_4_,1,auStack_3c
                                                                         );
                                                if (iVar1 == 0) {
                                                  auStack_3c[0] =
                                                       CONCAT31(auStack_3c[0]._1_3_,
                                                                (cmd_req->payload).
                                                                extended_number_of_price_tiers);
                                                  iVar1 = zmsg_append_bytes(packet._32_4_,1,
                                                                            auStack_3c);
                                                  if (iVar1 == 0) {
                                                    auStack_3c[0] =
                                                         CONCAT31(auStack_3c[0]._1_3_,
                                                                  (cmd_req->payload).
                                                                  extended_price_tier);
                                                    iVar1 = zmsg_append_bytes(packet._32_4_,1,
                                                                              auStack_3c);
                                                    if (iVar1 == 0) {
                                                      auStack_3c[0] =
                                                           CONCAT31(auStack_3c[0]._1_3_,
                                                                    (cmd_req->payload).
                                                                    extended_register_tier);
                                                      iVar1 = zmsg_append_bytes(packet._32_4_,1,
                                                                                auStack_3c);
                                                      if (iVar1 == 0) {
                                                        zcl_packet_send(auStack_3c + 1,
                                                                        &(cmd_req->cmd_ctrl).cnf_ctx
                                                                       );
                                                        iVar1 = zcl_status_to_err();
                                                        if (iVar1 == 0) {
                                                          return 0;
                                                        }
                                                      }
                                                      else {
                                                        iVar1 = 1;
                                                      }
                                                    }
                                                    else {
                                                      iVar1 = 1;
                                                    }
                                                  }
                                                  else {
                                                    iVar1 = 1;
                                                  }
                                                }
                                                else {
                                                  iVar1 = 1;
                                                }
                                              }
                                              else {
                                                iVar1 = 1;
                                              }
                                            }
                                            else {
                                              iVar1 = 1;
                                            }
                                          }
                                          else {
                                            iVar1 = 1;
                                          }
                                        }
                                        else {
                                          iVar1 = 1;
                                        }
                                      }
                                      else {
                                        iVar1 = 1;
                                      }
                                    }
                                    else {
                                      iVar1 = 1;
                                    }
                                  }
                                  else {
                                    iVar1 = 1;
                                  }
                                }
                                else {
                                  iVar1 = 1;
                                }
                              }
                              else {
                                iVar1 = 1;
                              }
                            }
                            else {
                              iVar1 = 1;
                            }
                          }
                          else {
                            iVar1 = 1;
                          }
                        }
                        else {
                          iVar1 = 1;
                        }
                      }
                      else {
                        iVar1 = 1;
                      }
                    }
                    else {
                      iVar1 = 1;
                    }
                  }
                  else {
                    iVar1 = 1;
                  }
                }
                else {
                  iVar1 = 1;
                }
              }
              else {
                iVar1 = 1;
              }
            }
            else {
              iVar1 = 1;
            }
          }
          else {
            iVar1 = 1;
          }
        }
        else {
          iVar1 = 2;
        }
      }
      else {
        iVar1 = 1;
      }
    }
  }
  zcl_packet_free(auStack_3c + 1);
  return iVar1;
}

