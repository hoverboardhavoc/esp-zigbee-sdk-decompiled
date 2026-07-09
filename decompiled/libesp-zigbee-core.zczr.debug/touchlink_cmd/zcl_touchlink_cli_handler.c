/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_cli_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_touchlink_cli_handler(int param_1,uint param_2)

{
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink_cmd.c",0x319,
                  "zcl_touchlink_cli_handler","packet");
  }
  else {
    param_2 = (uint)*(byte *)(param_1 + 0x20);
    if (param_2 == 0x11) {
      zcl_touchlink_network_start_rsp_handler();
      return;
    }
    if (0x11 < param_2) {
      if (param_2 == 0x13) {
        zcl_touchlink_network_join_router_rsp_handler();
        return;
      }
      if (param_2 == 0x15) {
        zcl_touchlink_network_join_end_device_rsp_handler();
        return;
      }
      goto _L0;
    }
  }
  if (param_2 == 1) {
    zcl_touchlink_scan_rsp_handler();
    return;
  }
  if (param_2 == 3) {
    zcl_touchlink_device_information_rsp_handler();
    return;
  }
_L0:
  zcl_packet_send_default_response(0x81);
  return;
}

