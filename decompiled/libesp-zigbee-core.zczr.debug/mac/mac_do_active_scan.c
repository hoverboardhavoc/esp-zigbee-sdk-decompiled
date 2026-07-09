/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_do_active_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_do_active_scan(int param_1)

{
  int iVar1;
  
  iVar1 = mac_update_scan_channel();
  if (iVar1 == 0) {
    mac_do_transmit(param_1);
  }
  else {
    mac_pal_set_panid(*(undefined2 *)(param_1 + 10));
    mac_pal_set_rx_when_idle(*(uint *)(param_1 + 0x28) >> 0x11 & 1);
    mac_set_state(param_1,0);
    mac_finish_op(param_1);
    mac_report_active_scan_result(param_1,0);
    mac_perform_next_op(param_1);
  }
  return;
}

