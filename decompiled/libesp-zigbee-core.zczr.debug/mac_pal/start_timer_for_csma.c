/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_pal.o -> start_timer_for_csma
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void start_timer_for_csma(uint8_t be)

{
  int iVar1;
  
  iVar1 = random_noncrypto_range_u32(0,1 << (be & 0x1f));
  if ((s_mac_pal_ctx._3_1_ & 1) == 0) {
    ezb_plat_radio_sleep();
  }
  else {
    ezb_plat_radio_receive((s_mac_pal_ctx.tx_frame)->channel);
  }
  start_timer(iVar1 * 0x14);
  return;
}

