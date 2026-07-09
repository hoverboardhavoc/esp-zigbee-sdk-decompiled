/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_get_intrp_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 touchlink_get_intrp_channel(void)

{
  int iVar1;
  undefined1 uStack_15;
  undefined4 auStack_14 [4];
  
  auStack_14[0] = 0;
  uStack_15 = 0xb;
  iVar1 = nwk_mm_get_pib_attr(0,0x62,auStack_14,4);
  if (iVar1 == 0) {
    channel_page_get_next_channel(auStack_14[0],&uStack_15);
  }
  return uStack_15;
}

