/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> mac_pal_handle_tx_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void mac_pal_handle_tx_done(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  micro_timer_stop(&s_mac_pal_ctx);
  iVar1 = should_handle_csma_backoff();
  if (((iVar1 == 0) || (param_3 != 0x1e1)) || (*(byte *)(param_1 + 0x11) <= DAT_00010a05)) {
    DAT_00010a05 = '\0';
    iVar1 = should_handle_transmit_retries();
    if (((iVar1 == 0) || (param_3 == 0)) || (*(byte *)(param_1 + 0x10) <= DAT_00010a06)) {
      set_state(2);
      mac_pal_callback_tx_done(param_1,param_2,param_3);
    }
    else {
      DAT_00010a06 = DAT_00010a06 + 1;
      start_csma();
    }
  }
  else {
    DAT_00010a05 = DAT_00010a05 + 1;
    start_csma();
  }
  return;
}

