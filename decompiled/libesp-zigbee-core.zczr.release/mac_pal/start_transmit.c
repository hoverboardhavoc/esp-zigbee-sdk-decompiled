/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> mac_pal.o -> start_transmit
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
  if (s_mac_pal_ctx.state == '\x03') {
    iVar2 = ezb_plat_radio_receive((s_mac_pal_ctx.tx_frame)->channel);
    if (iVar2 == 0) goto _L0;
    do {
      __assert_func(0,0,0,0);
_L0:
      set_state(MAC_PAL_STATE_TRANSMIT);
      iVar2 = ezb_plat_radio_transmit(peVar1);
    } while (iVar2 != 0);
    return;
  }
  return;
}

