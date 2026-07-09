/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_cmd.o -> zcl_touchlink_srv_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_touchlink_srv_handler(int param_1,uint param_2)

{
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/touchlink/touchlink_cmd.c",0x2f3,
                  "zcl_touchlink_srv_handler","packet");
  }
  else {
    param_2 = (uint)*(byte *)(param_1 + 0x20);
    if (param_2 == 0x10) {
      zcl_touchlink_network_start_req_handler();
      return;
    }
    if (0x10 < param_2) {
      if (param_2 == 0x14) {
        zcl_touchlink_network_join_end_device_req_handler();
        return;
      }
      if (param_2 == 0x16) {
        zcl_touchlink_network_update_req_handler();
        return;
      }
      if (param_2 == 0x12) {
        zcl_touchlink_network_join_router_req_handler();
        return;
      }
      goto _L0;
    }
    if (param_2 == 6) {
      zcl_touchlink_identify_req_handler();
      return;
    }
    if (param_2 < 7) {
      if (param_2 == 0) {
        zcl_touchlink_scan_req_handler();
        return;
      }
      if (param_2 == 2) {
        zcl_touchlink_device_information_req_handler();
        return;
      }
      goto _L0;
    }
  }
  if (param_2 == 7) {
    zcl_touchlink_reset_to_factory_new_req_handler();
    return;
  }
_L0:
  zcl_packet_send_default_response(0x81);
  return;
}

