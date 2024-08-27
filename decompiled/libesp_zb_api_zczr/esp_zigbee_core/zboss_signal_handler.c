/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zboss_signal_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zboss_signal_handler(int param_1)

{
  int iVar1;
  undefined4 *local_20;
  undefined4 uStack_1c;
  undefined4 *puStack_18;
  int iStack_14;
  
  local_20 = (undefined4 *)0x0;
  iVar1 = zb_buf_get_status_func();
  uStack_1c = zb_get_app_signal(param_1,&local_20);
  puStack_18 = local_20;
  if (local_20 == (undefined4 *)0x0) {
    puStack_18 = &uStack_1c;
  }
  iStack_14 = -(uint)(iVar1 != 0);
  esp_zb_app_signal_handler(&puStack_18);
  if (param_1 != 0) {
    zb_buf_free_func(param_1);
  }
  return;
}

