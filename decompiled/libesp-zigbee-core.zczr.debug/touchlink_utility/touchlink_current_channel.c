/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_current_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 touchlink_current_channel(void)

{
  int iVar1;
  undefined1 auStack_11 [13];
  
  auStack_11[0] = 0xb;
  iVar1 = touchlink_is_factory_new();
  if (iVar1 == 0) {
    auStack_11[0] = 0xb;
    nwk_get_pan_channel();
    channel_page_get_next_channel(auStack_11);
  }
  else {
    auStack_11[0] = touchlink_get_logical_channel();
  }
  return auStack_11[0];
}

