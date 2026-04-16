/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_step_color_temperature_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
color_control_step_color_temperature_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  _Bool _Var2;
  byte bVar3;
  uint uVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint8_t *offset_00;
  undefined1 local_20 [4];
  ezb_zcl_color_control_step_color_temperature_cmd_payload_t req;
  uint16_t offset;
  
  req.options_mask = '\0';
  req.options_override = '\0';
  local_20[0] = '\0';
  local_20[1] = 0;
  local_20._2_2_ = 0;
  req.step_mode = '\0';
  req._1_1_ = 0;
  req.step_size = 0;
  req.color_temperature_min_mireds = 0;
  req.color_temperature_max_mireds = 0;
  if (packet == (zcl_packet_t *)0x0) {
    uVar4 = 0;
  }
  else if (rsp == (zcl_packet_t *)0x0) {
    uVar4 = 0;
  }
  else {
    offset_00 = &req.options_mask;
    af_read_le8(packet->payload,(uint16_t *)offset_00,local_20);
    af_read_le16(packet->payload,(uint16_t *)offset_00,(uint16_t *)(local_20 + 2));
    af_read_le16(packet->payload,(uint16_t *)offset_00,&req.color_temperature_min_mireds);
    af_read_le16(packet->payload,(uint16_t *)offset_00,(uint16_t *)&req);
    af_read_le16(packet->payload,(uint16_t *)offset_00,&req.step_size);
    uVar4 = zmsg_get_length(packet->payload);
    if (uVar4 < (ushort)req._10_2_) {
      uVar4 = 0x80;
    }
    else {
      af_read_le8(packet->payload,(uint16_t *)offset_00,(uint8_t *)&req.color_temperature_max_mireds
                 );
      af_read_le8(packet->payload,(uint16_t *)offset_00,
                  (uint8_t *)((int)&req.color_temperature_max_mireds + 1));
      _Var2 = color_control_check_options_is_exec
                        ((packet->header).dst_ep,(uint8_t)req.color_temperature_max_mireds,
                         req.color_temperature_max_mireds._1_1_);
      if (CONCAT31(extraout_var,_Var2) == 0) {
        uVar4 = 0;
      }
      else {
        eVar1 = color_control_change_color_mode(packet,'\x02');
        uVar4 = CONCAT31(extraout_var_00,eVar1);
        if (uVar4 == 0) {
          bVar3 = step_cvc_color_temperature
                            ((packet->header).dst_ep,
                             (ezb_zcl_color_control_step_color_temperature_cmd_payload_t *)local_20)
          ;
          uVar4 = (uint)bVar3;
        }
      }
    }
  }
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar4);
  return eVar1;
}

