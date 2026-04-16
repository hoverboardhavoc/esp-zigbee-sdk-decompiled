/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> channel_page_get_next_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t channel_page_get_next_channel(channel_page_t channel_page,uint8_t *channel_number)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (uint)*channel_number;
  if (uVar1 == 0xff) {
    if ((uint)channel_page < 0x8000000) {
      uVar1 = 10;
    }
    else {
      uVar1 = 0;
    }
  }
  do {
    uVar2 = uVar1 + 1;
    uVar1 = uVar2 & 0xff;
    if (0x1a < uVar1) {
      return 5;
    }
  } while (((channel_page.u32 & 0x7ffffff) >> (uVar2 & 0x1f) & 1) == 0);
  *channel_number = (uint8_t)uVar2;
  return 0;
}

