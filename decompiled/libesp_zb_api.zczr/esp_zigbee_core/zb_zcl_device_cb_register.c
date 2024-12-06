/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> zb_zcl_device_cb_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_device_cb_register(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar1 = s_device_cb_list;
  piVar2 = s_device_cb_list;
  while( true ) {
    if (piVar2 + -2 == (int *)0xfffffff8) {
      piVar2 = (int *)malloc(0xc);
      uVar3 = 0x101;
      if (piVar2 != (int *)0x0) {
        piVar2[2] = (int)piVar1;
        *piVar2 = param_1;
        piVar2[1] = param_2;
        s_device_cb_list = piVar2 + 2;
        uVar3 = 0;
      }
      return uVar3;
    }
    if ((piVar2[-2] == param_1) && (piVar2[-1] != 0)) break;
    piVar2 = (int *)*piVar2;
  }
  return 0x102;
}

