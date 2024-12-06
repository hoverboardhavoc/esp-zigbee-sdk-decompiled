/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_restart_process_rejoin
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zcl_commissioning_restart_process_rejoin(int param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  uVar1 = 4;
  if ((char)g_comm_ctx != '\x01') {
    if ((char)g_comm_ctx == '\x02') {
      uVar1 = zb_buf_get_out_func();
      puVar2 = (undefined1 *)zb_buf_get_tail_func(1);
      *puVar2 = 0;
      zb_schedule_callback(&zdo_commissioning_initiate_rejoin,uVar1);
      goto _L0;
    }
    if ((char)g_comm_ctx != '\x03') goto _L0;
    uVar1 = 0;
  }
  bdb_start_top_level_commissioning(uVar1);
_L0:
  if (param_1 == 0) {
    return;
  }
  zb_buf_free_func();
  return;
}

