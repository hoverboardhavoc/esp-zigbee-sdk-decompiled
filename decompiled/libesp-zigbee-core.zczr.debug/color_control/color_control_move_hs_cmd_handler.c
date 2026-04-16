/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_move_hs_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t color_control_move_hs_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  _Bool _Var2;
  byte bVar3;
  uint uVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint8_t *offset_00;
  ezb_zcl_color_control_move_hue_cmd_payload_t eStack_18;
  ezb_zcl_color_control_move_hs_cmd_payload_t req;
  uint16_t offset;
  
  req.options_mask = '\0';
  req.options_override = '\0';
  eStack_18.move_mode = '\0';
  eStack_18.rate = '\0';
  eStack_18.options_mask = '\0';
  eStack_18.options_override = '\0';
  if (packet == (zcl_packet_t *)0x0) {
    uVar4 = 0;
  }
  else if (rsp == (zcl_packet_t *)0x0) {
    uVar4 = 0;
  }
  else {
    offset_00 = &req.options_mask;
    af_read_le8(packet->payload,(uint16_t *)offset_00,&eStack_18.move_mode);
    af_read_le8(packet->payload,(uint16_t *)offset_00,&eStack_18.rate);
    uVar4 = zmsg_get_length(packet->payload);
    if (uVar4 < (ushort)req._2_2_) {
      uVar4 = 0x80;
    }
    else {
      af_read_le8(packet->payload,(uint16_t *)offset_00,&eStack_18.options_mask);
      af_read_le8(packet->payload,(uint16_t *)offset_00,&eStack_18.options_override);
      _Var2 = color_control_check_options_is_exec
                        ((packet->header).dst_ep,eStack_18.options_mask,eStack_18.options_override);
      if (CONCAT31(extraout_var,_Var2) == 0) {
        uVar4 = 0;
      }
      else {
        eVar1 = color_control_change_color_mode(packet,'\0');
        uVar4 = CONCAT31(extraout_var_00,eVar1);
        if (uVar4 == 0) {
          if ((packet->header).cmd_id == '\x01') {
            bVar3 = cvc_move_hue((packet->header).dst_ep,&eStack_18);
            uVar4 = (uint)bVar3;
          }
          else {
            bVar3 = cvc_move_sat((packet->header).dst_ep,&eStack_18);
            uVar4 = (uint)bVar3;
          }
        }
      }
    }
  }
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar4);
  return eVar1;
}

