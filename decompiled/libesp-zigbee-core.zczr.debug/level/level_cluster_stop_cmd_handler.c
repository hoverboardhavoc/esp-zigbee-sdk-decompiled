/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> level_cluster_stop_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t level_cluster_stop_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  uint8_t ep_id;
  uint8_t cmd_id;
  _Bool _Var1;
  ezb_zcl_status_t eVar2;
  undefined3 extraout_var;
  undefined4 uStack_28;
  ezb_zcl_level_stop_cmd_payload_t payload;
  uint16_t offset;
  
  ep_id = (packet->header).dst_ep;
  cmd_id = (packet->header).cmd_id;
  payload.options_mask = '\0';
  payload.options_override = '\0';
  uStack_28 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/level.c",0x1ff,
                  "level_cluster_stop_cmd_handler","packet && rsp");
  }
  else {
    af_read_le8(packet->payload,(uint16_t *)&payload.options_mask,(uint8_t *)((int)&uStack_28 + 2));
    af_read_le8(packet->payload,(uint16_t *)&payload.options_mask,(uint8_t *)((int)&uStack_28 + 3));
    _Var1 = level_check_options_is_exec(ep_id,cmd_id,uStack_28._2_1_,uStack_28._3_1_);
    if (CONCAT31(extraout_var,_Var1) == 0) {
      eVar2 = '\0';
      goto _L0;
    }
  }
  eVar2 = stop_cvc_handler(ep_id);
_L0:
  eVar2 = zcl_packet_setup_default_response(rsp,packet,eVar2);
  return eVar2;
}

