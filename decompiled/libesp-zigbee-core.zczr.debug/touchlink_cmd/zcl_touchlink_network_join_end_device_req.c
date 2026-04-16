/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_network_join_end_device_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_touchlink_network_join_end_device_req(zcl_touchlink_join_end_device_req_t *cmd_req)

{
  ezb_address_t *unaff_s1;
  ezb_err_t eVar1;
  int iVar2;
  uint32_t uStack_3c;
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  auStack_38 = (undefined1  [4])0x0;
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
  if (cmd_req == (zcl_touchlink_join_end_device_req_t *)0x0) {
    eVar1 = -1;
  }
  else {
    iVar2 = zcl_packet_init(auStack_38,0);
    if (iVar2 == 0) {
      eVar1 = zcl_touchlink_cmd_to_packet((zcl_packet_t *)auStack_38,'\0','\x14',unaff_s1);
      if (eVar1 == 0) {
        uStack_3c = cmd_req->transaction_id;
        eVar1 = zmsg_append_bytes(packet._32_4_,4,&uStack_3c);
        if ((eVar1 == 0) &&
           (eVar1 = zmsg_append_bytes(packet._32_4_,8,&cmd_req->ext_panid), eVar1 == 0)) {
          uStack_3c = CONCAT31(uStack_3c._1_3_,cmd_req->key_index);
          eVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_3c);
          if ((eVar1 == 0) &&
             (eVar1 = zmsg_append_bytes(packet._32_4_,0x10,cmd_req->encrypted_nwk_key), eVar1 == 0))
          {
            uStack_3c = CONCAT31(uStack_3c._1_3_,cmd_req->update_id);
            eVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_3c);
            if (eVar1 == 0) {
              uStack_3c = CONCAT31(uStack_3c._1_3_,cmd_req->channel);
              eVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_3c);
              if (eVar1 == 0) {
                uStack_3c = CONCAT22(uStack_3c._2_2_,cmd_req->pan_id);
                eVar1 = zmsg_append_bytes(packet._32_4_,2,&uStack_3c);
                if (eVar1 == 0) {
                  uStack_3c = CONCAT22(uStack_3c._2_2_,cmd_req->new_nwk_addr);
                  eVar1 = zmsg_append_bytes(packet._32_4_,2,&uStack_3c);
                  if (eVar1 == 0) {
                    uStack_3c = CONCAT22(uStack_3c._2_2_,cmd_req->group_id_begin);
                    eVar1 = zmsg_append_bytes(packet._32_4_,2,&uStack_3c);
                    if (eVar1 == 0) {
                      uStack_3c = CONCAT22(uStack_3c._2_2_,cmd_req->group_id_end);
                      eVar1 = zmsg_append_bytes(packet._32_4_,2,&uStack_3c);
                      if (eVar1 == 0) {
                        uStack_3c = CONCAT22(uStack_3c._2_2_,cmd_req->free_nwk_addr_begin);
                        eVar1 = zmsg_append_bytes(packet._32_4_,2,&uStack_3c);
                        if (eVar1 == 0) {
                          uStack_3c = CONCAT22(uStack_3c._2_2_,cmd_req->free_nwk_addr_end);
                          eVar1 = zmsg_append_bytes(packet._32_4_,2,&uStack_3c);
                          if (eVar1 == 0) {
                            uStack_3c = CONCAT22(uStack_3c._2_2_,cmd_req->free_group_id_begin);
                            eVar1 = zmsg_append_bytes(packet._32_4_,2,&uStack_3c);
                            if (eVar1 == 0) {
                              uStack_3c = CONCAT22(uStack_3c._2_2_,cmd_req->free_group_id_end);
                              eVar1 = zmsg_append_bytes(packet._32_4_,2,&uStack_3c);
                              if (eVar1 == 0) {
                                zcl_packet_intrp_send(auStack_38,&cmd_req->cnf_ctx);
                                eVar1 = zcl_status_to_err();
                                if (eVar1 == 0) {
                                  return 0;
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    else {
      eVar1 = -1;
    }
  }
  zcl_packet_free(auStack_38);
  return eVar1;
}

