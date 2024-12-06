/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> zb_zcl_privilege_command_handler_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_privilege_command_handler_register(int param_1)

{
  undefined4 uVar1;
  
  if ((s_privilege_command_handler == 0) ||
     (uVar1 = 0xffffffff, s_privilege_command_handler == param_1)) {
    uVar1 = 0;
    s_privilege_command_handler = param_1;
  }
  return uVar1;
}

