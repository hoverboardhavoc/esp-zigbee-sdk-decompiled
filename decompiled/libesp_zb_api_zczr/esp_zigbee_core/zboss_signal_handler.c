/*
 * Last changed at upstream commit 0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * https://github.com/espressif/esp-zigbee-sdk/commit/0de2da5bd0b050dcc5b1f7f4c5eba0b5eeccfd85
 * Upstream date: 2023-07-14 11:30:10 +0800
 * Upstream subject: esp-zigbee-sdk: release v0.7.1(5785a2c)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zboss_signal_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zboss_signal_handler(int param_1)

{
  int iVar1;
  undefined4 *__ptr;
  undefined4 uStack_14;
  
  uStack_14 = 0;
  iVar1 = zb_buf_get_status_func();
  __ptr = (undefined4 *)malloc(8);
  zb_get_app_signal(param_1,&uStack_14);
  *__ptr = uStack_14;
  if (iVar1 != 0) {
    iVar1 = -1;
  }
  __ptr[1] = iVar1;
  esp_zb_app_signal_handler(__ptr);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  free(__ptr);
  return;
}

