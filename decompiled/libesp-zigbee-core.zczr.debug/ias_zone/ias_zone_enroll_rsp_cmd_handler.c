/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_enroll_rsp_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t ias_zone_enroll_rsp_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  _Bool _Var1;
  ezb_zcl_status_t eVar2;
  uint uVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  zcl_attr_desc_t *pzVar4;
  undefined4 uStack_28;
  ezb_zcl_ias_zone_enroll_rsp_message_t message;
  uint16_t offset;
  
  message._18_2_ = 0;
  uStack_28 = 0;
  message.info.status = '\0';
  message.info.dst_ep = '\0';
  message.info.cluster_id = 0;
  message.info.cluster_role = '\0';
  message.info._5_1_ = 0;
  message._6_2_ = 0;
  message.in.header = (ezb_zcl_cmd_hdr_t *)0x0;
  message.in.payload.enroll_rsp_code = '\0';
  message.in.payload.zone_id = '\0';
  message.in._6_2_ = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_zone.c",0x99,
                  "ias_zone_enroll_rsp_cmd_handler","packet && rsp");
_L0:
    _Var1 = validate_cie_authorization
                      ((packet->header).dst_ep,(packet->header).src_addr.u.short_addr);
    if (CONCAT31(extraout_var_00,_Var1) == 0) {
      uVar3 = 0x7e;
      goto _L0;
    }
    pzVar4 = ias_zone_srv_get_attr_desc((packet->header).dst_ep,0x11);
    *(undefined1 *)pzVar4->data_p = message.in.header._1_1_;
    pzVar4 = ias_zone_srv_get_attr_desc((packet->header).dst_ep,0);
    *(undefined1 *)pzVar4->data_p = 1;
  }
  else {
    af_read_le8(packet->payload,(uint16_t *)&message.field_0x12,(uint8_t *)&message.in);
    af_read_le8(packet->payload,(uint16_t *)&message.field_0x12,
                (uint8_t *)((int)&message.in.header + 1));
    uVar3 = zmsg_get_length(packet->payload);
    if (uVar3 < (ushort)message._18_2_) {
      uVar3 = 0x80;
      goto _L0;
    }
    if (((uint)message.in.header & 0xff) == 0) {
      _Var1 = validate_cie_establishment((packet->header).dst_ep);
      if (CONCAT31(extraout_var,_Var1) == 0) {
        uVar3 = 0x7e;
        goto _L0;
      }
      goto _L0;
    }
  }
  uVar3 = zcl_packet_to_message(&uStack_28,packet);
  if (uVar3 == 0) {
    message.in.payload.enroll_rsp_code = 0xfe;
    message._4_4_ = packet;
    zcl_core_action_schedule(0x31,&uStack_28);
    if ((message.in._4_4_ & 0xff) != 0xfe) {
      uVar3 = message.in._4_4_ & 0xff;
    }
  }
_L0:
  eVar2 = zcl_packet_setup_default_response(rsp,packet,uVar3);
  return eVar2;
}

