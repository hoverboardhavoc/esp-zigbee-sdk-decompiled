/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_core.o -> zb_zcl_device_cb_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_zcl_device_cb_register(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  
  piVar2 = s_device_cb_list;
  while( true ) {
    if (piVar2 + -2 == (int *)0xfffffff8) {
      piVar2 = (int *)malloc(0xc);
      if (piVar2 == (int *)0x0) {
        uVar1 = 0x101;
      }
      else {
        *piVar2 = param_1;
        piVar2[1] = param_2;
        piVar2[2] = (int)s_device_cb_list;
        uVar1 = 0;
        s_device_cb_list = piVar2 + 2;
      }
      return uVar1;
    }
    if ((piVar2[-2] == param_1) && (piVar2[-1] != 0)) break;
    piVar2 = (int *)*piVar2;
  }
  return 0x102;
}

