/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_data
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_handle_data(int param_1,int param_2)

{
  int iVar1;
  
  if (*(char *)(param_1 + 0x2d) != '\x02') {
    if (((*(char *)(param_1 + 0x2e) == '\x06') && (*(char *)(param_2 + 4) != '\0')) &&
       (iVar1 = mac_frame_is_from_coord(), iVar1 != 0)) {
      mac_stop_timer(param_1);
      mac_finish_op(param_1);
      mac_report_poll_result(param_1,0);
      mac_perform_next_op(param_1);
    }
    nwk_mm_data_indication(*(undefined1 *)(param_1 + 0x2c),param_2);
  }
  return;
}

