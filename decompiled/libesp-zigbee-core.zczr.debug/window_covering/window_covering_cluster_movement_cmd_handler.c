/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> window_covering.o -> window_covering_cluster_movement_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: message */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
window_covering_cluster_movement_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  zcl_packet_t *pzVar2;
  uint uVar3;
  undefined3 extraout_var;
  int iVar4;
  uint in_a5;
  uint16_t attr_id;
  uint16_t uStack_26;
  undefined4 uStack_24;
  uint16_t offset;
  ezb_zcl_window_covering_movement_message_t message;
  
  uStack_24 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload = (ezb_zcl_window_covering_cmd_payload_t)0x0;
  message.in._6_2_ = 0;
  uStack_26 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    pzVar2 = (zcl_packet_t *)
             __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/window_covering.c"
                           ,0xab,"window_covering_cluster_movement_cmd_handler","packet && rsp");
_L0:
    if (in_a5 < 3) {
      attr_id = 0;
    }
    else {
      if (in_a5 != 4) {
        iVar4 = 0x81;
        goto _L0;
      }
      af_read_le16(pzVar2->payload,&uStack_26,(uint16_t *)&message.in);
      attr_id = 3;
    }
  }
  else {
    in_a5 = (uint)(packet->header).cmd_id;
    message._4_4_ = packet;
    if (in_a5 == 5) {
      af_read_le8(packet->payload,&uStack_26,(uint8_t *)&message.in);
      attr_id = 8;
    }
    else {
      pzVar2 = packet;
      if (in_a5 < 6) goto _L0;
      if (in_a5 == 7) {
        af_read_le16(packet->payload,&uStack_26,(uint16_t *)&message.in);
        attr_id = 4;
      }
      else {
        if (in_a5 != 8) {
          iVar4 = 0x81;
          goto _L0;
        }
        af_read_le8(packet->payload,&uStack_26,(uint8_t *)&message.in);
        attr_id = 9;
      }
    }
  }
  uVar3 = zmsg_get_length(packet->payload);
  if (uVar3 < uStack_26) {
    iVar4 = 0x80;
  }
  else {
    if ((((ushort)(attr_id - 3) < 2) || (attr_id == 8)) || (attr_id == 9)) {
      eVar1 = window_covering_srv_set_attr_value
                        ((packet->header).dst_ep,attr_id,(uint8_t *)&message.in);
      iVar4 = CONCAT31(extraout_var,eVar1);
      if (iVar4 != 0) goto _L0;
    }
    iVar4 = zcl_packet_to_message(&stack0xffffffdc,packet);
    if (iVar4 == 0) {
      message.in.payload.lift_percentage = 0xfe;
      zcl_core_action_schedule(0x1a,&stack0xffffffdc);
      if ((message.in._4_4_ & 0xff) != 0xfe) {
        if ((message.in._4_4_ & 0xff) == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = 1;
        }
      }
    }
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,iVar4);
  return eVar1;
}

