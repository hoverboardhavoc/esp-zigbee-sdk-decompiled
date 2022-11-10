/*
 * Last changed at upstream commit 6f86421a4970072ce8039b9d5be911c385f38303
 * https://github.com/espressif/esp-zigbee-sdk/commit/6f86421a4970072ce8039b9d5be911c385f38303
 * Upstream date: 2022-11-10 11:13:02 +0800
 * Upstream subject: examples: apply new signal handler API function
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
  zb_get_app_signal(param_1,&uStack_14);
  __ptr = (undefined4 *)malloc(8);
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

