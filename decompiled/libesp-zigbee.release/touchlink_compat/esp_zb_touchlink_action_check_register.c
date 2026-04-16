/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> touchlink_compat.o -> esp_zb_touchlink_action_check_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_touchlink_action_check_register
                    (esp_zb_touchlink_action_allowed_callback_t callback)

{
  esp_err_t eVar1;
  
  s_touchlink_action_allowed_cb = callback;
  ezb_touchlink_action_permission_handler_register(touchlink_action_permission_handler);
  eVar1 = esp_zigbee_err_to_esp();
  return eVar1;
}

