/*
 * Last changed at upstream commit e28462af08968da8dbda59a317df742f0109ee5f
 * https://github.com/espressif/esp-zigbee-sdk/commit/e28462af08968da8dbda59a317df742f0109ee5f
 * Upstream date: 2024-04-12 14:44:19 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.3(042315bf)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zcl_privilege_command_handler_register
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

