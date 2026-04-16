/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_get_intrp_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t touchlink_get_intrp_channel(void)

{
  int iVar1;
  uint uVar2;
  uint uStack_14;
  channel_page_t channel_page;
  
  uStack_14 = 0;
  iVar1 = nwk_mm_get_pib_attr(0,0x62,&uStack_14,4);
  if (iVar1 == 0) {
    uVar2 = 0xc;
    do {
      if (((uStack_14 & 0x7ffffff) >> (uVar2 & 0x1f) & 1) != 0) {
        return (uint8_t)uVar2;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 != 0x1b);
  }
  return '\v';
}

