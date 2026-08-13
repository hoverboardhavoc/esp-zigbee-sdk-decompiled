/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_handle_timer
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_handle_timer(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 0x2e);
  if (cVar1 == '\x03') {
    mac_finish_op();
    mac_start_op(param_1,5);
    mac_perform_next_op(param_1);
  }
  else if (cVar1 == '\x06') {
    mac_finish_op();
    mac_report_poll_result(param_1,0xeb);
    mac_perform_next_op(param_1);
  }
  else {
    if (cVar1 != '\x01') {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac.c",0x41f,"mac_handle_timer",
                    &_LC8);
      mac_handle_timer();
      return;
    }
    mac_do_active_scan();
  }
  return;
}

