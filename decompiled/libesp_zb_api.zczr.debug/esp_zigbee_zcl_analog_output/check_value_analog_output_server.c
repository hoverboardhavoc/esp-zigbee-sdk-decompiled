/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_analog_output.o -> check_value_analog_output_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

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
  zb_trace_msg_port_platform(0x100,1,"check_value_analog_out ret %hd",0x10000,0x90,0x57,4,uVar1);
  return uVar1;
}

