/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_enhanced_step_hue_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t color_control_enhanced_step_hue_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  _Bool _Var1;
  ezb_zcl_status_t eVar2;
  byte bVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar4;
  uint8_t *offset_00;
  undefined1 auStack_1c [4];
  ezb_zcl_color_control_enhanced_step_hue_cmd_payload_t req;
  uint16_t offset;
  
  req.options_mask = '\0';
  req.options_override = '\0';
  auStack_1c[0] = '\0';
  auStack_1c[1] = 0;
  auStack_1c._2_2_ = 0;
  req.step_mode = '\0';
  req._1_1_ = 0;
  req.step_size = 0;
  if (packet == (zcl_packet_t *)0x0) {
    uVar4 = 0;
  }
  else if (rsp == (zcl_packet_t *)0x0) {
    uVar4 = 0;
  }
  else {
    offset_00 = &req.options_mask;
    af_read_le8(packet->payload,(uint16_t *)offset_00,auStack_1c);
    af_read_le16(packet->payload,(uint16_t *)offset_00,(uint16_t *)(auStack_1c + 2));
    af_read_le16(packet->payload,(uint16_t *)offset_00,(uint16_t *)&req);
    af_read_le8(packet->payload,(uint16_t *)offset_00,(uint8_t *)&req.step_size);
    af_read_le8(packet->payload,(uint16_t *)offset_00,(uint8_t *)((int)&req.step_size + 1));
    _Var1 = color_control_check_options_is_exec
                      ((packet->header).dst_ep,(uint8_t)req.step_size,req.step_size._1_1_);
    if (CONCAT31(extraout_var,_Var1) == 0) {
      uVar4 = 0;
    }
    else {
      eVar2 = color_control_change_color_mode(packet,'\x03');
      uVar4 = CONCAT31(extraout_var_00,eVar2);
      if (uVar4 == 0) {
        bVar3 = cvc_enhanced_step_hue
                          ((packet->header).dst_ep,
                           (ezb_zcl_color_control_enhanced_step_hue_cmd_payload_t *)auStack_1c);
        uVar4 = (uint)bVar3;
      }
    }
  }
  eVar2 = zcl_packet_setup_default_response(rsp,packet,uVar4);
  return eVar2;
}

