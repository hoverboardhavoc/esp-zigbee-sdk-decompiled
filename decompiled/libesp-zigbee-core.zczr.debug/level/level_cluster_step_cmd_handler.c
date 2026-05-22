/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> level_cluster_step_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t level_cluster_step_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t ep_id;
  uint8_t cmd_id;
  ezb_zcl_status_t eVar1;
  _Bool _Var2;
  uint uVar3;
  undefined3 extraout_var;
  uint16_t *unaff_s2;
  undefined1 auStack_28 [4];
  ezb_zcl_level_step_cmd_payload_t payload;
  uint16_t offset;
  
  ep_id = (packet->header).dst_ep;
  cmd_id = (packet->header).cmd_id;
  payload.transition_time = 0;
  auStack_28[0] = '\0';
  auStack_28[1] = '\0';
  auStack_28._2_2_ = 0;
  payload.step_mode = '\0';
  payload.step_size = '\0';
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/level.c",0x1db,
                  "level_cluster_step_cmd_handler","packet && rsp");
  }
  else {
    unaff_s2 = &payload.transition_time;
    af_read_le8(packet->payload,unaff_s2,auStack_28);
    af_read_le8(packet->payload,unaff_s2,auStack_28 + 1);
    af_read_le16(packet->payload,unaff_s2,(uint16_t *)(auStack_28 + 2));
    uVar3 = zmsg_get_length(packet->payload);
    if (uVar3 < payload.transition_time) {
      eVar1 = 0x80;
      goto _L0;
    }
  }
  af_read_le8(packet->payload,unaff_s2,&payload.step_mode);
  af_read_le8(packet->payload,unaff_s2,&payload.step_size);
  _Var2 = level_check_options_is_exec(ep_id,cmd_id,payload.step_mode,payload.step_size);
  if (CONCAT31(extraout_var,_Var2) == 0) {
    eVar1 = '\0';
  }
  else {
    eVar1 = cvc_step_handler(ep_id,(packet->header).cmd_id != '\x02',
                             (ezb_zcl_level_step_cmd_payload_t *)auStack_28);
  }
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,eVar1);
  return eVar1;
}

