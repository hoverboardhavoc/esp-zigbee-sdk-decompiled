/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_cmd.o -> zcl_touchlink_handler
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
    packet = (zcl_packet_t *)__assert_func(0,0,0);
  }
  if (((packet->header).fc & 8) == 0) {
    zVar1 = zcl_touchlink_srv_handler(packet);
    return zVar1;
  }
  zVar1 = zcl_touchlink_cli_handler(packet);
  return zVar1;
}

