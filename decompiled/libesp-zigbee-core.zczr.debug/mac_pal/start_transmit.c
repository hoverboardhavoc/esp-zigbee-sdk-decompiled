/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> start_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void start_transmit(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00010a08;
  if (s_mac_pal_ctx != '\x03') {
    return;
  }
  iVar1 = ezb_plat_radio_receive(*(undefined1 *)(DAT_00010a08 + 5));
  if (iVar1 == 0) {
    set_state(4);
    iVar2 = ezb_plat_radio_transmit(iVar2);
    if (iVar2 == 0) {
      return;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0xa1,"start_transmit",
                  "(ezb_plat_radio_transmit(tx_frame)) == 0");
  }
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x9d,
                        "start_transmit","(ezb_plat_radio_receive(tx_frame->channel)) == 0");
  micro_timer_start(&s_mac_pal_ctx,iVar2 << 4);
  return;
}

