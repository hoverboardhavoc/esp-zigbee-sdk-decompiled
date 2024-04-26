/*
 * Last changed at upstream commit 438301125bdfa70150622d905094f79315456774
 * https://github.com/espressif/esp-zigbee-sdk/commit/438301125bdfa70150622d905094f79315456774
 * Upstream date: 2024-04-26 19:22:10 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.3.0(a824e1a1)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_commissioning.o -> esp_zcl_commissioning_restart_process_rejoin
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zcl_commissioning_restart_process_rejoin(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  if (DAT_00011792 == '\x01') {
    bdb_start_top_level_commissioning(4);
  }
  else if (DAT_00011792 == '\x02') {
    uVar1 = zb_buf_get_out_func();
    puVar2 = (undefined1 *)zb_buf_get_tail_func(1);
    *puVar2 = 0;
    zb_schedule_callback(&zdo_commissioning_initiate_rejoin,uVar1);
  }
  else if (DAT_00011792 == '\x03') {
    bdb_start_top_level_commissioning(0);
  }
  esp_zcl_comm_restart_process_finish(param_1);
  return;
}

