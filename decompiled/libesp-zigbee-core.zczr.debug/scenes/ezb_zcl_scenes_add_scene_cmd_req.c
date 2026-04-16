/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> scenes.o -> ezb_zcl_scenes_add_scene_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: packet */
/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_scenes_add_scene_cmd_req(ezb_zcl_scenes_add_scene_cmd_t *cmd_req)

{
  undefined4 uVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  ezb_zcl_scenes_extension_field_t *peVar5;
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
  if (cmd_req == (ezb_zcl_scenes_add_scene_cmd_t *)0x0) {
    iVar3 = -1;
  }
  else {
    iVar3 = zcl_packet_init(&uStack_38,0);
    if (iVar3 == 0) {
      iVar3 = zcl_cmd_to_packet(&uStack_38,0,0,(cmd_req->cmd_ctrl).dis_default_rsp,0,0,5);
      if (iVar3 == 0) {
        uStack_3a = (cmd_req->payload).group_id;
        iVar3 = zmsg_append_bytes(packet._32_4_,2,&uStack_3a);
        if (iVar3 == 0) {
          uStack_3a = CONCAT11(uStack_3a._1_1_,(cmd_req->payload).scene_id);
          iVar3 = zmsg_append_bytes(packet._32_4_,1,&uStack_3a);
          if (iVar3 == 0) {
            uStack_3a = (cmd_req->payload).transition_time;
            iVar3 = zmsg_append_bytes(packet._32_4_,2,&uStack_3a);
            uVar1 = packet._32_4_;
            if (iVar3 == 0) {
              pcVar2 = (cmd_req->payload).scene_name;
              uVar4 = ezb_zcl_get_attr_value_size(0x42,pcVar2);
              iVar3 = zmsg_append_bytes(uVar1,uVar4,pcVar2);
              if (iVar3 == 0) {
                for (peVar5 = (cmd_req->payload).extension_field;
                    peVar5 != (ezb_zcl_scenes_extension_field_t *)0x0; peVar5 = peVar5->next) {
                  uStack_3a = peVar5->cluster_id;
                  iVar3 = zmsg_append_bytes(packet._32_4_,2,&uStack_3a);
                  if (iVar3 != 0) goto _L0;
                  uStack_3a = CONCAT11(uStack_3a._1_1_,peVar5->length);
                  iVar3 = zmsg_append_bytes(packet._32_4_,1,&uStack_3a);
                  if ((iVar3 != 0) ||
                     (iVar3 = zmsg_append_bytes(packet._32_4_,peVar5->length,peVar5->value),
                     iVar3 != 0)) goto _L0;
                }
                zcl_packet_send(&uStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
                iVar3 = zcl_status_to_err();
_L0:
                if (iVar3 == 0) {
                  return 0;
                }
              }
            }
          }
        }
      }
    }
    else {
      iVar3 = -1;
    }
  }
  zcl_packet_free(&uStack_38);
  return iVar3;
}

