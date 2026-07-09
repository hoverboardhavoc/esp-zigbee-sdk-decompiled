/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
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
  
  iVar2 = DAT_00010918;
  if (s_mac_pal_ctx != '\x03') {
    return;
  }
  iVar1 = ezb_plat_radio_receive(*(undefined1 *)(DAT_00010918 + 5));
  if (iVar1 == 0) {
    set_state(4);
    iVar2 = ezb_plat_radio_transmit(iVar2);
    if (iVar2 == 0) {
      return;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0xa0,"start_transmit",
                  "(ezb_plat_radio_transmit(tx_frame)) == 0");
  }
  iVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/mac/mac_pal.c",0x9c,
                        "start_transmit","(ezb_plat_radio_receive(tx_frame->channel)) == 0");
  micro_timer_start(&s_mac_pal_ctx,iVar2 << 4);
  return;
}

