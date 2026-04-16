/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> color_control.o -> color_control_stop_move_step_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t color_control_stop_move_step_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  _Bool _Var1;
  ezb_zcl_status_t eVar2;
  undefined3 extraout_var;
  uint8_t auStack_14 [2];
  uint16_t uStack_12;
  ezb_zcl_color_control_stop_move_step_cmd_payload_t req;
  uint16_t offset;
  
  uStack_12 = 0;
  auStack_14[0] = '\0';
  auStack_14[1] = '\0';
  if ((packet != (zcl_packet_t *)0x0) && (rsp != (zcl_packet_t *)0x0)) {
    af_read_le8(packet->payload,&uStack_12,auStack_14);
    af_read_le8(packet->payload,&uStack_12,auStack_14 + 1);
    _Var1 = color_control_check_options_is_exec((packet->header).dst_ep,auStack_14[0],auStack_14[1])
    ;
    if (CONCAT31(extraout_var,_Var1) != 0) {
      stop_cvc_color((packet->header).dst_ep,0xff);
    }
  }
  eVar2 = zcl_packet_setup_default_response(rsp,packet,0);
  return eVar2;
}

