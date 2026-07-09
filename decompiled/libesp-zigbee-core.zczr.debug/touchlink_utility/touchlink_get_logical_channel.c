/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_get_logical_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint touchlink_get_logical_channel(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = touchlink_device_info_get();
  iVar1 = touchlink_channel_is_valid(*(undefined1 *)(iVar1 + 1));
  if (iVar1 == 0) {
    uVar2 = touchlink_assign_random_channel();
  }
  else {
    iVar1 = touchlink_device_info_get();
    uVar2 = (uint)*(byte *)(iVar1 + 1);
  }
  return uVar2;
}

