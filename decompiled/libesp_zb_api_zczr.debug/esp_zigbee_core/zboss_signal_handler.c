/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_core.o -> zboss_signal_handler
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

