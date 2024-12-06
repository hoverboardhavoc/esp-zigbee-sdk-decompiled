/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_analog_output.o -> check_value_analog_output_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 check_value_analog_output_server(int param_1,byte *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0x51) {
    if (*param_2 < 2) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else if (param_1 == 0x6f) {
    if (*param_2 < 0x10) {
      uVar1 = 0;
    }
    else {
      uVar1 = 0xffffffff;
    }
  }
  else {
    uVar1 = 0;
  }
  if ((g_trace_level != '\0') && ((_g_trace_mask & 0x100) != 0)) {
    esp_zb_trace_msg_port(0x100,1,"check_value_analog_out ret %hd",0x10000,0x57,4,uVar1);
  }
  return uVar1;
}

