/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> metering.o -> metering_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t metering_cluster_cli_cmd_proc_handler(void *arg)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  ezb_zcl_status_t eVar4;
  uint16_t uVar5;
  undefined2 extraout_var_03;
  undefined2 extraout_var_04;
  undefined2 extraout_var_05;
  undefined2 extraout_var_06;
  undefined2 extraout_var_07;
  undefined2 extraout_var_08;
  undefined2 extraout_var_09;
  undefined2 extraout_var_10;
  undefined2 extraout_var_11;
  undefined2 extraout_var_12;
  undefined2 extraout_var_13;
  uint uVar6;
  undefined2 extraout_var_14;
  undefined2 extraout_var_15;
  undefined2 extraout_var_16;
  undefined2 extraout_var_17;
  undefined2 extraout_var_18;
  undefined2 extraout_var_19;
  undefined2 extraout_var_20;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  uint64_t *puVar7;
  uint64_t *puVar8;
  uint16_t uStack_a2;
  undefined1 auStack_a0 [2];
  uint16_t offset;
  zcl_packet_t rsp;
  ezb_zcl_metering_get_sampled_data_rsp_message_t message;
  ezb_zcl_metering_block_info_set_t eStack_50;
  byte bStack_28;
  
  iVar2 = 1;
  memset(auStack_a0,0,0x28);
  if (arg == (void *)0x0) goto _L0;
  iVar2 = 1;
  if (((*(byte *)((int)arg + 0x1a) & 8) == 0) ||
     (iVar2 = zcl_packet_init(auStack_a0,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar2 != 0))
  goto _L0;
  bVar1 = *(byte *)((int)arg + 0x20);
  if (bVar1 == 6) {
    memset(&rsp.payload,0,0x58);
    uStack_a2 = 0;
    uVar5 = af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,(uint32_t *)&message.in.payload);
    if ((((CONCAT22(extraout_var_14,uVar5) == 4) &&
         (uVar5 = af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,
                               &message.in.payload.start_time), CONCAT22(extraout_var_15,uVar5) == 4
         )) && (uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,
                                    &message.in.payload.sample_type),
               CONCAT22(extraout_var_16,uVar5) == 1)) &&
       (((uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,&message.in.payload.field_0x9
                             ), CONCAT22(extraout_var_17,uVar5) == 1 &&
         (uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,
                              (uint8_t *)&message.in.payload.req_interval),
         CONCAT22(extraout_var_18,uVar5) == 1)) &&
        ((uVar5 = af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,
                               (uint32_t *)&message.in.payload.num_of_samples),
         CONCAT22(extraout_var_19,uVar5) == 4 &&
         (uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,
                              (uint8_t *)&message.in.payload.samples),
         CONCAT22(extraout_var_20,uVar5) == 1)))))) {
      if ((byte)message.in.payload.samples == 4) {
_L0:
        eVar4 = parse_tou_info_no_billing_set_from_payload
                          (*(zcl_packet_payload_t **)((int)arg + 0x24),&uStack_a2,
                           (ezb_zcl_metering_tou_info_no_billing_set_t *)&eStack_50);
        uVar6 = CONCAT31(extraout_var_00,eVar4);
        if (uVar6 == 0) {
_L0:
          puVar7 = (uint64_t *)0x0;
          puVar8 = (uint64_t *)eStack_50.bill_to_date_time_stamp;
          goto _L0;
        }
      }
      else {
        if ((byte)message.in.payload.samples < 5) {
          if (((byte)message.in.payload.samples != 2) && ((byte)message.in.payload.samples != 3)) {
            eVar4 = parse_tou_info_set_from_payload
                              (*(zcl_packet_payload_t **)((int)arg + 0x24),&uStack_a2,
                               (ezb_zcl_metering_tou_info_set_t *)&eStack_50);
            uVar6 = CONCAT31(extraout_var,eVar4);
            eStack_50.bill_to_date_time_stamp = (uint32_t)eStack_50.tier_summation;
            if (uVar6 != 0) goto _L0;
            goto _L0;
          }
          eVar4 = parse_block_info_set_from_payload
                            (*(zcl_packet_payload_t **)((int)arg + 0x24),&uStack_a2,&eStack_50);
          uVar6 = CONCAT31(extraout_var_01,eVar4);
          puVar8 = eStack_50.tier_summation;
          puVar7 = eStack_50.tier_block_summation;
        }
        else {
          if (((byte)message.in.payload.samples != 6) && ((byte)message.in.payload.samples != 7)) {
            uVar6 = 0x87;
            if ((byte)message.in.payload.samples != 5) goto _L0;
            goto _L0;
          }
          eVar4 = parse_block_info_no_billing_set_from_payload
                            (*(zcl_packet_payload_t **)((int)arg + 0x24),&uStack_a2,
                             (ezb_zcl_metering_block_info_no_billing_set_t *)&eStack_50);
          uVar6 = CONCAT31(extraout_var_02,eVar4);
          puVar8 = (uint64_t *)eStack_50.bill_to_date_time_stamp;
          puVar7 = (uint64_t *)eStack_50.projected_bill_time_stamp;
        }
        if (uVar6 == 0) {
_L0:
          uVar6 = zcl_packet_to_message(&rsp.payload,arg);
          if (uVar6 == 0) {
            bStack_28 = 0xfe;
            message._4_4_ = arg;
            zcl_core_action_schedule(0x47,&rsp.payload);
            if (bStack_28 != 0xfe) {
              uVar6 = (uint)bStack_28;
            }
          }
          if (puVar8 != (uint64_t *)0x0) {
            mm_free(puVar8);
          }
          goto joined_r0x00010bbc;
        }
      }
    }
    else {
      uVar6 = 0x80;
    }
  }
  else if (bVar1 < 7) {
    if (bVar1 == 0) {
      memset(&rsp.payload,0,0x24);
      uStack_a2 = 0;
      uVar5 = af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,(uint32_t *)&message.in);
      if ((((CONCAT22(extraout_var_04,uVar5) == 0) ||
           (uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,
                                (uint8_t *)&message.in.payload),
           CONCAT22(extraout_var_05,uVar5) == 0)) ||
          (uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,
                               (uint8_t *)&message.in.payload.start_time),
          CONCAT22(extraout_var_06,uVar5) == 0)) ||
         (uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,
                              &message.in.payload.sample_type), CONCAT22(extraout_var_07,uVar5) == 0
         )) {
_L0:
        uVar6 = 0x80;
      }
      else {
        iVar2 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        uVar6 = (uint)message.in.payload.sample_type;
        if (iVar2 < (int)((uint)uStack_a2 + uVar6 * 3)) goto _L0;
        if (uVar6 == 0) {
_L0:
          uVar6 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
          if (uVar6 < uStack_a2) goto _L0;
          uVar6 = zcl_packet_to_message(&rsp.payload,arg);
          if (uVar6 == 0) {
            message.in.payload.samples._0_1_ = 0xfe;
            message._4_4_ = arg;
            zcl_core_action_schedule(0x43,&rsp.payload);
            if ((byte)message.in.payload.samples != 0xfe) {
              uVar6 = (uint)(byte)message.in.payload.samples;
            }
          }
        }
        else {
          message.in.payload._12_4_ = calloc(uVar6,4);
          uVar6 = 0x89;
          uVar3 = 0;
          if ((void *)message.in.payload._12_4_ != (void *)0x0) {
            while( true ) {
              if (message.in.payload.sample_type <= uVar3) break;
              iVar2 = zcl_packet_read_variable_attr_value
                                (*(undefined4 *)((int)arg + 0x24),&uStack_a2,0x22,
                                 uVar3 * 4 + message.in.payload._12_4_);
              if (iVar2 == 0) goto _L0;
              uVar3 = uVar3 + 1 & 0xff;
            }
            goto _L0;
          }
        }
      }
      if (message.in.payload._12_4_ != 0) {
        mm_free();
      }
    }
    else {
      if (bVar1 == 3) {
        memset(&rsp.payload,0,0x18);
        uStack_a2 = 0;
        uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,(uint8_t *)&message.in);
        if (((CONCAT22(extraout_var_12,uVar5) == 0) ||
            (uVar5 = af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,
                                  (uint32_t *)&message.in.payload),
            CONCAT22(extraout_var_13,uVar5) == 0)) ||
           (uVar6 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24)), uVar6 < uStack_a2)) {
          uVar6 = 0x80;
        }
        else {
          uVar6 = zcl_packet_to_message(&rsp.payload,arg);
          if (uVar6 == 0) {
            message.in.payload.start_time._0_1_ = 0xfe;
            message._4_4_ = arg;
            zcl_core_action_schedule(0x45,&rsp.payload,0);
            if ((byte)message.in.payload.start_time != 0xfe) {
              uVar6 = (uint)(byte)message.in.payload.start_time;
            }
          }
        }
        goto _L0;
      }
