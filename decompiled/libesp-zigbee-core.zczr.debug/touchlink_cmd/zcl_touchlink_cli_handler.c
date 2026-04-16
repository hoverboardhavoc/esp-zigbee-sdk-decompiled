/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_cli_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_touchlink_cli_handler(zcl_packet_t *packet)

{
  zcl_status_t zVar1;
  uint in_a5;
  
  if (packet == (zcl_packet_t *)0x0) {
    packet = (zcl_packet_t *)
             __assert_func("//build/esp-zigbee/src/core/touchlink/touchlink_cmd.c",0x319,
                           "zcl_touchlink_cli_handler","packet");
  }
  else {
    in_a5 = (uint)(packet->header).cmd_id;
    if (in_a5 == 0x11) {
      zVar1 = zcl_touchlink_network_start_rsp_handler(packet);
      return zVar1;
    }
    if (0x11 < in_a5) {
      if (in_a5 == 0x13) {
        zVar1 = zcl_touchlink_network_join_router_rsp_handler(packet);
        return zVar1;
      }
      if (in_a5 == 0x15) {
        zVar1 = zcl_touchlink_network_join_end_device_rsp_handler(packet);
        return zVar1;
      }
      goto _L0;
    }
  }
  if (in_a5 == 1) {
    zVar1 = zcl_touchlink_scan_rsp_handler(packet);
    return zVar1;
  }
  if (in_a5 == 3) {
    zVar1 = zcl_touchlink_device_information_rsp_handler(packet);
    return zVar1;
  }
_L0:
  zVar1 = zcl_packet_send_default_response(0x81);
  return zVar1;
}

