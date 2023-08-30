/*
 * Last changed at upstream commit c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * https://github.com/espressif/esp-zigbee-sdk/commit/c1113e88ee047f0eb31a91352a6fd0fc5318b6fd
 * Upstream date: 2023-08-30 15:00:29 +0800
 * Upstream subject: esp-zigbee-sdk: release/v0.9.3(6da46788)
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
  puVar2[2] = active_scan_complete_cb;
  *puVar2 = param_1;
  *(undefined1 *)(puVar2 + 1) = param_2;
  zdo_active_scan_user_cb = param_3;
  zb_schedule_app_alarm(&zb_zdo_active_scan_request,uVar1,0);
  return;
}

