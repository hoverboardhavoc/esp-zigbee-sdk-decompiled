/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> get_zcl_send_status_cb_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

code * get_zcl_send_status_cb_handle(void)

{
  code *pcVar1;
  
  pcVar1 = s_cmd_send_status_cb;
  if (s_cmd_send_status_cb != (code *)0x0) {
    pcVar1 = zcl_cmd_send_status_handler;
  }
  return pcVar1;
}

