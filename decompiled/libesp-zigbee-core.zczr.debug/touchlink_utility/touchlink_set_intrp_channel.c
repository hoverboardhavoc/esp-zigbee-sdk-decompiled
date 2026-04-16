/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_set_intrp_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_set_intrp_channel(uint8_t channel)

{
  _Bool _Var1;
  undefined3 extraout_var;
  ezb_err_t eVar2;
  uint uStack_14;
  channel_page_t channel_page;
  
  uStack_14 = 0;
  _Var1 = touchlink_channel_is_valid(channel);
  if (CONCAT31(extraout_var,_Var1) == 0) {
    uStack_14 = uStack_14 & 0xf8000000;
  }
  else {
    uStack_14 = uStack_14 & 0xf8000000 | 1 << (channel & 0x1f) & 0x7ffffffU;
  }
  eVar2 = nwk_mm_set_pib_attr(0,0x62,&uStack_14);
  return eVar2;
}

