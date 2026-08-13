/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_report_poll_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_report_poll_result(int param_1,int param_2)

{
  undefined2 uStack_14;
  undefined1 uStack_12;
  
  mac_pal_set_rx_when_idle(*(uint *)(param_1 + 0x28) >> 0x11 & 1);
  if (*(char *)(param_1 + 0x2d) == '\x02') {
    if (param_2 != 0) {
      uStack_14 = 0xffff;
      uStack_12 = (char)param_2;
      mac_finish_association(param_1,&uStack_14);
      return;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x358,
                  "mac_report_poll_result","status != 0x00U");
  }
  uStack_14 = CONCAT11(uStack_14._1_1_,(char)param_2);
  nwk_mm_poll_confirm(*(undefined1 *)(param_1 + 0x2c),&uStack_14);
  return;
}

