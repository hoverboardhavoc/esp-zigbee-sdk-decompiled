/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> metering.o -> metering_cluster_publish_snapshot_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
metering_cluster_publish_snapshot_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint16_t uVar2;
  undefined2 extraout_var_07;
  undefined2 extraout_var_08;
  undefined2 extraout_var_09;
  undefined2 extraout_var_10;
  undefined2 extraout_var_11;
  undefined2 extraout_var_12;
  undefined2 extraout_var_13;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint16_t uStack_7a;
  undefined1 auStack_78 [2];
  uint16_t offset;
  ezb_zcl_metering_publish_snapshot_command_message_t message;
  
  memset(auStack_78,0,0x58);
  uStack_7a = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/metering.c",0x209,
                  "metering_cluster_publish_snapshot_cmd_handler","packet && rsp");
  }
  else {
    uVar2 = af_read_le32(packet->payload,&uStack_7a,(uint32_t *)&message.in.field_0x4);
    if (CONCAT22(extraout_var_07,uVar2) != 4) {
      uVar3 = 0;
      uVar4 = 0x80;
      goto _L0;
    }
  }
  uVar2 = af_read_le32(packet->payload,&uStack_7a,&message.in.payload.snapshot_id);
  if (CONCAT22(extraout_var_08,uVar2) == 4) {
    uVar2 = af_read_le8(packet->payload,&uStack_7a,(uint8_t *)&message.in.payload.snapshot_time);
    if (CONCAT22(extraout_var_09,uVar2) == 1) {
      uVar2 = af_read_le8(packet->payload,&uStack_7a,
                          (uint8_t *)((int)&message.in.payload.snapshot_time + 1));
      if (CONCAT22(extraout_var_10,uVar2) == 1) {
        uVar2 = af_read_le8(packet->payload,&uStack_7a,
                            (uint8_t *)((int)&message.in.payload.snapshot_time + 2));
        if (CONCAT22(extraout_var_11,uVar2) == 1) {
          uVar2 = af_read_le32(packet->payload,&uStack_7a,
                               (uint32_t *)&message.in.payload.total_snapshots_found);
          if (CONCAT22(extraout_var_12,uVar2) == 4) {
            uVar2 = af_read_le8(packet->payload,&uStack_7a,
                                (uint8_t *)&message.in.payload.snapshot_cause);
            if (CONCAT22(extraout_var_13,uVar2) == 1) {
              if ((byte)message.in.payload.snapshot_cause == 4) {
                eVar1 = parse_tou_info_no_billing_set_from_payload
                                  (packet->payload,&uStack_7a,
                                   (ezb_zcl_metering_tou_info_no_billing_set_t *)
                                   &message.in.payload.field_0x14);
                uVar4 = CONCAT31(extraout_var_04,eVar1);
                if (uVar4 != 0) {
                  uVar3 = 0;
                  goto _L0;
                }
                uVar3 = 0;
                uVar5 = message.in.payload.sub_payload.tou_delivered.bill_to_date;
              }
              else if ((byte)message.in.payload.snapshot_cause < 5) {
                if ((byte)message.in.payload.snapshot_cause == 2) {
                  eVar1 = parse_block_info_set_from_payload
                                    (packet->payload,&uStack_7a,
                                     (ezb_zcl_metering_block_info_set_t *)
                                     &message.in.payload.field_0x14);
                  uVar4 = CONCAT31(extraout_var_03,eVar1);
                  uVar3 = message.in.payload.sub_payload._32_4_;
                  uVar5 = message.in.payload.sub_payload._24_4_;
                  if (uVar4 != 0) {
                    uVar3 = 0;
                    goto _L0;
                  }
                }
                else if ((byte)message.in.payload.snapshot_cause < 3) {
                  if ((byte)message.in.payload.snapshot_cause == 0) {
                    eVar1 = parse_tou_info_set_from_payload
                                      (packet->payload,&uStack_7a,
                                       (ezb_zcl_metering_tou_info_set_t *)
                                       &message.in.payload.field_0x14);
                    uVar4 = CONCAT31(extraout_var_02,eVar1);
                    if (uVar4 != 0) {
                      uVar3 = 0;
                      goto _L0;
                    }
                    uVar3 = 0;
                    uVar5 = message.in.payload.sub_payload._24_4_;
                  }
                  else {
                    if ((byte)message.in.payload.snapshot_cause != 1) {
                      uVar3 = 0;
                      uVar4 = 0x87;
                      goto _L0;
                    }
                    eVar1 = parse_tou_info_set_from_payload
                                      (packet->payload,&uStack_7a,
                                       (ezb_zcl_metering_tou_info_set_t *)
                                       &message.in.payload.field_0x14);
                    uVar4 = CONCAT31(extraout_var,eVar1);
                    if (uVar4 != 0) {
                      uVar3 = 0;
                      goto _L0;
                    }
                    uVar3 = 0;
                    uVar5 = message.in.payload.sub_payload._24_4_;
                  }
                }
                else {
                  if ((byte)message.in.payload.snapshot_cause != 3) {
                    uVar3 = 0;
                    uVar4 = 0x87;
                    goto _L0;
                  }
                  eVar1 = parse_block_info_set_from_payload
                                    (packet->payload,&uStack_7a,
                                     (ezb_zcl_metering_block_info_set_t *)
                                     &message.in.payload.field_0x14);
                  uVar4 = CONCAT31(extraout_var_00,eVar1);
                  uVar3 = message.in.payload.sub_payload._32_4_;
                  uVar5 = message.in.payload.sub_payload._24_4_;
                  if (uVar4 != 0) {
                    uVar3 = 0;
                    goto _L0;
                  }
                }
              }
              else if ((byte)message.in.payload.snapshot_cause == 6) {
                eVar1 = parse_block_info_no_billing_set_from_payload
                                  (packet->payload,&uStack_7a,
                                   (ezb_zcl_metering_block_info_no_billing_set_t *)
                                   &message.in.payload.field_0x14);
                uVar4 = CONCAT31(extraout_var_05,eVar1);
                uVar3 = message.in.payload.sub_payload.tou_delivered.projected_bill;
                uVar5 = message.in.payload.sub_payload.tou_delivered.bill_to_date;
                if (uVar4 != 0) {
                  uVar3 = 0;
                  goto _L0;
                }
              }
              else if ((byte)message.in.payload.snapshot_cause == 7) {
                eVar1 = parse_block_info_no_billing_set_from_payload
                                  (packet->payload,&uStack_7a,
                                   (ezb_zcl_metering_block_info_no_billing_set_t *)
                                   &message.in.payload.field_0x14);
                uVar4 = CONCAT31(extraout_var_06,eVar1);
                uVar3 = message.in.payload.sub_payload.tou_delivered.projected_bill;
                uVar5 = message.in.payload.sub_payload.tou_delivered.bill_to_date;
                if (uVar4 != 0) {
                  uVar3 = 0;
                  goto _L0;
                }
              }
              else {
                if ((byte)message.in.payload.snapshot_cause != 5) {
                  uVar3 = 0;
                  uVar4 = 0x87;
                  goto _L0;
                }
                eVar1 = parse_tou_info_no_billing_set_from_payload
                                  (packet->payload,&uStack_7a,
                                   (ezb_zcl_metering_tou_info_no_billing_set_t *)
                                   &message.in.payload.field_0x14);
                uVar4 = CONCAT31(extraout_var_01,eVar1);
                if (uVar4 != 0) {
                  uVar3 = 0;
                  goto _L0;
                }
                uVar3 = 0;
                uVar5 = message.in.payload.sub_payload.tou_delivered.bill_to_date;
              }
              uVar4 = zcl_packet_to_message(auStack_78,packet);
              if (uVar4 == 0) {
                message.in.payload.sub_payload._36_1_ = 0xfe;
                message._4_4_ = packet;
                zcl_core_action_schedule(0x47,auStack_78);
                if ((byte)message.in.payload.sub_payload._36_1_ != 0xfe) {
                  uVar4 = (uint)(byte)message.in.payload.sub_payload._36_1_;
                }
              }
              if (uVar5 != 0) {
                mm_free(uVar5);
              }
            }
            else {
              uVar3 = 0;
              uVar4 = 0x80;
            }
          }
          else {
            uVar3 = 0;
            uVar4 = 0x80;
          }
        }
        else {
          uVar3 = 0;
          uVar4 = 0x80;
        }
      }
      else {
        uVar3 = 0;
        uVar4 = 0x80;
      }
    }
    else {
      uVar3 = 0;
      uVar4 = 0x80;
    }
  }
  else {
    uVar3 = 0;
    uVar4 = 0x80;
  }
_L0:
  if (uVar3 != 0) {
    mm_free(uVar3);
  }
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar4);
  return eVar1;
}

