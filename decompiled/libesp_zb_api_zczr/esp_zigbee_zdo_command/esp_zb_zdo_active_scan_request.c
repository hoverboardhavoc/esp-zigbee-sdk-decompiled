/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zdo_command.o -> esp_zb_zdo_active_scan_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_active_scan_request(undefined4 param_1,undefined1 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = zb_buf_get_out_func();
  puVar2 = (undefined4 *)zb_buf_get_tail_func(0xc);
  *(undefined1 *)(puVar2 + 1) = param_2;
  puVar2[2] = active_scan_complete_cb;
  *puVar2 = param_1;
  zdo_active_scan_user_cb = param_3;
  zb_schedule_app_alarm(&zb_zdo_active_scan_request,uVar1,0,0);
  return;
}

