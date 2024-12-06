/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_restart_process_rejoin
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zcl_commissioning_restart_process_rejoin(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if (DAT_000117aa == '\x01') {
    bdb_start_top_level_commissioning(4);
  }
  else if (DAT_000117aa == '\x02') {
    uVar1 = zb_buf_get_out_func();
    puVar2 = (undefined1 *)zb_buf_get_tail_func(1);
    *puVar2 = 0;
    zb_schedule_callback(&zdo_commissioning_initiate_rejoin,uVar1);
  }
  else if (DAT_000117aa == '\x03') {
    bdb_start_top_level_commissioning(0);
  }
  esp_zcl_comm_restart_process_finish(param_1);
  return;
}

