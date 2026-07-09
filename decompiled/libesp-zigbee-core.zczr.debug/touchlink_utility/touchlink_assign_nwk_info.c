/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_assign_nwk_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void touchlink_assign_nwk_info(void)

{
  char *pcVar1;
  uint uVar2;
  
  pcVar1 = (char *)touchlink_device_info_get();
  if (*pcVar1 != '\0') {
    touchlink_assign_short_addr();
    nwk_set_short_address();
    nwk_secur_set_key(0,0);
  }
  touchlink_assign_pan_id();
  nwk_set_panid();
  uVar2 = touchlink_get_logical_channel();
  nwk_set_pan_channel(1 << (uVar2 & 0x1f) & 0x7ffffff);
  return;
}

