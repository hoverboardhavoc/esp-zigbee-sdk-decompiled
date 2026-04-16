/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> level_cluster_move_to_level_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t level_cluster_move_to_level_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t ep_id;
  uint8_t cmd_id;
  ezb_zcl_status_t eVar1;
  _Bool _Var2;
  uint uVar3;
  undefined3 extraout_var;
  uint16_t *unaff_s2;
  undefined1 auStack_28 [4];
  ezb_zcl_level_move_to_level_cmd_payload_t payload;
  uint16_t offset;
  
  ep_id = (packet->header).dst_ep;
  cmd_id = (packet->header).cmd_id;
  payload.transition_time = 0;
  auStack_28[0] = '\0';
  auStack_28[1] = 0;
  auStack_28._2_2_ = 0;
  payload.level = '\0';
  payload._1_1_ = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/level.c",0x159,
                  "level_cluster_move_to_level_cmd_handler","packet && rsp");
  }
  else {
    unaff_s2 = &payload.transition_time;
    af_read_le8(packet->payload,unaff_s2,auStack_28);
    af_read_le16(packet->payload,unaff_s2,(uint16_t *)(auStack_28 + 2));
    uVar3 = zmsg_get_length(packet->payload);
    if (uVar3 < payload.transition_time) {
      eVar1 = 0x80;
      goto _L0;
    }
  }
  af_read_le8(packet->payload,unaff_s2,&payload.level);
  af_read_le8(packet->payload,unaff_s2,&payload.field_0x1);
  _Var2 = level_check_options_is_exec(ep_id,cmd_id,payload.level,payload._1_1_);
  if (CONCAT31(extraout_var,_Var2) == 0) {
    eVar1 = '\0';
  }
  else {
    eVar1 = move_to_cvc_level(ep_id,(packet->header).cmd_id != '\0',
                              (ezb_zcl_level_move_to_level_cmd_payload_t *)auStack_28);
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,eVar1);
  return eVar1;
}

