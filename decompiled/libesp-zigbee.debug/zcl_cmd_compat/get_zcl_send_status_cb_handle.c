/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> get_zcl_send_status_cb_handle
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_af_user_cnf_callback_t get_zcl_send_status_cb_handle(void)

{
  ezb_af_user_cnf_callback_t p_Var1;
  
  p_Var1 = (ezb_af_user_cnf_callback_t)s_cmd_send_status_cb;
  if (s_cmd_send_status_cb != (esp_zb_zcl_command_send_status_callback_t)0x0) {
    p_Var1 = zcl_cmd_send_status_handler;
  }
  return p_Var1;
}

