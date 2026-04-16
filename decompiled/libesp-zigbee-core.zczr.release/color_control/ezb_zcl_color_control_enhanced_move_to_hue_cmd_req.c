/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> color_control.o -> ezb_zcl_color_control_enhanced_move_to_hue_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_color_control_enhanced_move_to_hue_cmd_req
                    (ezb_zcl_color_control_enhanced_move_to_hue_cmd_t *cmd_req)

{
  int iVar1;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [4];
  zcl_packet_t packet;
  
  memset(auStack_38,0,0x28);
  if ((cmd_req == (ezb_zcl_color_control_enhanced_move_to_hue_cmd_t *)0x0) ||
     (iVar1 = zcl_packet_init(auStack_38,0), iVar1 != 0)) {
    iVar1 = -1;
  }
  else {
    memcpy(auStack_50,cmd_req,10);
    iVar1 = zcl_cmd_to_packet(auStack_38,0,0,(cmd_req->cmd_ctrl).dis_default_rsp,0,0x40,0x300);
    if ((((iVar1 == 0) &&
         (iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,(cmd_req->payload).enhanced_hue),
         iVar1 == 0)) &&
        (iVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,(cmd_req->payload).direction), iVar1 == 0))
       && (((iVar1 = zmsg_append_le16((zmsg_t *)packet._32_4_,(cmd_req->payload).transition_time),
            iVar1 == 0 &&
            (iVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,(cmd_req->payload).options_mask),
            iVar1 == 0)) &&
           (iVar1 = zmsg_append_u8((zmsg_t *)packet._32_4_,(cmd_req->payload).options_override),
           iVar1 == 0)))) {
      zcl_packet_send(auStack_38,&(cmd_req->cmd_ctrl).cnf_ctx);
      iVar1 = zcl_status_to_err();
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  zcl_packet_free(auStack_38);
  return iVar1;
}

