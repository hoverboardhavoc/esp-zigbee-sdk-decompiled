/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> start_transmit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void start_transmit(void)

{
  ezb_radio_frame_t *peVar1;
  int iVar2;
  
  peVar1 = s_mac_pal_ctx.tx_frame;
  if (s_mac_pal_ctx.state != '\x03') {
    return;
  }
  iVar2 = ezb_plat_radio_receive((s_mac_pal_ctx.tx_frame)->channel);
  if (iVar2 == 0) {
    set_state(MAC_PAL_STATE_TRANSMIT);
    iVar2 = ezb_plat_radio_transmit(peVar1);
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

