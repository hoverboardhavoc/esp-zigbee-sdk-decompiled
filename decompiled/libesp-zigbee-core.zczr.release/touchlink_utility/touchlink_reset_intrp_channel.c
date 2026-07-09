/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_reset_intrp_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_reset_intrp_channel(void)

{
  int iVar1;
  uint auStack_14 [3];
  
  auStack_14[0] = 0;
  iVar1 = touchlink_channel_is_valid();
  auStack_14[0] = (uint)(iVar1 != 0) | auStack_14[0] & 0xf8000000;
  nwk_mm_set_pib_attr(0,0x62,auStack_14);
  return;
}

