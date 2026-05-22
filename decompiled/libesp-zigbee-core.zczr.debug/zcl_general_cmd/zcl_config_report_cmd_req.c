/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_config_report_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: packet */
/* WARNING: Unknown calling convention */

ezb_err_t zcl_config_report_cmd_req(zcl_config_report_cmd_t *cmd_req)

{
  uint16_t uVar1;
  ezb_zcl_config_report_record_t *peVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
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
  if (cmd_req == (zcl_config_report_cmd_t *)0x0) {
    iVar3 = -1;
  }
  else if ((cmd_req->payload).record_number == 0) {
    iVar3 = -1;
  }
  else if ((cmd_req->payload).record_field == (ezb_zcl_config_report_record_t *)0x0) {
    iVar3 = -1;
  }
  else {
    iVar3 = zcl_packet_init(&uStack_38,*(uint *)&(cmd_req->cmd_ctrl).fc & 1);
    if (iVar3 == 0) {
      uVar5 = *(uint *)&(cmd_req->cmd_ctrl).fc;
      iVar3 = zcl_cmd_to_packet(&uStack_38,0,uVar5 & 1,uVar5 >> 1 & 1,uVar5 >> 2 & 1,
                                (cmd_req->cmd_ctrl).manuf_code,6,(cmd_req->cmd_ctrl).cluster_id);
      if (iVar3 == 0) {
        while ((iVar3 < (int)(uint)(cmd_req->payload).record_number &&
               (peVar2 = (cmd_req->payload).record_field,
               peVar2 != (ezb_zcl_config_report_record_t *)0x0))) {
          peVar2 = peVar2 + iVar3;
          uStack_3a = CONCAT11(uStack_3a._1_1_,peVar2->direction);
          iVar4 = zmsg_append_bytes(packet._32_4_,1,&uStack_3a);
          if (iVar4 != 0) goto _L0;
          uStack_3a = peVar2->attr_id;
          iVar4 = zmsg_append_bytes(packet._32_4_,2,&uStack_3a);
          if (iVar4 != 0) goto _L0;
          if (peVar2->direction == '\0') {
            uStack_3a = CONCAT11(uStack_3a._1_1_,(peVar2->field_2).client.attr_type);
            iVar4 = zmsg_append_bytes(packet._32_4_,1,&uStack_3a);
            if (iVar4 != 0) goto _L0;
            uStack_3a = (peVar2->field_2).client.min_interval;
            iVar4 = zmsg_append_bytes(packet._32_4_,2,&uStack_3a);
            if (iVar4 != 0) goto _L0;
            uStack_3a = (peVar2->field_2).client.max_interval;
            iVar4 = zmsg_append_bytes(packet._32_4_,2,&uStack_3a);
            if (iVar4 != 0) goto _L0;
            iVar4 = zcl_attr_type_is_analog((peVar2->field_2).client.attr_type);
            if (iVar4 != 0) {
              uVar1 = (peVar2->field_2).client.max_interval;
              if (((uVar1 == 0) && ((peVar2->field_2).client.min_interval == 0xffff)) ||
                 (uVar1 == 0xffff)) {
                uStack_3a = uStack_3a & 0xff00;
                iVar4 = zmsg_append_bytes(packet._32_4_,1,&uStack_3a);
              }
              else {
                iVar4 = zcl_packet_append_variable_attr_value
                                  (packet._32_4_,(peVar2->field_2).client.attr_type,
                                   (undefined1 *)((int)&peVar2->field_2 + 8));
              }
              goto joined_r0x00011cd0;
            }
          }
          else {
            uStack_3a = (peVar2->field_2).server.timeout;
            iVar4 = zmsg_append_bytes(packet._32_4_,2,&uStack_3a);
joined_r0x00011cd0:
            if (iVar4 != 0) goto _L0;
          }
          iVar3 = iVar3 + 1;
        }
        zcl_packet_send(&uStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
        iVar4 = zcl_status_to_err();
_L0:
        iVar3 = iVar4;
        if (iVar4 == 0) {
          return 0;
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

