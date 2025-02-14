/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_core.o -> zboss_signal_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zboss_signal_handler(int param_1)

{
  undefined4 uVar1;
  undefined4 *local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 *apuStack_14 [2];
  
  apuStack_14[0] = (undefined4 *)0x0;
  uVar1 = zb_buf_get_status_func();
  uStack_18 = zb_get_app_signal(param_1,apuStack_14);
  local_20 = apuStack_14[0];
  if (apuStack_14[0] == (undefined4 *)0x0) {
    local_20 = &uStack_18;
  }
  uStack_1c = zb_ret_to_esp_err(uVar1);
  esp_zb_app_signal_handler(&local_20);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

