/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_update_scan_channel
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_update_scan_channel(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = mac_is_enabled();
  if (iVar1 == 0) {
    uVar2 = 8;
  }
  else {
    uVar2 = channel_page_get_next_channel(*(undefined4 *)(param_1 + 0x34),param_1 + 0x32);
  }
  return uVar2;
}

