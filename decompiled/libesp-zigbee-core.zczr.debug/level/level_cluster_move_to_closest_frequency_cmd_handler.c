/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> level_cluster_move_to_closest_frequency_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
level_cluster_move_to_closest_frequency_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  ezb_zcl_status_t eVar1;
  uint uVar2;
  undefined4 uVar3;
  uint16_t uStack_14;
  uint16_t uStack_12;
  ezb_zcl_level_move_to_closest_frequency_cmd_payload_t payload;
  uint16_t offset;
  
  uStack_12 = 0;
  uStack_14 = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/level.c",0x213,
                  "level_cluster_move_to_closest_frequency_cmd_handler","packet && rsp");
  }
  else {
    af_read_le16(packet->payload,&uStack_12,&uStack_14);
    uVar2 = zmsg_get_length(packet->payload);
    if (uStack_12 <= uVar2) {
      uVar3 = 0x81;
      goto _L0;
    }
  }
  uVar3 = 0x80;
_L0:
  eVar1 = zcl_packet_setup_default_response(rsp,packet,uVar3);
  return eVar1;
}

