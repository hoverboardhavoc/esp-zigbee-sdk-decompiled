/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> ezb_zcl_color_control_color_loop_set_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_color_control_color_loop_set_cmd_req
                    (ezb_zcl_color_control_color_loop_set_cmd_t *cmd_req)

{
  ezb_err_t eVar1;
  int iVar2;
  uint16_t uStack_3a;
  undefined4 uStack_38;
  zcl_packet_t packet;
  
  uStack_38 = 0;
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
  if (cmd_req == (ezb_zcl_color_control_color_loop_set_cmd_t *)0x0) {
    eVar1 = -1;
  }
  else {
    iVar2 = zcl_packet_init(&uStack_38,0);
    if (iVar2 == 0) {
      eVar1 = zcl_cmd_to_packet(&uStack_38,0,0,(cmd_req->cmd_ctrl).dis_default_rsp,0,0x44,0x300);
      if (eVar1 == 0) {
        uStack_3a = CONCAT11(uStack_3a._1_1_,(cmd_req->payload).update_flags);
        eVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_3a);
        if (eVar1 == 0) {
          uStack_3a = CONCAT11(uStack_3a._1_1_,(cmd_req->payload).action);
          eVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_3a);
          if (eVar1 == 0) {
            uStack_3a = CONCAT11(uStack_3a._1_1_,(cmd_req->payload).direction);
            eVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_3a);
            if (eVar1 == 0) {
              uStack_3a = (cmd_req->payload).time;
              eVar1 = zmsg_append_bytes(packet._32_4_,2,&uStack_3a);
              if (eVar1 == 0) {
                uStack_3a = (cmd_req->payload).start_hue;
                eVar1 = zmsg_append_bytes(packet._32_4_,2,&uStack_3a);
                if (eVar1 == 0) {
                  uStack_3a = CONCAT11(uStack_3a._1_1_,(cmd_req->payload).options_mask);
                  eVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_3a);
                  if (eVar1 == 0) {
                    uStack_3a = CONCAT11(uStack_3a._1_1_,(cmd_req->payload).options_override);
                    eVar1 = zmsg_append_bytes(packet._32_4_,1,&uStack_3a);
                    if (eVar1 == 0) {
                      zcl_packet_send(&uStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
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
    else {
      eVar1 = -1;
    }
  }
  zcl_packet_free(&uStack_38);
  return eVar1;
}

