/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_srv_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_touchlink_srv_handler(zcl_packet_t *packet)

{
  zcl_status_t zVar1;
  uint in_a5;
  
  if (packet == (zcl_packet_t *)0x0) {
    packet = (zcl_packet_t *)
             __assert_func("//build/esp-zigbee/src/core/touchlink/touchlink_cmd.c",0x2f3,
                           "zcl_touchlink_srv_handler","packet");
  }
  else {
    in_a5 = (uint)(packet->header).cmd_id;
    if (in_a5 == 0x10) {
      zVar1 = zcl_touchlink_network_start_req_handler(packet);
      return zVar1;
    }
    if (0x10 < in_a5) {
      if (in_a5 == 0x14) {
        zVar1 = zcl_touchlink_network_join_end_device_req_handler(packet);
        return zVar1;
      }
      if (in_a5 == 0x16) {
        zVar1 = zcl_touchlink_network_update_req_handler(packet);
        return zVar1;
      }
      if (in_a5 == 0x12) {
        zVar1 = zcl_touchlink_network_join_router_req_handler(packet);
        return zVar1;
      }
      goto _L0;
    }
    if (in_a5 == 6) {
      zVar1 = zcl_touchlink_identify_req_handler(packet);
      return zVar1;
    }
    if (in_a5 < 7) {
      if (in_a5 == 0) {
        zVar1 = zcl_touchlink_scan_req_handler(packet);
        return zVar1;
      }
      if (in_a5 == 2) {
        zVar1 = zcl_touchlink_device_information_req_handler(packet);
        return zVar1;
      }
      goto _L0;
    }
  }
  if (in_a5 == 7) {
    zVar1 = zcl_touchlink_reset_to_factory_new_req_handler(packet);
    return zVar1;
  }
_L0:
  zVar1 = zcl_packet_send_default_response(0x81);
  return zVar1;
}

