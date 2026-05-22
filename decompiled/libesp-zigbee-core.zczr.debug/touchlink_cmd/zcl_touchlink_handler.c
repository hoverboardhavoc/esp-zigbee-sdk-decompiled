/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_status_t zcl_touchlink_handler(zcl_packet_t *packet)

{
  zcl_status_t zVar1;
  
  if (packet == (zcl_packet_t *)0x0) {
    packet = (zcl_packet_t *)
             __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink_cmd.c",
                           0x336,"zcl_touchlink_handler","packet");
  }
  else if (((packet->header).fc & 8) == 0) {
    zVar1 = zcl_touchlink_srv_handler(packet);
    return zVar1;
  }
  zVar1 = zcl_touchlink_cli_handler(packet);
  return zVar1;
}

