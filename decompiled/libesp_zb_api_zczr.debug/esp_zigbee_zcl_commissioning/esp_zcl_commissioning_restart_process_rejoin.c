/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
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

