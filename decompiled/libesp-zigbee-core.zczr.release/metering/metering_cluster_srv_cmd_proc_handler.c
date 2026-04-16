/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> metering.o -> metering_cluster_srv_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t metering_cluster_srv_cmd_proc_handler(void *arg)

{
  byte bVar1;
  ezb_zcl_status_t eVar2;
  uint16_t uVar3;
  int iVar4;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  undefined2 extraout_var_07;
  undefined2 extraout_var_08;
  undefined2 extraout_var_09;
  int iVar5;
  uint uVar6;
  ezb_err_t eVar7;
  undefined2 extraout_var_10;
  undefined2 extraout_var_11;
  undefined2 extraout_var_12;
  undefined2 extraout_var_13;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint uVar8;
  undefined4 uVar9;
  uint16_t local_80;
  uint16_t uStack_7e;
  uint16_t offset;
  uint16_t offset_1;
  ezb_zcl_cmd_cnf_ctx_t cnf_ctx;
  zcl_packet_t rsp;
  ezb_zcl_metering_get_sampled_data_req_message_t message;
  
  memset(&cnf_ctx.user_ctx,0,0x28);
  _offset = (ezb_zcl_metering_get_sampled_data_rsp_t *)0x0;
  cnf_ctx.cb = (ezb_af_user_cnf_callback_t)0x0;
  iVar4 = 1;
  if (arg == (void *)0x0) goto _L0;
  iVar4 = 1;
  if (((*(byte *)((int)arg + 0x1a) >> 3 & 1) != 0) ||
     (iVar4 = zcl_packet_init(&cnf_ctx.user_ctx,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar4 != 0))
  goto _L0;
  bVar1 = *(byte *)((int)arg + 0x20);
  if (bVar1 == 6) {
    memset(&rsp.payload,0,0x2c);
    uStack_7e = 0;
    uVar3 = af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_7e,(uint32_t *)&message.in);
    if ((((CONCAT22(extraout_var_10,uVar3) == 0) ||
         (uVar3 = af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_7e,
                               (uint32_t *)&message.in.payload),
         CONCAT22(extraout_var_11,uVar3) == 0)) ||
        (uVar3 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_7e,
                             (uint8_t *)&message.in.payload.earliest_start_time),
        CONCAT22(extraout_var_12,uVar3) == 0)) ||
       ((uVar3 = af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_7e,
                              (uint32_t *)&message.in.payload.sample_type),
        CONCAT22(extraout_var_13,uVar3) == 0 ||
        (uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24)), uVar8 < uStack_7e)))) {
      uVar8 = 0x80;
    }
    else {
      uVar8 = zcl_packet_to_message(&rsp.payload,arg);
      if (uVar8 == 0) {
        message.out.result = 0xfe;
        message._4_4_ = arg;
        zcl_core_action_schedule(0x46,&rsp.payload);
        uVar8 = message.out._0_4_ & 0xff;
        if (uVar8 == 0xfe) {
          uVar8 = 0;
        }
        if ((char)rsp.payload == -2) {
          uVar8 = 0x8b;
        }
        else if (uVar8 == 0) {
          eVar7 = zmsg_append_le32((zmsg_t *)rsp._32_4_,*(uint32_t *)message.out.payload);
          if ((((eVar7 == 0) &&
               (eVar7 = zmsg_append_le32((zmsg_t *)rsp._32_4_,(message.out.payload)->start_time),
               eVar7 == 0)) &&
              ((eVar7 = zmsg_append_u8((zmsg_t *)rsp._32_4_,(message.out.payload)->sample_type),
               eVar7 == 0 &&
               (((eVar7 = zmsg_append_u8((zmsg_t *)rsp._32_4_,(message.out.payload)->field_0x9),
                 eVar7 == 0 &&
                 (eVar7 = zmsg_append_u8((zmsg_t *)rsp._32_4_,
                                         (uint8_t)(message.out.payload)->req_interval), eVar7 == 0))
                && (eVar7 = zmsg_append_le32((zmsg_t *)rsp._32_4_,
                                             *(uint32_t *)&(message.out.payload)->num_of_samples),
                   eVar7 == 0)))))) &&
             (eVar7 = zmsg_append_u8((zmsg_t *)rsp._32_4_,
                                     *(uint8_t *)&(message.out.payload)->samples), eVar7 == 0)) {
            bVar1 = *(byte *)&(message.out.payload)->samples;
            if (bVar1 == 4) {
_L0:
              eVar2 = append_tou_info_no_billing_set_to_payload
                                ((zcl_packet_payload_t *)rsp._32_4_,
                                 (ezb_zcl_metering_tou_info_no_billing_set_t *)
                                 &message.out.payload[1].start_time);
              uVar8 = CONCAT31(extraout_var_00,eVar2);
            }
            else if (bVar1 < 5) {
              if ((bVar1 == 2) || (bVar1 == 3)) {
                eVar2 = append_block_info_set_to_payload
                                  ((zcl_packet_payload_t *)rsp._32_4_,
                                   (ezb_zcl_metering_block_info_set_t *)
                                   &message.out.payload[1].start_time);
                uVar8 = CONCAT31(extraout_var_01,eVar2);
              }
              else {
                eVar2 = append_tou_info_set_to_payload
                                  ((zcl_packet_payload_t *)rsp._32_4_,
                                   (ezb_zcl_metering_tou_info_set_t *)
                                   &message.out.payload[1].start_time);
                uVar8 = CONCAT31(extraout_var,eVar2);
              }
            }
            else {
              if ((bVar1 != 6) && (bVar1 != 7)) {
                uVar8 = 1;
                if (bVar1 != 5) goto _L0;
                goto _L0;
              }
              eVar2 = append_block_info_no_billing_set_to_payload
                                ((zcl_packet_payload_t *)rsp._32_4_,
                                 (ezb_zcl_metering_block_info_no_billing_set_t *)
                                 &message.out.payload[1].start_time);
              uVar8 = CONCAT31(extraout_var_02,eVar2);
            }
            if (uVar8 == 0) {
              _offset = (ezb_zcl_metering_get_sampled_data_rsp_t *)message.out.cnf_ctx.cb;
              cnf_ctx.cb = (ezb_af_user_cnf_callback_t)message.out.cnf_ctx.user_ctx;
              uVar8 = zcl_packet_setup_response(&cnf_ctx.user_ctx,arg,6);
              if (uVar8 == 0) goto _L0;
            }
          }
          else {
            uVar8 = 0x89;
          }
        }
      }
    }
