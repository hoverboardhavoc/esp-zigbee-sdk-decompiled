/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> price.o -> price_cluster_cli_cmd_proc_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t price_cluster_cli_cmd_proc_handler(void *arg)

{
  byte bVar1;
  uint16_t uVar2;
  uint16_t uVar3;
  int iVar4;
  undefined2 extraout_var;
  ezb_err_t eVar5;
  int iVar6;
  uint32_t val;
  undefined2 extraout_var_00;
  uint uVar7;
  short sVar8;
  byte bStack_ad;
  uint16_t uStack_ac;
  undefined2 uStack_aa;
  uint8_t map_value;
  uint16_t offset;
  uint16_t temp_u16;
  uint32_t temp_u32;
  zcl_packet_t rsp;
  ezb_zcl_price_publish_price_message_t message;
  
  memset(&temp_u32,0,0x28);
  iVar4 = 1;
  if (arg == (void *)0x0) goto _L0;
  iVar4 = 1;
  if (((*(byte *)((int)arg + 0x1a) & 8) == 0) ||
     (iVar4 = zcl_packet_init(&temp_u32,*(byte *)((int)arg + 0x1a) >> 2 & 1), iVar4 != 0)) goto _L0;
  if (*(char *)((int)arg + 0x20) == '\0') {
    memset(&rsp.payload,0,0x4c);
    uStack_ac = 0;
    bStack_ad = 0;
    _offset = (ezb_zcl_cmd_hdr_t *)0x0;
    uStack_aa = 0;
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,(uint32_t *)&offset);
    message.in.header = _offset;
    uVar2 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,(uint8_t *)&message.in.payload);
    uVar3 = uStack_ac;
    if (CONCAT22(extraout_var,uVar2) == 0) {
_L0:
      uVar7 = 0x80;
      goto _L0;
    }
    uVar7 = 0x87;
    if (0xc < (byte)message.in.payload.provider_id) goto _L0;
    iVar6 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),uStack_ac,
                            (byte)message.in.payload.provider_id,
                            (undefined1 *)((int)&message.in.payload.provider_id + 1));
    if ((iVar6 == 0) && ((byte)message.in.payload.provider_id != 0)) {
      uStack_ac = 0xffff;
    }
    else {
      uStack_ac = uVar3 + (short)iVar6;
    }
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,(uint32_t *)&offset);
    message.in.payload.rate_label[9] = (uint8_t)_offset;
    message.in.payload.rate_label[10] = (uint8_t)((uint)_offset >> 8);
    message.in.payload.rate_label[0xb] = (uint8_t)((uint)_offset >> 0x10);
    message.in.payload.rate_label[0xc] = (uint8_t)((uint)_offset >> 0x18);
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,(uint32_t *)&offset);
    message.in.payload.issuer_event_id._0_1_ = (char)_offset;
    message.in.payload.issuer_event_id._1_1_ = (char)((uint)_offset >> 8);
    message.in.payload.issuer_event_id._2_1_ = (char)((uint)_offset >> 0x10);
    message.in.payload.issuer_event_id._3_1_ = (byte)((uint)_offset >> 0x18);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,(uint8_t *)&message.in.payload.current_time
               );
    uVar3 = uStack_ac;
    iVar6 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),uStack_ac,2,&stack0xffffff56);
    if (iVar6 == 0) {
      uStack_ac = 0xffff;
    }
    else {
      uStack_ac = uVar3 + (short)iVar6;
    }
    message.in.payload.current_time._1_2_ = uStack_aa;
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,&bStack_ad);
    message.in.payload.current_time._3_1_ = bStack_ad >> 4 | bStack_ad << 4;
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,&bStack_ad);
    message.in.payload.unit_of_measure = bStack_ad >> 4 | bStack_ad << 4;
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,(uint32_t *)&offset);
    uVar3 = uStack_ac;
    message.in.payload.currency = (uint16_t)_offset;
    message.in.payload._28_2_ = (undefined2)((uint)_offset >> 0x10);
    iVar6 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),uStack_ac,2,&stack0xffffff56);
    if (iVar6 == 0) {
      uStack_ac = 0xffff;
    }
    else {
      uStack_ac = uVar3 + (short)iVar6;
    }
    message.in.payload.start_time._0_2_ = uStack_aa;
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,(uint32_t *)&offset);
    message.in.payload._32_4_ = _offset;
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,(uint8_t *)&message.in.payload.price);
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,(uint32_t *)&offset);
    message.in.payload.price._1_1_ = SUB41(_offset,0);
    message.in.payload.price._2_1_ = (undefined1)((uint)_offset >> 8);
    message.in.payload.price._3_1_ = (undefined1)((uint)_offset >> 0x10);
    message.in.payload.price_ratio = (uint8_t)((uint)_offset >> 0x18);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,
                (uint8_t *)&message.in.payload.generation_price);
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,(uint32_t *)&offset);
    message.in.payload.generation_price._1_2_ = SUB42(_offset,0);
    message.in.payload._44_2_ = (undefined2)((uint)_offset >> 0x10);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,
                (uint8_t *)&message.in.payload.alternate_cost_delivered);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,
                (uint8_t *)((int)&message.in.payload.alternate_cost_delivered + 1));
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,
                (uint8_t *)((int)&message.in.payload.alternate_cost_delivered + 2));
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,
                (uint8_t *)((int)&message.in.payload.alternate_cost_delivered + 3));
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,&message.in.payload.alternate_cost_unit);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,
                &message.in.payload.alternate_cost_trailing_digit);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,
                &message.in.payload.number_of_block_thresholds);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,&message.in.payload.price_control);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&uStack_ac,
                &message.in.payload.number_of_generation_tiers);
    uVar7 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
    if (uVar7 < uStack_ac) goto _L0;
    uVar7 = zcl_packet_to_message(&rsp.payload,arg);
    if (uVar7 != 0) goto _L0;
    message.in.payload.extended_number_of_price_tiers = 0xfe;
    message._4_4_ = arg;
    zcl_core_action_schedule(0x4e,&rsp.payload,0);
    uVar7 = (uint)message.in.payload.extended_number_of_price_tiers;
    if (uVar7 == 0xfe) {
      uVar7 = 1;
      goto _L0;
    }
    if ((message.in.payload.alternate_cost_delivered._3_1_ & 1) == 0) goto _L0;
    eVar5 = zmsg_append_le32((zmsg_t *)rsp._32_4_,(uint32_t)message.in.header);
    if ((eVar5 != 0) ||
       (eVar5 = zmsg_append_le32((zmsg_t *)rsp._32_4_,
                                 message.in.payload._16_4_ << 0x18 |
                                 (uint)message.in.payload.rate_label._8_4_ >> 8), eVar5 != 0)) {
_L0:
      uVar7 = 0x89;
      goto _L0;
    }
    val = zcl_time_get_utc_time(*(undefined1 *)((int)arg + 0x15));
    if (val == 0xffffffff) {
      val = (uint)message.in.payload.issuer_event_id._3_1_ << 0x18 |
            (uint)message.in.payload._16_4_ >> 8;
    }
    eVar5 = zmsg_append_le32((zmsg_t *)rsp._32_4_,val);
    if ((eVar5 != 0) ||
       (eVar5 = zmsg_append_u8((zmsg_t *)rsp._32_4_,
                               message.in.payload.alternate_cost_delivered._3_1_), eVar5 != 0))
    goto _L0;
    uVar7 = zcl_packet_setup_response(&temp_u32,arg,2);
    if (uVar7 != 0) goto _L0;
  }
  else {
    if (*(char *)((int)arg + 0x20) != '\b') {
      uVar7 = 0x81;
      goto _L0;
    }
    memset(&rsp.payload,0,0x24);
    _offset = (ezb_zcl_cmd_hdr_t *)((uint)_offset & 0xffff0000);
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&offset,(uint32_t *)&message.in);
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&offset,&message.in.payload.provider_id);
    af_read_le32(*(zmsg_t **)((int)arg + 0x24),&offset,(uint32_t *)message.in.payload.rate_label);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset,message.in.payload.rate_label + 4);
    af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset,message.in.payload.rate_label + 5);
    uVar3 = af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset,message.in.payload.rate_label + 6);
    if (CONCAT22(extraout_var_00,uVar3) == 1) {
      if (message.in.payload.rate_label[6] == 0) {
_L0:
        uVar7 = zmsg_get_length(*(undefined4 *)((int)arg + 0x24));
        if (uVar7 < ((uint)_offset & 0xffff)) goto _L0;
        uVar7 = zcl_packet_to_message(&rsp.payload,arg);
        if (uVar7 == 0) {
          message.in.payload.rate_label[0xc] = 0xfe;
          message._4_4_ = arg;
          zcl_core_action_schedule(0x4f,&rsp.payload);
          if ((message.in.payload._16_4_ & 0xff) != 0xfe) {
            uVar7 = message.in.payload._16_4_ & 0xff;
          }
        }
      }
      else {
        message.in.payload.rate_label._8_4_ = calloc((uint)message.in.payload.rate_label[6],0xe);
        uVar7 = 0x89;
        if ((void *)message.in.payload.rate_label._8_4_ != (void *)0x0) {
          for (uVar7 = 0; uVar7 < message.in.payload.rate_label[6]; uVar7 = uVar7 + 1 & 0xff) {
            iVar6 = uVar7 * 0xe;
            af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset,
                        (uint8_t *)(message.in.payload.rate_label._8_4_ + iVar6));
            af_read_le8(*(zmsg_t **)((int)arg + 0x24),&offset,
                        (uint8_t *)(message.in.payload.rate_label._8_4_ + iVar6 + 1));
            bVar1 = *(byte *)(message.in.payload.rate_label._8_4_ + iVar6 + 1);
            if (0xc < bVar1) {
              uVar7 = 0x87;
              goto _L0;
            }
            uVar3 = offset;
            iVar6 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x24),(uint)_offset & 0xffff,bVar1,
                                    message.in.payload.rate_label._8_4_ + iVar6 + 2);
            if ((iVar6 != 0) || (sVar8 = -1, bVar1 == 0)) {
              sVar8 = uVar3 + (short)iVar6;
            }
            _offset = (ezb_zcl_cmd_hdr_t *)CONCAT22(temp_u16,sVar8);
          }
          goto _L0;
        }
      }
    }
    else {
_L0:
      uVar7 = 0x80;
    }
_L0:
    if (message.in.payload.rate_label._8_4_ != 0) {
      mm_free();
    }
_L0:
    iVar6 = zcl_packet_setup_default_response(&temp_u32,arg,uVar7);
    if (iVar6 != 0) {
      zcl_packet_free(&temp_u32);
      iVar4 = iVar6;
      goto _L0;
    }
  }
  zcl_packet_send(&temp_u32,0);
_L0:
  return (ezb_zcl_status_t)iVar4;
}

