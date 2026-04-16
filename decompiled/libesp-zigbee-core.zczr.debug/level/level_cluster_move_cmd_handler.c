/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> level_cluster_move_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t level_cluster_move_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t ep_id;
  uint8_t cmd_id;
  ezb_zcl_status_t eVar1;
  _Bool _Var2;
  uint uVar3;
  undefined3 extraout_var;
  uint8_t *unaff_s2;
  ezb_zcl_level_move_cmd_payload_t eStack_28;
  ezb_zcl_level_move_cmd_payload_t payload;
  uint16_t offset;
  
  ep_id = (packet->header).dst_ep;
  cmd_id = (packet->header).cmd_id;
  payload.options_mask = '\0';
  payload.options_override = '\0';
  eStack_28.move_mode = '\0';
  eStack_28.rate = '\0';
  eStack_28.options_mask = '\0';
  eStack_28.options_override = '\0';
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/level.c",0x199,
                  "level_cluster_move_cmd_handler","packet && rsp");
  }
  else {
    unaff_s2 = &payload.options_mask;
    af_read_le8(packet->payload,(uint16_t *)unaff_s2,&eStack_28.move_mode);
    af_read_le8(packet->payload,(uint16_t *)unaff_s2,&eStack_28.rate);
    uVar3 = zmsg_get_length(packet->payload);
    if (uVar3 < (ushort)payload._2_2_) {
      eVar1 = 0x80;
      goto _L0;
    }
  }
  af_read_le8(packet->payload,(uint16_t *)unaff_s2,&eStack_28.options_mask);
  af_read_le8(packet->payload,(uint16_t *)unaff_s2,&eStack_28.options_override);
  _Var2 = level_check_options_is_exec
                    (ep_id,cmd_id,eStack_28.options_mask,eStack_28.options_override);
  if (CONCAT31(extraout_var,_Var2) == 0) {
    eVar1 = '\0';
  }
  else {
    eVar1 = move_cvc_handler(ep_id,(packet->header).cmd_id != '\x01',&eStack_28);
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,eVar1);
  return eVar1;
}

