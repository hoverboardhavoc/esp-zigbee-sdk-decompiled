/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> touchlink_compat.o -> esp_zb_touchlink_action_check_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_touchlink_action_check_register(undefined4 param_1)

{
  s_touchlink_action_allowed_cb = param_1;
  ezb_touchlink_action_permission_handler_register(touchlink_action_permission_handler);
  esp_zigbee_err_to_esp();
  return;
}