_L0:
    iVar5 = zcl_packet_setup_default_response(&cnf_ctx.user_ctx,arg,uVar8);
    if (iVar5 != 0) {
      zcl_packet_free(&cnf_ctx.user_ctx);
      iVar4 = iVar5;
      goto _L0;
    }
  }
  else {
    if (6 < bVar1) {
      if (bVar1 == 8) {
        memset(&rsp.payload,0,0x28);
        local_80 = 0;
        uVar3 = af_read_le16(*(zmsg_t **)((int)arg + 0x24),&local_80,(uint16_t *)&message.in);
        if ((((CONCAT22(extraout_var_03,uVar3) == 0) ||
             (uVar3 = af_read_le32(*(zmsg_t **)((int)arg + 0x24),&local_80,
                                   (uint32_t *)&message.in.payload),
             CONCAT22(extraout_var_04,uVar3) == 0)) ||
            (uVar3 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&local_80,
                                 (uint8_t *)&message.in.payload.earliest_start_time),
            CONCAT22(extraout_var_05,uVar3) == 0)) ||
           ((uVar3 = af_read_le16(*(zmsg_t **)((int)arg + 0x24),&local_80,
                                  (uint16_t *)((int)&message.in.payload.earliest_start_time + 2)),
            CONCAT22(extraout_var_06,uVar3) == 0 ||
            (uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24)), uVar8 < local_80))))
        goto _L0;
        uVar8 = 0x87;
        if ((message.in.payload.earliest_start_time._2_2_ != 0) &&
           (uVar8 = zcl_packet_to_message(&rsp.payload,arg,0x87), uVar8 == 0)) {
          message.in.payload.sample_type = 0xfe;
          message._4_4_ = arg;
          zcl_core_action_schedule(0x48,&rsp.payload,0);
          uVar8 = message.in.payload._8_4_ & 0xff;
          if (uVar8 == 0xfe) {
            uVar8 = 0;
          }
          if ((char)rsp.payload != -2) {
            if (uVar8 != 0) goto _L0;
            if ((*(short *)(message.out._0_4_ + 0xc) != 0) &&
               (*(int *)(message.out._0_4_ + 0x10) != 0)) {
              uStack_7e = *(uint16_t *)message.out._0_4_;
              iVar5 = zmsg_append_bytes(rsp._32_4_,2,&uStack_7e);
              if ((iVar5 == 0) &&
                 ((eVar7 = zmsg_append_le32((zmsg_t *)rsp._32_4_,
                                            *(uint32_t *)(message.out._0_4_ + 4)), eVar7 == 0 &&
                  (eVar7 = zmsg_append_u8((zmsg_t *)rsp._32_4_,*(uint8_t *)(message.out._0_4_ + 8)),
                  eVar7 == 0)))) {
                uStack_7e = *(ushort *)(message.out._0_4_ + 10);
                iVar5 = zmsg_append_bytes(rsp._32_4_,2,&uStack_7e);
                if (iVar5 == 0) {
                  uStack_7e = *(ushort *)(message.out._0_4_ + 0xc);
                  iVar5 = zmsg_append_bytes(rsp._32_4_,2,&uStack_7e);
                  if (iVar5 == 0) {
                    uVar8 = (uint)*(ushort *)(message.out._0_4_ + 0xc);
                    if ((uint)message.in.payload.earliest_start_time._2_2_ <
                        (uint)*(ushort *)(message.out._0_4_ + 0xc)) {
                      uVar8 = (uint)message.in.payload.earliest_start_time._2_2_;
                    }
                    uVar6 = 0;
                    do {
                      if (uVar8 <= (uVar6 & 0xffff)) {
                        uVar9 = 7;
                        _offset = message.out.payload;
                        cnf_ctx.cb = message.out.cnf_ctx.cb;
                        goto _L0;
                      }
                      iVar5 = uVar6 * 4;
                      uVar6 = uVar6 + 1;
                      iVar5 = zcl_packet_append_variable_attr_value
                                        (rsp._32_4_,0x22,*(int *)(message.out._0_4_ + 0x10) + iVar5)
                      ;
                    } while (iVar5 == 0);
                  }
                }
              }
              goto _L0;
            }
          }
_L0:
          uVar8 = 0x8b;
        }
      }
      else {
_L0:
        uVar8 = 0x81;
      }
      goto _L0;
    }
    if (bVar1 == 0) {
      memset(&rsp.payload,0,0x28);
      uStack_7e = 0;
      uVar3 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_7e,(uint8_t *)&message.in);
      if ((((CONCAT22(extraout_var_07,uVar3) == 0) ||
           (uVar3 = af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_7e,
                                 (uint32_t *)&message.in.payload),
           CONCAT22(extraout_var_08,uVar3) == 0)) ||
          (uVar3 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_7e,
                               (uint8_t *)&message.in.payload.earliest_start_time),
          CONCAT22(extraout_var_09,uVar3) == 0)) ||
         (uVar8 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24)), uVar8 < uStack_7e)) {
_L0:
        uVar8 = 0x80;
      }
      else {
        uVar8 = 0x87;
        if (((byte)message.in.payload.earliest_start_time != 0) &&
           (uVar8 = zcl_packet_to_message(&rsp.payload,arg,0x87), uVar8 == 0)) {
          message.in.payload.sample_type = 0xfe;
          message._4_4_ = arg;
          zcl_core_action_schedule(0x42,&rsp.payload,0);
          uVar8 = message.in.payload._8_4_ & 0xff;
          if (uVar8 == 0xfe) {
            uVar8 = 0;
          }
          if ((char)rsp.payload == -2) goto _L0;
          if (uVar8 == 0) {
            if (message.out._0_4_ == 0) {
_L0:
              uVar8 = 1;
            }
            else {
              eVar7 = zmsg_append_le32((zmsg_t *)rsp._32_4_,*(uint32_t *)message.out._0_4_);
              if (((eVar7 == 0) &&
                  (eVar7 = zmsg_append_u8((zmsg_t *)rsp._32_4_,*(uint8_t *)(message.out._0_4_ + 4)),
                  eVar7 == 0)) &&
                 ((eVar7 = zmsg_append_u8((zmsg_t *)rsp._32_4_,*(uint8_t *)(message.out._0_4_ + 8)),
                  eVar7 == 0 &&
                  (eVar7 = zmsg_append_u8((zmsg_t *)rsp._32_4_,*(uint8_t *)(message.out._0_4_ + 0xc)
                                         ), eVar7 == 0)))) {
                uVar8 = (uint)*(byte *)(message.out._0_4_ + 0xc);
                if ((uVar8 != 0) && (*(int *)(message.out._0_4_ + 0x10) == 0)) goto _L0;
                uVar6 = (uint)(byte)message.in.payload.earliest_start_time;
                if (uVar8 < (byte)message.in.payload.earliest_start_time) {
                  uVar6 = uVar8;
                }
                uVar8 = 0;
                do {
                  if (uVar6 <= (uVar8 & 0xff)) {
                    uVar9 = 0;
                    _offset = message.out.payload;
                    cnf_ctx.cb = message.out.cnf_ctx.cb;
                    goto _L0;
                  }
                  iVar5 = uVar8 * 4;
                  uVar8 = uVar8 + 1;
                  iVar5 = zcl_packet_append_variable_attr_value
                                    (rsp._32_4_,0x22,*(int *)(message.out._0_4_ + 0x10) + iVar5);
                } while (iVar5 == 0);
              }
_L0:
              uVar8 = 0x89;
            }
          }
        }
      }
      goto _L0;
    }
    if (bVar1 != 3) goto _L0;
    memset(&rsp.payload,0,0x1c);
    uVar8 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),0,2,&message.in);
    if ((uVar8 == 0) || (uVar6 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24)), uVar6 < uVar8))
    goto _L0;
    uVar8 = zcl_packet_to_message(&rsp.payload,arg);
    if (uVar8 != 0) goto _L0;
    message.in.payload.sample_id._0_1_ = 0xfe;
    message._4_4_ = arg;
    zcl_core_action_schedule(0x44,&rsp.payload,0);
    uVar8 = (uint)(byte)message.in.payload.sample_id;
    if (uVar8 == 0xfe) {
      uVar8 = 0;
    }
    if ((char)rsp.payload == -2) goto _L0;
    if (uVar8 != 0) goto _L0;
    eVar7 = zmsg_append_u8((zmsg_t *)rsp._32_4_,(byte)message.in.payload.earliest_start_time);
    if ((eVar7 != 0) ||
       (eVar7 = zmsg_append_le32((zmsg_t *)rsp._32_4_,message.in.payload._8_4_), eVar7 != 0))
    goto _L0;
    uVar9 = 3;
_L0:
    uVar8 = zcl_packet_setup_response(&cnf_ctx.user_ctx,arg,uVar9);
    if (uVar8 != 0) goto _L0;
  }
_L0:
  zcl_packet_send(&cnf_ctx.user_ctx,&offset);
_L0:
  return (ezb_zcl_status_t)iVar4;
}

