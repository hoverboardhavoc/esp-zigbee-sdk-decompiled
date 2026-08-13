/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> aps_retrans.o -> aps_tx_window_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void aps_tx_window_init(undefined1 *param_1,uint param_2,uint param_3)

{
  undefined1 *puVar1;
  uint extraout_a1;
  
  if ((param_3 - 1 & 0xff) < 8) {
    *param_1 = (char)param_2;
    param_1[1] = 0;
    param_1[2] = 0;
    if ((int)param_2 < (int)param_3) {
      param_3 = param_2;
    }
    param_1[3] = (char)param_3;
    param_1[4] = -(char)(1 << (param_3 & 0x1f));
    return;
  }
  puVar1 = (undefined1 *)
           __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x46,
                         "aps_tx_window_init","0 < w_sz && w_sz <= 8");
  if ((extraout_a1 - 1 & 0xff) < 8) {
    *puVar1 = 0xff;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = (char)extraout_a1;
    puVar1[4] = -(char)(1 << (extraout_a1 & 0x1f));
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_retrans.c",0x17f,
                "aps_rx_window_init","0 < w_sz && w_sz <= 8");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

