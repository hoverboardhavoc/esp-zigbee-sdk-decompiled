/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk.o -> nwk_set_pan_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

ezb_err_t nwk_set_pan_channel(channel_page_t channel_page)

{
  ezb_err_t eVar1;
  channel_page_t cStack_14;
  channel_page_t channel_page_local;
  
  cStack_14 = channel_page;
  eVar1 = nwk_mm_set_pib_attr(0,0x61,&cStack_14);
  return eVar1;
}

