/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_general_cmd.o -> zcl_general_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: rsp */
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unknown calling convention */

zcl_status_t zcl_general_cmd_handler(zcl_packet_t *packet)

{
  uint16_t uVar1;
  int iVar2;
  uint8_t uVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  uint uVar7;
  uint uVar8;
  void *pvVar9;
  size_t sVar10;
  int iVar11;
  char *pcVar12;
  undefined1 *puVar13;
  undefined2 *puVar14;
  undefined2 *puVar15;
  ezb_zcl_cmd_hdr_t *value;
  uint8_t *value_00;
  undefined4 uVar16;
  undefined4 *puVar17;
  byte bVar18;
  byte bVar19;
  ezb_zcl_cmd_hdr_t *peVar20;
  uint16_t *puVar21;
  zmsg_t *pzVar22;
  uint16_t uVar23;
  uint16_t auStack_11c [2];
  anon_struct_2_1_5b20b909 read_attr_req;
  zcl_disc_cmd_req_s disc_cmd_req;
  uint16_t uStack_112;
  uint16_t offset_7;
  uint16_t offset_5;
  zcl_read_reporting_configuration_req_t read_rep_cfg;
  zcl_disc_attr_req_s disc_attr_req;
  zcl_write_attr_req_t write_attr_req;
  zcl_cmd_read_attr_rsp_message_t message_2;
  zcl_cmd_write_attr_rsp_message_t message_4;
  zcl_cmd_config_report_rsp_message_t message_5;
  zcl_cmd_read_report_config_rsp_message_t message_6;
  zcl_cmd_report_attr_message_t message_3;
  zcl_cmd_default_rsp_message_t message_1;
  uint16_t offset;
  uint8_t auStack_7c [4];
  uint16_t *puStack_78;
  byte bStack_74;
  undefined4 local_70;
  zcl_configure_reporting_req_t config_reporting_req;
  undefined1 auStack_58 [4];
  zcl_packet_t rsp;
  
  memset(auStack_58,0,0x28);
  if (packet != (zcl_packet_t *)0x0) goto _L0;
_L166:
  do {
    while( true ) {
      __assert_func(0,0,0,0);
_L0:
      iVar4 = zcl_packet_init(auStack_58,*(ushort *)&(packet->header).fc >> 2 & 1);
      if (iVar4 != 0) goto _L0;
      bVar19 = (packet->header).cmd_id;
      if (bVar19 == 9) goto _L0;
      if (9 < bVar19) break;
      if (bVar19 == 4) {
        message_2.out.result = '\0';
        message_2._17_3_ = 0;
        message_4.info.status = '\0';
        message_4.info.dst_ep = '\0';
        message_4.info.cluster_id = 0;
        message_4.info.cluster_role = '\0';
        message_4.info._5_1_ = 0;
        message_4._6_2_ = 0;
        message_4.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
        message_4.in.variables = (ezb_zcl_write_attr_rsp_variable_t *)0x0;
        if ((packet->payload != (zcl_packet_payload_t *)0x0) && (rsp._32_4_ != 0)) {
          iVar4 = zcl_packet_to_message(&message_2.out,packet);
          if (iVar4 != 0) goto _L208;
          local_70 = local_70 & 0xffff0000;
          message_4._4_4_ = packet;
          uVar5 = zmsg_get_length(packet->payload);
          goto _L0;
        }
      }
      else if (bVar19 < 5) {
        if (bVar19 == 1) {
          write_attr_req.attr_value = (void *)0x0;
          message_2.info.status = '\0';
          message_2.info.dst_ep = '\0';
          message_2.info.cluster_id = 0;
          message_2.info.cluster_role = '\0';
          message_2.info._5_1_ = 0;
          message_2._6_2_ = 0;
          message_2.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
          message_2.in.variables = (ezb_zcl_read_attr_rsp_variable_t *)0x0;
          if ((packet->payload != (zcl_packet_payload_t *)0x0) && (rsp._32_4_ != 0)) {
            iVar4 = zcl_packet_to_message(&write_attr_req.attr_value,packet);
            if (iVar4 != 0) goto _L0;
            pzVar22 = packet->payload;
            local_70 = local_70 & 0xffff0000;
            message_2._4_4_ = packet;
            uVar5 = zmsg_get_length(pzVar22);
            goto _L0;
          }
        }
        else if (bVar19 == 2) {
          pzVar22 = packet->payload;
          disc_attr_req.start_attr_id = 0;
          disc_attr_req.max_count = '\0';
          disc_attr_req._3_1_ = 0;
          write_attr_req.attr_id = 0;
          write_attr_req.attr_type = '\0';
          write_attr_req._3_1_ = 0;
          if ((pzVar22 != (zmsg_t *)0x0) && (rsp._32_4_ != 0)) {
            uVar23 = 0;
            if (((packet->header).fc & 4) != 0) {
              uVar23 = (packet->header).manuf_code;
            }
            iVar4 = af_get_ep_desc((packet->header).dst_ep);
            if (iVar4 == 0) goto _L0;
            uVar16 = 1;
            if (((packet->header).fc & 8) != 0) {
              uVar16 = 2;
            }
            iVar4 = af_endpoint_get_cluster_desc((packet->header).cluster_id,uVar16);
            if (iVar4 == 0) goto _L0;
            uVar7 = zmsg_get_length(pzVar22);
            local_70 = local_70 & 0xffff0000;
            while ((local_70 & 0xffff) < uVar7) {
              disc_attr_req.start_attr_id = 0;
              disc_attr_req.max_count = '\0';
              disc_attr_req._3_1_ = 0;
              write_attr_req.attr_id = 0;
              write_attr_req.attr_type = '\0';
              write_attr_req._3_1_ = 0;
              af_read_le16(pzVar22,(uint16_t *)&local_70,&disc_attr_req.start_attr_id);
              af_read_le8(pzVar22,(uint16_t *)&local_70,&disc_attr_req.max_count);
              iVar2 = 0x86;
              sVar10 = zcl_packet_read_variable_attr_size
                                 (packet->payload,local_70 & 0xffff,
                                  (uint)disc_attr_req >> 0x10 & 0xff);
              write_attr_req._0_4_ = calloc(1,sVar10);
              zcl_packet_read_variable_attr_value
                        (pzVar22,&local_70,(uint)disc_attr_req >> 0x10 & 0xff,write_attr_req._0_4_);
              iVar11 = zcl_cluster_get_attr_desc(iVar4,(uint)disc_attr_req & 0xffff,uVar23);
              if (iVar11 != 0) {
                iVar2 = 0x8d;
                if (disc_attr_req.max_count == *(uint8_t *)(iVar11 + 2)) {
                  bVar19 = *(byte *)(iVar11 + 3);
                  iVar2 = 0x88;
                  if (((bVar19 != 1) && ((bVar19 & 2) != 0)) && (iVar2 = 0x86, (bVar19 & 0x40) == 0)
                     ) {
                    uVar16 = 1;
                    if (((packet->header).fc & 8) != 0) {
                      uVar16 = 2;
                    }
                    iVar2 = zcl_set_attr_value((packet->header).dst_ep,(packet->header).cluster_id,
                                               uVar16,(uint)disc_attr_req & 0xffff,uVar23,
                                               write_attr_req._0_4_,0);
                    if (iVar2 == 0) {
                      if (((packet->header).cluster_id == 0x500) && (((packet->header).fc & 8) == 0)
                         ) {
                        ias_zone_cluster_srv_set_attr_val_post_proc
                                  (packet,(uint)disc_attr_req & 0xffff,write_attr_req._0_4_);
                      }
                      uVar16 = 1;
                      if (((packet->header).fc & 8) != 0) {
                        uVar16 = 2;
                      }
                      zcl_message_notify_attr_value
                                ((packet->header).dst_ep,(packet->header).cluster_id,uVar16,iVar11);
                    }
                  }
                }
              }
              zmsg_append_u8((zmsg_t *)rsp._32_4_,(uint8_t)iVar2);
              if (iVar2 != 0) {
                zmsg_append_le16((zmsg_t *)rsp._32_4_,disc_attr_req.start_attr_id);
              }
              mm_free(write_attr_req._0_4_);
            }
            uVar5 = 0x80;
            if (uVar7 != (local_70 & 0xffff)) goto _L0;
            uVar16 = 4;
            goto _L0;
          }
        }
        else {
          if (bVar19 != 0) {
_L510:
            iVar4 = 0x81;
            goto _L0;
          }
          pzVar22 = packet->payload;
          auStack_11c[0] = 0;
          if ((pzVar22 != (zmsg_t *)0x0) && (rsp._32_4_ != 0)) {
            uVar23 = 0;
            if (((packet->header).fc & 4) != 0) {
              uVar23 = (packet->header).manuf_code;
            }
            uVar5 = zmsg_get_length(pzVar22);
            message_1.out.result = '\0';
            message_1._17_1_ = 0;
            if ((uVar5 & 1) == 0) goto _L0;
            goto _L0;
          }
        }
      }
      else if (bVar19 == 7) {
        message_4.out.result = '\0';
        message_4._17_3_ = 0;
        message_5.info.status = '\0';
        message_5.info.dst_ep = '\0';
        message_5.info.cluster_id = 0;
        message_5.info.cluster_role = '\0';
        message_5.info._5_1_ = 0;
        message_5._6_2_ = 0;
        message_5.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
        message_5.in.variables = (ezb_zcl_config_report_rsp_variable_t *)0x0;
        if ((packet->payload != (zcl_packet_payload_t *)0x0) && (rsp._32_4_ != 0)) {
          iVar4 = zcl_packet_to_message(&message_4.out,packet);
          if (iVar4 != 0) goto _L241;
          local_70 = local_70 & 0xffff0000;
          message_5._4_4_ = packet;
          uVar5 = zmsg_get_length(packet->payload);
          goto _L0;
        }
      }
      else {
        if (bVar19 != 8) {
          if (bVar19 != 6) goto _L510;
          local_70 = 0;
          config_reporting_req.direction = '\0';
          config_reporting_req._1_1_ = 0;
          config_reporting_req.attr_id = 0;
          config_reporting_req.field_2._0_4_ = 0;
          config_reporting_req.field_2._4_4_ = 0;
          pzVar22 = packet->payload;
          uVar23 = 0;
          if (((packet->header).fc & 4) != 0) {
            uVar23 = (packet->header).manuf_code;
          }
          iVar4 = af_get_ep_desc((packet->header).dst_ep);
          if (iVar4 == 0) {
            uVar5 = 0x81;
            goto _L0;
          }
          iVar4 = af_endpoint_get_cluster_desc
                            ((packet->header).cluster_id,(((packet->header).fc & 8) != 0) + '\x01');
          if (iVar4 != 0) {
            uVar7 = zmsg_get_length(pzVar22);
            message_1.out.result = '\0';
            message_1._17_1_ = 0;
            goto _L0;
          }
          uVar5 = 0xc3;
          goto _L0;
        }
        pzVar22 = packet->payload;
        _offset_7 = 0;
        if ((pzVar22 != (zmsg_t *)0x0) && (rsp._32_4_ != 0)) {
          uVar23 = 0;
          if (((packet->header).fc & 4) != 0) {
            uVar23 = (packet->header).manuf_code;
          }
          puVar13 = (undefined1 *)af_get_ep_desc((packet->header).dst_ep);
          if (puVar13 == (undefined1 *)0x0) {
_L0:
            uVar5 = 0x81;
            goto _L0;
          }
          puVar14 = (undefined2 *)
                    af_endpoint_get_cluster_desc
                              ((packet->header).cluster_id,(((packet->header).fc & 8) != 0) + '\x01'
                              );
          if (puVar14 == (undefined2 *)0x0) goto _L0;
          uVar5 = zmsg_get_length(pzVar22);
          local_70 = local_70 & 0xffff0000;
          goto _L0;
        }
      }
    }
    if (bVar19 != 0xd) {
      if (bVar19 < 0xe) {
        pzVar22 = packet->payload;
        if (bVar19 == 0xb) {
          message_3.out.result = '\0';
          message_3._17_3_ = 0;
          message_1.info.status = '\0';
          message_1.info.dst_ep = '\0';
          message_1.info.cluster_id = 0;
          message_1.info.cluster_role = '\0';
          message_1.info._5_1_ = 0;
          message_1._6_2_ = 0;
          message_1.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
          message_1.in.rsp_to_cmd = '\0';
          message_1.in.status_code = '\0';
          message_1.in._6_2_ = 0;
          uStack_112 = 0;
          if ((pzVar22 != (zmsg_t *)0x0) && (rsp._32_4_ != 0)) {
            iVar4 = zcl_packet_to_message(&message_3.out,packet);
            uVar5 = 0xfe;
            if (iVar4 == 0) {
              message_1._4_4_ = packet;
              af_read_le8(packet->payload,&uStack_112,(uint8_t *)&message_1.in);
              af_read_le8(packet->payload,&uStack_112,(uint8_t *)((int)&message_1.in.header + 1));
              uVar7 = zmsg_get_length(packet->payload);
              uVar5 = 0x80;
              if (uStack_112 <= uVar7) {
                message_1.in.rsp_to_cmd = 0xfe;
                zcl_core_action_schedule(8,&message_3.out,0x80);
                uVar5 = message_1.in._4_4_ & 0xff;
                if (uVar5 == 0xfe) {
                  uVar5 = 0;
                }
              }
            }
            goto _L0;
          }
          goto _L166;
        }
        if (bVar19 != 0xc) {
          message_6.out.result = '\0';
          message_6._17_3_ = 0;
          message_3.info.status = '\0';
          message_3.info.dst_ep = '\0';
          message_3.info.cluster_id = 0;
          message_3.info.cluster_role = '\0';
          message_3.info._5_1_ = 0;
          message_3._6_2_ = 0;
          message_3.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
          message_3.in.variables = (ezb_zcl_report_attr_variable_t *)0x0;
          disc_cmd_req.start_cmd_id = '\0';
          disc_cmd_req.max_count = '\0';
          if ((pzVar22 != (zmsg_t *)0x0) && (rsp._32_4_ != 0)) {
            uVar5 = zmsg_get_length(pzVar22);
            message_3.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
            iVar4 = zcl_packet_to_message(&message_6.out,packet);
            if (iVar4 != 0) goto _L0;
            uVar23 = 0;
            message_3._4_4_ = packet;
            if (((packet->header).fc & 4) != 0) {
              uVar23 = (packet->header).manuf_code;
            }
            goto _L0;
          }
          goto _L166;
        }
        read_rep_cfg.direction = '\0';
        read_rep_cfg._1_1_ = 0;
        read_rep_cfg.attr_id = 0;
        if ((pzVar22 == (zmsg_t *)0x0) || (rsp._32_4_ == 0)) goto _L166;
        iVar4 = af_get_ep_desc((packet->header).dst_ep);
        if (iVar4 == 0) goto _L0;
        iVar4 = af_endpoint_get_cluster_desc
                          ((packet->header).cluster_id,(((packet->header).fc & 8) != 0) + '\x01');
        if (iVar4 != 0) {
          uVar7 = zmsg_get_length(pzVar22);
          local_70 = local_70 & 0xffff0000;
          uVar5 = 0;
          goto _L0;
        }
      }
      else {
        if (bVar19 != 0x13) {
          if (bVar19 < 0x14) {
            if (bVar19 == 0x11) goto _L0;
            bVar18 = 0x12;
          }
          else {
            bVar18 = 0x14;
          }
          if (bVar19 != bVar18) goto _L510;
          memset(&local_70,0,0x18);
          if ((packet->payload != (zcl_packet_payload_t *)0x0) && (rsp._32_4_ != 0)) {
            iVar4 = zcl_packet_to_message(&local_70,packet);
            uVar5 = 0x80;
            if (iVar4 == 0) {
              message_1.out.result = '\0';
              message_1._17_1_ = 0;
              config_reporting_req.field_2._0_4_ = packet;
              uVar5 = zmsg_get_length(packet->payload);
              af_read_le8(packet->payload,(uint16_t *)&message_1.out,
                          (uint8_t *)
                          ((int)&config_reporting_req.field_2.send_info.max_reporting_interval + 1))
              ;
              config_reporting_req.field_2.send_info.max_reporting_interval._0_1_ =
                   (packet->header).cmd_id == '\x12';
              while ((ushort)message_1._16_2_ < uVar5) {
                value_00 = (uint8_t *)calloc(1,8);
                af_read_le8(packet->payload,(uint16_t *)&message_1.out,value_00);
                *(void **)(value_00 + 4) = config_reporting_req.field_2.send_info.reporting_change;
                config_reporting_req.field_2.send_info.reporting_change = value_00;
              }
              zcl_core_action_schedule(7,&local_70);
              uVar5 = 0;
            }
            while (config_reporting_req.field_2.send_info.reporting_change != (void *)0x0) {
              pvVar9 = *(void **)((int)config_reporting_req.field_2.send_info.reporting_change + 4);
              mm_free();
              config_reporting_req.field_2.send_info.reporting_change = pvVar9;
            }
            goto _L0;
          }
          goto _L166;
        }
_L0:
        pzVar22 = packet->payload;
        read_attr_req.attr_id = 0;
        if ((pzVar22 == (zmsg_t *)0x0) || (rsp._32_4_ == 0)) goto _L166;
        iVar4 = af_get_ep_desc((packet->header).dst_ep);
        if (iVar4 == 0) goto _L0;
        puVar14 = (undefined2 *)
                  af_endpoint_get_cluster_desc
                            ((packet->header).cluster_id,(((packet->header).fc & 8) != 0) + '\x01');
        if (puVar14 != (undefined2 *)0x0) {
          uVar7 = zmsg_get_length(pzVar22);
          message_1.out.result = '\0';
          message_1._17_1_ = 0;
          af_read_le8(pzVar22,(uint16_t *)&message_1.out,(uint8_t *)&read_attr_req);
          af_read_le8(pzVar22,(uint16_t *)&message_1.out,
                      (uint8_t *)((int)&read_attr_req.attr_id + 1));
          uVar5 = 0x80;
          if ((ushort)message_1._16_2_ != uVar7) goto _L0;
          zmsg_append_u8((zmsg_t *)rsp._32_4_,'\0');
          iVar4 = zcl_cluster_template_find(*puVar14,*(undefined1 *)(puVar14 + 1));
          if ((iVar4 != 0) && (*(code **)(iVar4 + 0xc) != (code *)0x0)) {
            local_70 = 0;
            uVar5 = (**(code **)(iVar4 + 0xc))((packet->header).cmd_id == '\x11',&local_70);
            uVar7 = 0;
            bVar19 = 0;
            while ((((uVar7 & 0xffff) < uVar5 && (local_70 != 0)) &&
                   (bVar19 < read_attr_req.attr_id._1_1_))) {
              if ((byte)read_attr_req.attr_id <= *(byte *)(local_70 + uVar7)) {
                bVar19 = bVar19 + 1;
                zmsg_append_u8((zmsg_t *)rsp._32_4_,*(byte *)(local_70 + uVar7));
              }
              uVar7 = uVar7 + 1;
            }
            message_3.out.result = (uVar7 & 0xffff) == uVar5;
            zmsg_write_bytes(0,1,&message_3.out);
            uVar16 = 0x14;
            if ((packet->header).cmd_id == '\x11') {
              uVar16 = 0x12;
            }
            goto _L0;
          }
          goto _L0;
        }
      }
_L0:
      uVar5 = 0xc3;
      goto _L0;
    }
    memset(&message_1.out,0,0x18);
    if ((packet->payload != (zcl_packet_payload_t *)0x0) && (rsp._32_4_ != 0)) {
      iVar4 = zcl_packet_to_message(&message_1.out,packet);
      uVar5 = 0x80;
      if (iVar4 == 0) {
        local_70 = local_70 & 0xffff0000;
        uVar5 = zmsg_get_length(packet->payload);
        af_read_le8(packet->payload,(uint16_t *)&local_70,auStack_7c);
        while ((local_70 & 0xffff) < uVar5) {
          puVar21 = (uint16_t *)calloc(1,8);
          af_read_le16(packet->payload,(uint16_t *)&local_70,puVar21);
          af_read_le8(packet->payload,(uint16_t *)&local_70,(uint8_t *)(puVar21 + 1));
          *(uint16_t **)(puVar21 + 2) = puStack_78;
          puStack_78 = puVar21;
        }
        bStack_74 = 0xfe;
        zcl_core_action_schedule(6,&message_1.out);
        uVar5 = (uint)bStack_74;
        if (uVar5 == 0xfe) {
          uVar5 = 0;
        }
      }
      while (puStack_78 != (uint16_t *)0x0) {
        puVar21 = *(uint16_t **)(puStack_78 + 2);
        mm_free();
        puStack_78 = puVar21;
      }
      goto _L0;
    }
  } while( true );
_L0:
  message_5.out.result = '\0';
  message_5._17_3_ = 0;
  message_6.info.status = '\0';
  message_6.info.dst_ep = '\0';
  message_6.info.cluster_id = 0;
  message_6.info.cluster_role = '\0';
  message_6.info._5_1_ = 0;
  message_6._6_2_ = 0;
  message_6.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message_6.in.variables = (ezb_zcl_read_report_config_rsp_variable_t *)0x0;
  if ((packet->payload == (zcl_packet_payload_t *)0x0) || (rsp._32_4_ == 0)) goto _L166;
  iVar4 = zcl_packet_to_message(&message_5.out,packet);
  if (iVar4 == 0) {
    local_70 = local_70 & 0xffff0000;
    message_6._4_4_ = packet;
    uVar5 = zmsg_get_length(packet->payload);
    while ((local_70 & 0xffff) < uVar5) {
      peVar20 = (ezb_zcl_cmd_hdr_t *)calloc(1,0x20);
      *(ezb_zcl_cmd_hdr_t **)&peVar20->profile_id = message_6.in.header;
      message_6.in.header = peVar20;
      af_read_le8(packet->payload,(uint16_t *)&local_70,(uint8_t *)peVar20);
      af_read_le8(packet->payload,(uint16_t *)&local_70,&(peVar20->src_addr).field_0x1);
      af_read_le16(packet->payload,(uint16_t *)&local_70,&(peVar20->src_addr).u.short_addr);
      if (uVar5 < (local_70 & 0xffff)) goto _L264;
      puVar21 = &(peVar20->src_addr).u.short_addr + 3;
      if ((peVar20->src_addr).addr_mode == '\0') {
        if ((peVar20->src_addr).field_0x1 == '\0') {
          af_read_le8(packet->payload,(uint16_t *)&local_70,(uint8_t *)puVar21);
          af_read_le16(packet->payload,(uint16_t *)&local_70,(uint16_t *)&peVar20->dst_addr);
          af_read_le16(packet->payload,(uint16_t *)&local_70,&(peVar20->dst_addr).u.short_addr);
          iVar4 = zcl_attr_type_is_analog(*(undefined1 *)((int)&(peVar20->src_addr).u + 6));
          if (iVar4 == 0) {
            *(undefined4 *)((int)&(peVar20->dst_addr).u + 4) = 0;
            peVar20->src_ep = '\0';
            peVar20->dst_ep = '\0';
            peVar20->cluster_id = 0;
          }
          else {
            zcl_packet_read_variable_attr_value
                      (packet->payload,&local_70,*(undefined1 *)((int)&(peVar20->src_addr).u + 6),
                       (undefined1 *)((int)&(peVar20->dst_addr).u + 4));
          }
        }
        else {
          af_read_le16(packet->payload,(uint16_t *)&local_70,puVar21);
        }
      }
      else {
        memset(puVar21,0xff,0x10);
      }
    }
    message_6.in.variables =
         (ezb_zcl_read_report_config_rsp_variable_t *)CONCAT31(message_6.in.variables._1_3_,0xfe);
    zcl_core_action_schedule(4,&message_5.out);
    uVar5 = (uint)message_6.in.variables & 0xff;
    if (uVar5 == 0xfe) {
      uVar5 = 0;
    }
  }
  else {
_L264:
    uVar5 = 0x80;
  }
  while (message_6.in.header != (ezb_zcl_cmd_hdr_t *)0x0) {
    peVar20 = *(ezb_zcl_cmd_hdr_t **)&(message_6.in.header)->profile_id;
    mm_free(message_6.in.header);
    message_6.in.header = peVar20;
  }
  goto _L0;
_L0:
  peVar20 = message_3.in.header;
  if (uVar5 <= (ushort)disc_cmd_req) goto _L0;
  value = (ezb_zcl_cmd_hdr_t *)calloc(1,0xc);
  *(ezb_zcl_cmd_hdr_t **)((int)&(value->src_addr).u + 6) = peVar20;
  message_3.in.header = value;
  af_read_le16(packet->payload,(uint16_t *)&disc_cmd_req,(uint16_t *)value);
  af_read_le8(packet->payload,(uint16_t *)&disc_cmd_req,(uint8_t *)&(value->src_addr).u.short_addr);
  if (uVar5 < (ushort)disc_cmd_req) goto _L0;
  sVar10 = zcl_packet_read_variable_attr_size(packet->payload,*(undefined1 *)&(value->src_addr).u);
  pvVar9 = calloc(1,sVar10);
  *(void **)((int)&(value->src_addr).u + 2) = pvVar9;
  zcl_packet_read_variable_attr_value
            (packet->payload,&disc_cmd_req,*(undefined1 *)&(value->src_addr).u,pvVar9);
  goto _L0;
_L0:
  for (; peVar20 != (ezb_zcl_cmd_hdr_t *)0x0;
      peVar20 = *(ezb_zcl_cmd_hdr_t **)((int)&(peVar20->src_addr).u + 6)) {
    zcl_reporting_mark_recv_attr_report
              ((packet->header).dst_ep,(packet->header).cluster_id,
               (((packet->header).fc & 8) != 0) + '\x01',*(undefined2 *)&peVar20->src_addr,uVar23);
  }
  message_3.in.variables =
       (ezb_zcl_report_attr_variable_t *)CONCAT31(message_3.in.variables._1_3_,0xfe);
  zcl_core_action_schedule(5,&message_6.out);
  uVar5 = (uint)message_3.in.variables & 0xff;
  if (uVar5 == 0xfe) {
    uVar5 = 0;
  }
_L0:
  while (message_3.in.header != (ezb_zcl_cmd_hdr_t *)0x0) {
    peVar20 = *(ezb_zcl_cmd_hdr_t **)((int)&((message_3.in.header)->src_addr).u + 6);
    if (*(int *)((int)&((message_3.in.header)->src_addr).u + 2) != 0) {
      mm_free();
    }
    mm_free(message_3.in.header);
    message_3.in.header = peVar20;
  }
  goto _L0;
_L0:
  uVar5 = 0x80;
  goto _L0;
_L0:
  if ((local_70 & 0xffff) < uVar7) {
    af_read_le16(pzVar22,(uint16_t *)&local_70,(uint16_t *)&read_rep_cfg);
    af_read_le8(pzVar22,(uint16_t *)&local_70,(uint8_t *)&read_rep_cfg.attr_id);
    if ((local_70 & 0xffff) != uVar7) goto _L0;
    puVar21 = (uint16_t *)0x0;
    zmsg_append_u8((zmsg_t *)rsp._32_4_,'\x01');
    do {
      do {
        puVar21 = (uint16_t *)zcl_cluster_get_next_attr_desc(iVar4,puVar21);
        if (puVar21 == (uint16_t *)0x0) goto _L0;
        uVar23 = *puVar21;
      } while (uVar23 < (ushort)read_rep_cfg._0_2_);
      if (((*(byte *)((int)puVar21 + 3) & 0x40) == 0) && (uVar23 != 0xfffd)) {
        uVar5 = uVar5 + 1 & 0xff;
        zmsg_append_le16((zmsg_t *)rsp._32_4_,uVar23);
        zmsg_append_u8((zmsg_t *)rsp._32_4_,(uint8_t)puVar21[1]);
      }
    } while (uVar5 < ((uint)read_rep_cfg >> 0x10 & 0xff));
    message_1._16_2_ = message_1._16_2_ & 0xff00;
    zmsg_write_bytes(rsp._32_4_,0,1,&message_1.out);
    goto _L0;
  }
  uVar16 = 0xd;
  goto _L0;
_L0:
  if ((local_70 & 0xffff) < uVar5) {
    peVar20 = (ezb_zcl_cmd_hdr_t *)calloc(1,8);
    *(ezb_zcl_cmd_hdr_t **)((int)&(peVar20->src_addr).u + 2) = message_4.in.header;
    message_4.in.header = peVar20;
    af_read_le8(packet->payload,(uint16_t *)&local_70,(uint8_t *)peVar20);
    if (uVar5 < (local_70 & 0xffff)) goto _L208;
    if ((peVar20->src_addr).addr_mode == '\0') {
      (peVar20->src_addr).u.short_addr = 0xffff;
    }
    else {
      af_read_le16(packet->payload,(uint16_t *)&local_70,&(peVar20->src_addr).u.short_addr);
    }
    goto _L0;
  }
  message_4.in.variables =
       (ezb_zcl_write_attr_rsp_variable_t *)CONCAT31(message_4.in.variables._1_3_,0xfe);
  zcl_core_action_schedule(2,&message_2.out);
  uVar5 = (uint)message_4.in.variables & 0xff;
  if (uVar5 == 0xfe) {
    uVar5 = 0;
  }
_L0:
  while (message_4.in.header != (ezb_zcl_cmd_hdr_t *)0x0) {
    peVar20 = *(ezb_zcl_cmd_hdr_t **)((int)&((message_4.in.header)->src_addr).u + 2);
    mm_free(message_4.in.header);
    message_4.in.header = peVar20;
  }
  goto _L0;
_L208:
  uVar5 = 0x80;
  goto _L0;
_L0:
  if ((local_70 & 0xffff) < uVar5) {
    peVar20 = (ezb_zcl_cmd_hdr_t *)calloc(1,8);
    *(ezb_zcl_cmd_hdr_t **)((int)&(peVar20->src_addr).u + 2) = message_5.in.header;
    message_5.in.header = peVar20;
    af_read_le8(packet->payload,(uint16_t *)&local_70,(uint8_t *)peVar20);
    if (uVar5 < (local_70 & 0xffff)) goto _L241;
    if ((peVar20->src_addr).addr_mode == '\0') {
      (peVar20->src_addr).field_0x1 = 0xff;
      (peVar20->src_addr).u.short_addr = 0xffff;
    }
    else {
      af_read_le8(packet->payload,(uint16_t *)&local_70,&(peVar20->src_addr).field_0x1);
      af_read_le16(packet->payload,(uint16_t *)&local_70,&(peVar20->src_addr).u.short_addr);
    }
    goto _L0;
  }
  message_5.in.variables =
       (ezb_zcl_config_report_rsp_variable_t *)CONCAT31(message_5.in.variables._1_3_,0xfe);
  zcl_core_action_schedule(3,&message_4.out);
  uVar5 = (uint)message_5.in.variables & 0xff;
  if (uVar5 == 0xfe) {
    uVar5 = 0;
  }
_L0:
  while (message_5.in.header != (ezb_zcl_cmd_hdr_t *)0x0) {
    peVar20 = *(ezb_zcl_cmd_hdr_t **)((int)&((message_5.in.header)->src_addr).u + 2);
    mm_free(message_5.in.header);
    message_5.in.header = peVar20;
  }
  goto _L0;
_L241:
  uVar5 = 0x80;
  goto _L0;
_L0:
  uVar5 = 0;
  if ((ushort)message_1._16_2_ < uVar7) {
    local_70 = 0;
    config_reporting_req.direction = '\0';
    config_reporting_req._1_1_ = 0;
    config_reporting_req.attr_id = 0;
    config_reporting_req.field_2._0_4_ = 0;
    config_reporting_req.field_2._4_4_ = 0;
    af_read_le8(pzVar22,(uint16_t *)&message_1.out,(uint8_t *)&local_70);
    af_read_le16(pzVar22,(uint16_t *)&message_1.out,(uint16_t *)((int)&local_70 + 2));
    if ((uint8_t)local_70 == '\0') {
      af_read_le8(pzVar22,(uint16_t *)&message_1.out,&config_reporting_req.direction);
      af_read_le16(pzVar22,(uint16_t *)&message_1.out,&config_reporting_req.attr_id);
      af_read_le16(pzVar22,(uint16_t *)&message_1.out,
                   &config_reporting_req.field_2.recv_info.timeout);
      iVar2 = zcl_attr_type_is_analog(config_reporting_req._0_4_ & 0xff);
      if (iVar2 != 0) {
        sVar10 = zcl_packet_read_variable_attr_size
                           (packet->payload,message_1._16_2_,config_reporting_req._0_4_ & 0xff);
        config_reporting_req.field_2._4_4_ = calloc(1,sVar10);
        zcl_packet_read_variable_attr_value
                  (pzVar22,&message_1.out,config_reporting_req._0_4_ & 0xff,
                   config_reporting_req.field_2._4_4_);
      }
    }
    else {
      af_read_le16(pzVar22,(uint16_t *)&message_1.out,(uint16_t *)&config_reporting_req);
    }
    if (uVar7 < (ushort)message_1._16_2_) {
      uVar5 = 0x80;
      goto _L0;
    }
    iVar2 = zcl_cluster_get_attr_desc(iVar4,local_70 >> 0x10,uVar23);
    if ((local_70 & 0xff) == 0) {
      if ((iVar2 == 0) || (*(int *)(iVar2 + 8) == 0)) {
        uVar3 = 0x86;
      }
      else {
        uVar8 = *(byte *)(iVar2 + 2) - 0x48;
        if ((9 < (uVar8 & 0xff)) || (uVar3 = 0x8c, (0x317U >> (uVar8 & 0x1f) & 1) == 0)) {
          if ((*(byte *)(iVar2 + 3) & 4) == 0) goto _L346;
          uVar3 = 0x8d;
          if ((config_reporting_req._0_4_ & 0xff) == (uint)*(byte *)(iVar2 + 2)) {
            if (((config_reporting_req.field_2._0_4_ & 0xffff) == 0) ||
               ((uint)config_reporting_req._0_4_ >> 0x10 <=
                (config_reporting_req.field_2._0_4_ & 0xffff))) goto _L0;
            uVar3 = 0x87;
          }
        }
      }
_L0:
      zmsg_append_u8((zmsg_t *)rsp._32_4_,uVar3);
      zmsg_append_u8((zmsg_t *)rsp._32_4_,(uint8_t)local_70);
      zmsg_append_le16((zmsg_t *)rsp._32_4_,local_70._2_2_);
    }
    else {
      if (iVar2 == 0) {
_L346:
        uVar3 = 0x8c;
        goto _L0;
      }
_L0:
      pcVar12 = (char *)zcl_reporting_info_find
                                  ((packet->header).dst_ep,(packet->header).cluster_id,
                                   (((packet->header).fc & 8) != 0) + '\x01',local_70 >> 0x10,
                                   *(undefined2 *)(iVar2 + 4));
      if (pcVar12 == (char *)0x0) {
        pcVar12 = (char *)zcl_reporting_info_create
                                    ((packet->header).dst_ep,(packet->header).profile_id,
                                     (uint8_t)local_70 != '\0',(packet->header).cluster_id,
                                     (((packet->header).fc & 8) != 0) + '\x01',local_70 >> 0x10,
                                     *(undefined2 *)(iVar2 + 4));
        zcl_reporting_info_add();
        iVar2 = err_to_zcl_status();
        if (iVar2 != 0) goto _L0;
      }
      uVar16 = config_reporting_req._0_4_;
      if (*pcVar12 == '\0') {
        uVar1 = config_reporting_req.attr_id;
        uVar5 = config_reporting_req.field_2._0_4_ & 0xffff;
        *(uint16_t *)(pcVar12 + 0x10) = config_reporting_req.attr_id;
        ((anon_struct_2_1_35098041_for_recv_info *)(pcVar12 + 0x12))->timeout =
             (uint16_t)config_reporting_req.field_2.recv_info.timeout;
        iVar2 = zcl_attr_type_is_analog(config_reporting_req._0_4_ & 0xff);
        if (iVar2 != 0) {
          if (uVar5 == 0) {
            if (uVar1 != 0xffff) {
_L0:
              zcl_write_attr_value
                        (pcVar12 + 0x18,config_reporting_req.field_2._4_4_,
                         config_reporting_req._0_4_ & 0xff);
            }
          }
          else if (uVar5 != 0xffff) goto _L0;
        }
      }
      else {
        pcVar12[0x10] = config_reporting_req.direction;
        pcVar12[0x11] = config_reporting_req._1_1_;
        config_reporting_req._0_4_ = uVar16;
      }
      zcl_reporting_info_update(pcVar12);
      uVar3 = err_to_zcl_status();
      zmsg_append_u8((zmsg_t *)rsp._32_4_,uVar3);
    }
    if (config_reporting_req.field_2._4_4_ != 0) {
      mm_free();
      config_reporting_req.field_2._4_4_ = 0;
    }
    goto _L0;
  }
_L0:
  if (config_reporting_req.field_2._4_4_ != 0) {
    mm_free();
  }
  uVar16 = 7;
  if (uVar5 != 0) goto _L0;
  goto _L0;
_L0:
  if ((local_70 & 0xffff) < uVar5) {
    af_read_le8(pzVar22,(uint16_t *)&local_70,(uint8_t *)&offset_7);
    af_read_le16(pzVar22,(uint16_t *)&local_70,&offset_5);
    if (uVar5 < (local_70 & 0xffff)) goto _L0;
    puVar15 = (undefined2 *)zcl_cluster_get_attr_desc(puVar14,_offset_7 >> 0x10,uVar23);
    iVar4 = 0x86;
    if ((puVar15 != (undefined2 *)0x0) && (*(int *)(puVar15 + 4) != 0)) {
      iVar4 = ((int)((uint)*(byte *)((int)puVar15 + 3) << 0x1d) >> 0x1f & 0xffffff74U) + 0x8c;
    }
    if (1 < (_offset_7 & 0xff)) {
      iVar4 = 0x87;
_L0:
      zmsg_append_u8((zmsg_t *)rsp._32_4_,(uint8_t)iVar4);
      zmsg_append_u8((zmsg_t *)rsp._32_4_,(uint8_t)offset_7);
      uVar1 = offset_5;
      goto _L0;
    }
    if (iVar4 != 0) goto _L0;
    iVar4 = zcl_reporting_info_find
                      (*puVar13,*puVar14,*(undefined1 *)(puVar14 + 1),*puVar15,puVar15[2]);
    uVar3 = '\0';
    if (iVar4 == 0) {
      uVar3 = 0x8b;
    }
    zmsg_append_u8((zmsg_t *)rsp._32_4_,uVar3);
    zmsg_append_u8((zmsg_t *)rsp._32_4_,(uint8_t)offset_7);
    zmsg_append_le16((zmsg_t *)rsp._32_4_,offset_5);
    if (uVar3 == '\0') {
      if ((uint8_t)offset_7 == '\0') {
        zmsg_append_u8((zmsg_t *)rsp._32_4_,*(uint8_t *)(puVar15 + 1));
        zmsg_append_le16((zmsg_t *)rsp._32_4_,*(uint16_t *)(iVar4 + 0x10));
        zmsg_append_le16((zmsg_t *)rsp._32_4_,*(uint16_t *)(iVar4 + 0x12));
        iVar2 = zcl_attr_type_is_analog(*(undefined1 *)(puVar15 + 1));
        if (iVar2 != 0) {
          zcl_packet_append_variable_attr_value
                    (rsp._32_4_,*(undefined1 *)(puVar15 + 1),iVar4 + 0x18);
        }
      }
      else {
        uVar1 = *(uint16_t *)(iVar4 + 0x10);
_L0:
        zmsg_append_le16((zmsg_t *)rsp._32_4_,uVar1);
      }
    }
    goto _L0;
  }
  uVar16 = 9;
  goto _L0;
_L0:
  uVar5 = 0x80;
  goto _L0;
_L0:
  uVar5 = 0x80;
  goto _L0;
_L0:
  if ((ushort)message_1._16_2_ < uVar5) {
    auStack_11c[0] = 0;
    af_read_le16(pzVar22,(uint16_t *)&message_1.out,auStack_11c);
    psVar6 = (short *)zcl_get_attr_desc((packet->header).dst_ep,(packet->header).cluster_id,
                                        (((packet->header).fc & 8) != 0) + '\x01',auStack_11c[0],
                                        uVar23);
    bVar19 = 0x86;
    if (psVar6 != (short *)0x0) {
      bVar18 = *(byte *)((int)psVar6 + 3);
      bVar19 = 0x7e;
      if (((bVar18 & 1) != 0) && (bVar19 = bVar18 & 0x40, (bVar18 & 0x40) != 0)) {
        bVar19 = 0x7e;
      }
    }
    uVar7 = zcl_packet_max_available_space
                      ((packet->header).cluster_id,0,*(ushort *)&(packet->header).fc >> 2 & 1);
    uVar8 = zmsg_get_length(rsp._32_4_);
    if (uVar7 <= uVar8) {
      uVar5 = 0x89;
      goto _L0;
    }
    zmsg_append_le16((zmsg_t *)rsp._32_4_,auStack_11c[0]);
    zmsg_append_u8((zmsg_t *)rsp._32_4_,bVar19);
    if (bVar19 == 0) {
      zmsg_append_u8((zmsg_t *)rsp._32_4_,(uint8_t)psVar6[1]);
      if ((((packet->header).cluster_id == 10) && (((packet->header).fc & 8) == 0)) &&
         (((ushort)(*psVar6 - 6U) < 2 || (*psVar6 == 0)))) {
        local_70 = 0;
        iVar4 = zcl_time_cluster_read_time((packet->header).dst_ep,&local_70);
        if (iVar4 != 0) goto _L0;
        puVar17 = &local_70;
      }
      else {
        puVar17 = *(undefined4 **)(psVar6 + 4);
      }
      zcl_packet_append_variable_attr_value(rsp._32_4_,(char)psVar6[1],puVar17);
    }
    goto _L0;
  }
  uVar16 = 1;
_L0:
  iVar4 = zcl_packet_setup_response(auStack_58,packet,uVar16);
  goto _L0;
_L0:
  uVar5 = 0x8b;
  goto _L0;
_L0:
  if ((local_70 & 0xffff) < uVar5) {
    peVar20 = (ezb_zcl_cmd_hdr_t *)calloc(1,0xc);
    *(ezb_zcl_cmd_hdr_t **)((int)&(peVar20->src_addr).u + 6) = message_2.in.header;
    message_2.in.header = peVar20;
    af_read_le16(pzVar22,(uint16_t *)&local_70,(uint16_t *)peVar20);
    af_read_le8(pzVar22,(uint16_t *)&local_70,(uint8_t *)&(peVar20->src_addr).u.short_addr);
    if (uVar5 < (local_70 & 0xffff)) goto _L0;
    if (*(char *)&(peVar20->src_addr).u == '\0') {
      af_read_le8(pzVar22,(uint16_t *)&local_70,
                  (uint8_t *)((int)&(peVar20->src_addr).u.group_addr.group + 1));
      sVar10 = zcl_packet_read_variable_attr_size
                         (pzVar22,local_70 & 0xffff,*(undefined1 *)((int)&(peVar20->src_addr).u + 1)
                         );
      if (sVar10 == 0xffff) {
        uVar5 = 0x85;
        goto _L0;
      }
      pvVar9 = calloc(1,sVar10);
      *(void **)((int)&(peVar20->src_addr).u + 2) = pvVar9;
      if ((pvVar9 == (void *)0x0) && (sVar10 != 0)) {
        uVar5 = 0x89;
        goto _L0;
      }
      zcl_packet_read_variable_attr_value
                (pzVar22,&local_70,*(undefined1 *)((int)&(peVar20->src_addr).u + 1),pvVar9);
    }
    goto _L0;
  }
  if (((packet->header).cluster_id != 10) ||
     (iVar4 = zcl_time_server_read_attr_rsp_handler(&write_attr_req.attr_value), iVar4 == 0)) {
    message_2.in.variables =
         (ezb_zcl_read_attr_rsp_variable_t *)CONCAT31(message_2.in.variables._1_3_,0xfe);
    zcl_core_action_schedule(1,&write_attr_req.attr_value);
    uVar5 = (uint)message_2.in.variables & 0xff;
    if (uVar5 != 0xfe) goto _L0;
  }
  uVar5 = 0;
_L0:
  while (message_2.in.header != (ezb_zcl_cmd_hdr_t *)0x0) {
    peVar20 = *(ezb_zcl_cmd_hdr_t **)((int)&((message_2.in.header)->src_addr).u + 6);
    if (*(int *)((int)&((message_2.in.header)->src_addr).u + 2) != 0) {
      mm_free();
    }
    mm_free(message_2.in.header);
    message_2.in.header = peVar20;
  }
_L0:
  iVar4 = zcl_packet_setup_default_response(auStack_58,packet,uVar5);
_L0:
  if (iVar4 == 0) {
    zcl_packet_send(auStack_58,0);
  }
  else {
_L0:
    zcl_packet_free(auStack_58);
  }
  return (zcl_status_t)iVar4;
}

