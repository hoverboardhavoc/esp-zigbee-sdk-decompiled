/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac.o -> mac_report_poll_result.constprop.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_report_poll_result_constprop_0(int param_1,int param_2)

{
  undefined2 uStack_14;
  undefined1 uStack_12;
  
  mac_pal_set_rx_when_idle(*(uint *)(param_1 + 0x28) >> 0x11 & 1);
  if (*(char *)(param_1 + 0x2d) == '\x02') {
    if (param_2 == 0) {
      mac_report_poll_result_part_0();
    }
    uStack_14 = 0xffff;
    uStack_12 = (char)param_2;
    mac_finish_association(param_1,&uStack_14);
  }
  else {
    uStack_14 = CONCAT11(uStack_14._1_1_,(char)param_2);
    nwk_mm_poll_confirm(*(undefined1 *)(param_1 + 0x2c),&uStack_14);
  }
  return;
}

