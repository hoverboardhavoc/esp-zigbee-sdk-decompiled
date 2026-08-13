/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_rx_window_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void aps_rx_window_init(undefined1 *param_1,uint param_2)

{
  if ((param_2 - 1 & 0xff) < 8) {
    *param_1 = 0xff;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = (char)param_2;
    param_1[4] = -(char)(1 << (param_2 & 0x1f));
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x17f,
                "aps_rx_window_init","0 < w_sz && w_sz <= 8");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

