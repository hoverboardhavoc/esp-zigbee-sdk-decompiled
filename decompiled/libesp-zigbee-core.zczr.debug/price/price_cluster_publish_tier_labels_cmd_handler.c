/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> price.o -> price_cluster_publish_tier_labels_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
price_cluster_publish_tier_labels_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  byte bVar1;
  int iVar2;
  ezb_zcl_status_t eVar3;
  uint16_t uVar4;
  undefined2 extraout_var;
  uint uVar5;
  uint16_t uStack_46;
  undefined4 uStack_44;
  uint16_t offset;
  ezb_zcl_price_publish_tier_labels_message_t message;
  
  uStack_44 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.provider_id = 0;
  message.in.payload.issuer_event_id = 0;
  message.in.payload.issuer_tariff_id = 0;
  message.in.payload.command_index = '\0';
  message.in.payload.total_number_of_commands = '\0';
  message.in.payload.number_of_labels = '\0';
  message.in.payload._15_1_ = 0;
  message.in.payload.tier_labels = (ezb_zcl_price_tier_label_entry_t *)0x0;
  uStack_46 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/price.c",0x118,
                  "price_cluster_publish_tier_labels_cmd_handler","packet && rsp");
  }
  else {
    af_read_le32(packet->payload,&uStack_46,(uint32_t *)&message.in);
    af_read_le32(packet->payload,&uStack_46,&message.in.payload.provider_id);
    af_read_le32(packet->payload,&uStack_46,&message.in.payload.issuer_event_id);
    af_read_le8(packet->payload,&uStack_46,(uint8_t *)&message.in.payload.issuer_tariff_id);
    af_read_le8(packet->payload,&uStack_46,
                (uint8_t *)((int)&message.in.payload.issuer_tariff_id + 1));
    uVar4 = af_read_le8(packet->payload,&uStack_46,
                        (uint8_t *)((int)&message.in.payload.issuer_tariff_id + 2));
    if (CONCAT22(extraout_var,uVar4) != 1) {
      uVar5 = 0x80;
      goto _L0;
    }
    uVar5 = message.in.payload.issuer_tariff_id >> 0x10 & 0xff;
    if (uVar5 != 0) {
      message.in.payload._12_4_ = calloc(uVar5,0xe);
      if ((void *)message.in.payload._12_4_ == (void *)0x0) {
        uVar5 = 0x89;
        goto _L0;
      }
      for (uVar5 = 0; uVar5 < (message.in.payload.issuer_tariff_id >> 0x10 & 0xff);
          uVar5 = uVar5 + 1 & 0xff) {
        iVar2 = uVar5 * 0xe;
        af_read_le8(packet->payload,&uStack_46,(uint8_t *)(message.in.payload._12_4_ + iVar2));
        af_read_le8(packet->payload,&uStack_46,(uint8_t *)(message.in.payload._12_4_ + iVar2 + 1));
        bVar1 = *(byte *)(message.in.payload._12_4_ + iVar2 + 1);
        if (0xc < bVar1) {
          uVar5 = 0x87;
          goto _L0;
        }
        af_read_bytes(packet->payload,&uStack_46,(ushort)bVar1,
                      (uint8_t *)(message.in.payload._12_4_ + iVar2 + 2));
      }
    }
  }
  uVar5 = zmsg_get_length(packet->payload);
  if (uVar5 < uStack_46) {
    uVar5 = 0x80;
  }
  else {
    uVar5 = zcl_packet_to_message(&stack0xffffffbc,packet);
    if (uVar5 == 0) {
      message.in.payload.tier_labels =
           (ezb_zcl_price_tier_label_entry_t *)CONCAT31(message.in.payload.tier_labels._1_3_,0xfe);
      message._4_4_ = packet;
      zcl_core_action_schedule(0x4f,&stack0xffffffbc);
      if (((uint)message.in.payload.tier_labels & 0xff) != 0xfe) {
        uVar5 = (uint)message.in.payload.tier_labels & 0xff;
      }
    }
  }
_L0:
  if (message.in.payload._12_4_ != 0) {
    mm_free();
  }
  eVar3 = zcl_packet_setup_default_response(rsp,packet,uVar5);
  return eVar3;
}

