/*
 * Last changed at upstream commit 6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * https://github.com/espressif/esp-zigbee-sdk/commit/6fb04b5b77a96f6ce5cb3daff360f54f13d8db16
 * Upstream date: 2023-06-09 17:12:37 +0800
 * Upstream subject: esp-zigbee-sdk: release esp-zigbee-sdk v0.6.2(2626797)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_active_scan_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_active_scan_request(undefined4 param_1,undefined1 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = zb_buf_get_out_func();
  puVar2 = (undefined4 *)zb_buf_get_tail_func(0xc);
  puVar2[2] = active_scan_complete_cb;
  *puVar2 = param_1;
  *(undefined1 *)(puVar2 + 1) = param_2;
  zdo_active_scan_user_cb = param_3;
  zb_schedule_callback(&zb_zdo_active_scan_request,uVar1);
  return;
}

