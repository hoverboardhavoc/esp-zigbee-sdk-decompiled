/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_basic_value.o -> check_value_binary_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 check_value_binary_server(int param_1,byte *param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 0x55) {
    if (param_1 == 0x6f) {
      if (*param_2 < 0x10) {
        uVar1 = 0;
      }
      else {
        uVar1 = 0xffffffff;
      }
      goto _L0;
    }
    if (param_1 != 0x51) {
      uVar1 = 0;
      goto _L0;
    }
  }
  if (*param_2 < 2) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
_L0:
  zb_trace_msg_port_platform(0x100,1,"check_value_basic_binary ret %hd",0x10000,0,0x78,4,uVar1);
  return uVar1;
}

