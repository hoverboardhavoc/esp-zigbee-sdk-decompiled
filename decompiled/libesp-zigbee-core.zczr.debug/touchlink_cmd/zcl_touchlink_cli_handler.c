/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
             __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink_cmd.c",
                           0x319,"zcl_touchlink_cli_handler","packet");
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

