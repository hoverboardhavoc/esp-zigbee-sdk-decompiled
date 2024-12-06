/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> zboss_signal_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zboss_signal_handler(int param_1)

{
  int iVar1;
  undefined4 *local_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 *apuStack_14 [2];
  
  apuStack_14[0] = (undefined4 *)0x0;
  iVar1 = zb_buf_get_status_func();
  uStack_18 = zb_get_app_signal(param_1,apuStack_14);
  local_20 = apuStack_14[0];
  if (apuStack_14[0] == (undefined4 *)0x0) {
    local_20 = &uStack_18;
  }
  if (iVar1 != 0) {
    iVar1 = -1;
  }
  iStack_1c = iVar1;
  esp_zb_app_signal_handler(&local_20);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

