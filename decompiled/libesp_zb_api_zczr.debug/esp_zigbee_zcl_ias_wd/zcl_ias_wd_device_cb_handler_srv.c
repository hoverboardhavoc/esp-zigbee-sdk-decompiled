/*
 * Last changed at upstream commit 144e7499ed4e1cce68f5de0341b465c0d192496c
 * https://github.com/espressif/esp-zigbee-sdk/commit/144e7499ed4e1cce68f5de0341b465c0d192496c
 * Upstream date: 2024-07-03 12:16:21 +0000
 * Upstream subject: esp-zigbee-lib:(290e291c)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_ias_wd.o -> zcl_ias_wd_device_cb_handler_srv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_ias_wd_device_cb_handler_srv(void)

{
  int *piVar1;
  undefined4 *__ptr;
  undefined4 uVar2;
  
  piVar1 = (int *)zb_buf_get_tail_func(0x38);
  if (*piVar1 == 9) {
    __ptr = (undefined4 *)malloc(0xc);
    *__ptr = 0;
    *(char *)(__ptr + 1) = (char)piVar1[1];
    *(undefined2 *)((int)__ptr + 6) = 0x502;
    __ptr[2] = piVar1 + 3;
    esp_zb_core_action_handler_schedule(0x1d,__ptr);
    uVar2 = esp_err_to_zb_ret();
  }
  else {
    if (*piVar1 != 10) {
      zb_assert(0x10000,0x4d);
      zb_zcl_ias_wd_init_server();
      zb_zcl_device_cb_register(9,zcl_ias_wd_device_cb_handler_srv);
      uVar2 = zb_zcl_device_cb_register(10,zcl_ias_wd_device_cb_handler_srv);
      return uVar2;
    }
    __ptr = (undefined4 *)malloc(0xc);
    *__ptr = 0;
    *(char *)(__ptr + 1) = (char)piVar1[1];
    *(undefined2 *)((int)__ptr + 6) = 0x502;
    __ptr[2] = piVar1 + 3;
    esp_zb_core_action_handler_schedule(0x1e,__ptr);
    uVar2 = esp_err_to_zb_ret();
  }
  free(__ptr);
  return uVar2;
}