_L0:
      uVar6 = 0x81;
    }
  }
  else {
    if (bVar1 != 7) goto _L0;
    memset(&rsp.payload,0,0x24);
    uStack_a2 = 0;
    uVar5 = af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,(uint16_t *)&message.in);
    if ((((CONCAT22(extraout_var_03,uVar5) != 0) &&
         (uVar5 = af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,
                               (uint32_t *)&message.in.payload),
         CONCAT22(extraout_var_08,uVar5) != 0)) &&
        (uVar5 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,
                             (uint8_t *)&message.in.payload.start_time),
        CONCAT22(extraout_var_09,uVar5) != 0)) &&
       ((uVar5 = af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,
                              (uint16_t *)((int)&message.in.payload.start_time + 2)),
        CONCAT22(extraout_var_10,uVar5) != 0 &&
        (uVar5 = af_read_le16(*(zmsg_t **)((int)arg + 0x24),&uStack_a2,
                              (uint16_t *)&message.in.payload.sample_type),
        CONCAT22(extraout_var_11,uVar5) != 0)))) {
      iVar2 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
      uVar6 = (uint)(ushort)message.in.payload._8_2_;
      if ((int)((uint)uStack_a2 + uVar6 * 3) <= iVar2) {
        if (uVar6 != 0) {
          message.in.payload._12_4_ = calloc(uVar6,4);
          uVar6 = 0x89;
          puVar7 = (uint64_t *)message.in.payload._12_4_;
          if ((uint64_t *)message.in.payload._12_4_ == (uint64_t *)0x0) goto joined_r0x00010bbc;
          for (uVar6 = 0; uVar6 < (ushort)message.in.payload._8_2_; uVar6 = uVar6 + 1 & 0xffff) {
            iVar2 = zcl_packet_read_variable_attr_value
                              (*(undefined4 *)((int)arg + 0x24),&uStack_a2,0x22,
                               uVar6 * 4 + message.in.payload._12_4_);
            if (iVar2 == 0) goto _L0;
          }
        }
        uVar6 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        if (uStack_a2 <= uVar6) {
          uVar6 = zcl_packet_to_message(&rsp.payload,arg);
          puVar7 = (uint64_t *)message.in.payload._12_4_;
          if (uVar6 == 0) {
            message.in.payload.samples._0_1_ = 0xfe;
            message._4_4_ = arg;
            zcl_core_action_schedule(0x49,&rsp.payload);
            puVar7 = (uint64_t *)message.in.payload._12_4_;
            if ((byte)message.in.payload.samples != 0xfe) {
              uVar6 = (uint)(byte)message.in.payload.samples;
            }
          }
          goto joined_r0x00010bbc;
        }
      }
    }
_L0:
    uVar6 = 0x80;
    puVar7 = (uint64_t *)message.in.payload._12_4_;
joined_r0x00010bbc:
    if (puVar7 != (uint64_t *)0x0) {
      mm_free(puVar7);
    }
  }
_L0:
  iVar2 = zcl_packet_setup_default_response(auStack_a0,arg,uVar6);
  if (iVar2 == 0) {
    zcl_packet_send(auStack_a0,0);
  }
  else {
    zcl_packet_free(auStack_a0);
  }
_L0:
  return (ezb_zcl_status_t)iVar2;
}

