/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> price.o -> price_cluster_publish_price_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t price_cluster_publish_price_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  byte bVar1;
  uint16_t *unaff_s1;
  uint uVar2;
  ezb_zcl_status_t eVar3;
  uint16_t uVar4;
  undefined2 extraout_var;
  int iVar5;
  ezb_zcl_cmd_hdr_t *peStack_7c;
  uint16_t uStack_76;
  ezb_zcl_cmd_hdr_t *peStack_74;
  uint16_t temp_u16;
  uint32_t temp_u32;
  undefined1 uStack_6c;
  uint8_t map_value;
  uint16_t offset;
  ezb_zcl_price_publish_price_message_t message;
  
  memset(&uStack_6c,0,0x4c);
  temp_u32._2_2_ = 0;
  temp_u32._1_1_ = 0;
  peStack_74 = (ezb_zcl_cmd_hdr_t *)0x0;
  uStack_76 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    uVar4 = 0x1644;
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/price.c",0xcd,
                  "packet && rsp");
  }
  else {
    unaff_s1 = (uint16_t *)((int)&temp_u32 + 2);
    af_read_le32(packet->payload,unaff_s1,(uint32_t *)&stack0xffffff8c);
    message.in.header = peStack_74;
    uVar4 = af_read_le8(packet->payload,unaff_s1,(uint8_t *)&message.in.payload);
    if (CONCAT22(extraout_var,uVar4) == 0) {
      uVar2 = 0x80;
      goto _L0;
    }
    uVar4 = (uint16_t)(byte)message.in.payload.provider_id;
    if (0xc < (byte)message.in.payload.provider_id) {
      uVar2 = 0x87;
      goto _L0;
    }
  }
  af_read_bytes(packet->payload,unaff_s1,uVar4,(uint8_t *)((int)&message.in.payload.provider_id + 1)
               );
  af_read_le32(packet->payload,unaff_s1,(uint32_t *)&stack0xffffff8c);
  message.in.payload.rate_label[9] = (uint8_t)peStack_74;
  message.in.payload.rate_label[10] = (uint8_t)((uint)peStack_74 >> 8);
  message.in.payload.rate_label[0xb] = (uint8_t)((uint)peStack_74 >> 0x10);
  message.in.payload.rate_label[0xc] = (uint8_t)((uint)peStack_74 >> 0x18);
  af_read_le32(packet->payload,unaff_s1,(uint32_t *)&stack0xffffff8c);
  message.in.payload.issuer_event_id._0_1_ = (char)peStack_74;
  message.in.payload.issuer_event_id._1_1_ = (char)((uint)peStack_74 >> 8);
  message.in.payload.issuer_event_id._2_1_ = (char)((uint)peStack_74 >> 0x10);
  message.in.payload.issuer_event_id._3_1_ = (byte)((uint)peStack_74 >> 0x18);
  af_read_le8(packet->payload,unaff_s1,(uint8_t *)&message.in.payload.current_time);
  af_read_le16(packet->payload,unaff_s1,&uStack_76);
  message.in.payload.current_time._1_2_ = uStack_76;
  af_read_le8(packet->payload,unaff_s1,(uint8_t *)((int)&temp_u32 + 1));
  message.in.payload._24_2_ =
       (ushort)((temp_u32._1_1_ & 0xf) << 4) |
       message.in.payload._24_2_ & 0xff00 | (ushort)(temp_u32._1_1_ >> 4);
  af_read_le8(packet->payload,unaff_s1,(uint8_t *)((int)&temp_u32 + 1));
  message.in.payload._24_2_ =
       (ushort)((temp_u32._1_1_ & 0xf) << 0xc) |
       message.in.payload._24_2_ & 0xff | (ushort)(temp_u32._1_1_ >> 4) << 8;
  af_read_le32(packet->payload,unaff_s1,(uint32_t *)&stack0xffffff8c);
  message.in.payload.currency = (uint16_t)peStack_74;
  message.in.payload._28_2_ = (undefined2)((uint)peStack_74 >> 0x10);
  af_read_le16(packet->payload,unaff_s1,&uStack_76);
  message.in.payload.start_time._0_2_ = uStack_76;
  af_read_le32(packet->payload,unaff_s1,(uint32_t *)&stack0xffffff8c);
  message.in.payload._32_4_ = peStack_74;
  af_read_le8(packet->payload,unaff_s1,(uint8_t *)&message.in.payload.price);
  af_read_le32(packet->payload,unaff_s1,(uint32_t *)&stack0xffffff8c);
  message.in.payload.price._1_1_ = SUB41(peStack_74,0);
  message.in.payload.price._2_1_ = (undefined1)((uint)peStack_74 >> 8);
  message.in.payload.price._3_1_ = (undefined1)((uint)peStack_74 >> 0x10);
  message.in.payload.price_ratio = (uint8_t)((uint)peStack_74 >> 0x18);
  af_read_le8(packet->payload,unaff_s1,(uint8_t *)&message.in.payload.generation_price);
  af_read_le32(packet->payload,unaff_s1,(uint32_t *)&stack0xffffff8c);
  message.in.payload.generation_price._1_2_ = SUB42(peStack_74,0);
  message.in.payload._44_2_ = (undefined2)((uint)peStack_74 >> 0x10);
  af_read_le8(packet->payload,unaff_s1,(uint8_t *)&message.in.payload.alternate_cost_delivered);
  af_read_le8(packet->payload,unaff_s1,
              (uint8_t *)((int)&message.in.payload.alternate_cost_delivered + 1));
  af_read_le8(packet->payload,unaff_s1,
              (uint8_t *)((int)&message.in.payload.alternate_cost_delivered + 2));
  af_read_le8(packet->payload,unaff_s1,
              (uint8_t *)((int)&message.in.payload.alternate_cost_delivered + 3));
  af_read_le8(packet->payload,unaff_s1,&message.in.payload.alternate_cost_unit);
  af_read_le8(packet->payload,unaff_s1,&message.in.payload.alternate_cost_trailing_digit);
  af_read_le8(packet->payload,unaff_s1,&message.in.payload.number_of_block_thresholds);
  af_read_le8(packet->payload,unaff_s1,&message.in.payload.price_control);
  af_read_le8(packet->payload,unaff_s1,&message.in.payload.number_of_generation_tiers);
  uVar2 = zmsg_get_length(packet->payload);
  if (uVar2 < temp_u32._2_2_) {
    uVar2 = 0x80;
  }
  else {
    uVar2 = zcl_packet_to_message(&uStack_6c,packet);
    if (uVar2 == 0) {
      message.in.payload.extended_number_of_price_tiers = 0xfe;
      message._4_4_ = packet;
      zcl_core_action_schedule(0x4e,&uStack_6c);
      uVar2 = (uint)message.in.payload.extended_number_of_price_tiers;
      if (uVar2 == 0xfe) {
        uVar2 = 1;
      }
      else {
        bVar1 = message.in.payload.alternate_cost_delivered._3_1_ & 1;
        if ((message.in.payload.alternate_cost_delivered._3_1_ & 1) != 0) {
          peStack_7c = message.in.header;
          iVar5 = zmsg_append_bytes(rsp->payload,4,&peStack_7c);
          if (iVar5 != 0) {
            uVar2 = 0x89;
            goto _L0;
          }
          peStack_7c = (ezb_zcl_cmd_hdr_t *)
                       (message.in.payload._16_4_ << 0x18 |
                       (uint)message.in.payload.rate_label._8_4_ >> 8);
          iVar5 = zmsg_append_bytes(rsp->payload,4,&peStack_7c);
          if (iVar5 != 0) {
            uVar2 = 0x89;
            goto _L0;
          }
          peStack_7c = (ezb_zcl_cmd_hdr_t *)zcl_time_get_utc_time((packet->header).dst_ep);
          if (peStack_7c == (ezb_zcl_cmd_hdr_t *)0xffffffff) {
            peStack_7c = (ezb_zcl_cmd_hdr_t *)
                         ((uint)message.in.payload.issuer_event_id._3_1_ << 0x18 |
                         (uint)message.in.payload._16_4_ >> 8);
          }
          iVar5 = zmsg_append_bytes(rsp->payload,4,&peStack_7c);
          if (iVar5 != 0) {
            uVar2 = 0x89;
            goto _L0;
          }
          peStack_7c = (ezb_zcl_cmd_hdr_t *)
                       CONCAT31(peStack_7c._1_3_,message.in.payload.alternate_cost_delivered._3_1_);
          iVar5 = zmsg_append_bytes(rsp->payload,1,&peStack_7c);
          if (iVar5 != 0) {
            uVar2 = 0x89;
            goto _L0;
          }
          uVar2 = zcl_packet_setup_response(rsp,packet,2);
        }
        if ((uVar2 == 0) && (bVar1 != 0)) {
          return '\0';
        }
      }
    }
  }
_L0:
  eVar3 = zcl_packet_setup_default_response(rsp,packet,uVar2);
  return eVar3;
}

